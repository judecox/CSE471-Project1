#include "pch.h"
#include "CSynthesizer.h"

#include <algorithm>
#include <memory>

#include "CToneInstrument.h"
#include "CEffectFactory.h"
#include "CPiano.h"
#include "xmlhelp.h"
#include "CNoiseGate.h"
#include "CCompressor.h"
#include "CWavetable.h"

using namespace std;

CSynthesizer::CSynthesizer()
{
	CoInitialize(NULL);

	m_channels = 2;
	m_sampleRate = 44100.;
	m_samplePeriod = 1 / m_sampleRate;
	m_time = 0;

	m_bpm = 120;
	m_secperbeat = 0.5;
	m_beatspermeasure = 4;

	m_effects = std::vector<CEffect*>();
}

CSynthesizer::~CSynthesizer()
{
	for each (auto * effect in m_effects)
	{
		delete effect;
	}

	for each (auto * instrument in m_instruments)
	{
		delete instrument;
	}

	for each (auto* note in m_notes)
	{
		delete note;
	}

	m_effects.clear();
	m_instruments.clear();
	m_notes.clear();
	m_effectCatalog.clear();
}

//! Start the synthesizer
void CSynthesizer::Start(void)
{
	m_instruments.clear();
	m_currentNote = 0;
	m_measure = 0;
	m_beat = 0;
	m_time = 0;
	m_recorded.Start();

	//LoadRecordedSound(m_recorded);
}

//! Generate one audio frame
bool CSynthesizer::Generate(double* frame)
{
	//
	// Phase 1: Determine if any notes need to be played.
	//

	while (m_currentNote < (int)m_notes.size())
	{
		// Get a pointer to the current note
		CNote note = *m_notes.at(m_currentNote);

		// If the measure is in the future we can't play
		// this note just yet.
		if (note.Measure() > m_measure)
			break;

		// If this is the current measure, but the
		// beat has not been reached, we can't play
		// this note.
		if (note.Measure() == m_measure && note.Beat() > m_beat)
			break;

		//
		// Play the note!
		//

		// Create the instrument object based on the specified "instrument" tag

		const std::wstring& instrName = note.Instrument();
		CInstrument* instrument = nullptr;
		if (instrName == L"ToneInstrument")
		{
			instrument = new CToneInstrument();
		}
		else if (instrName == L"piano")
		{
			instrument = new CPiano();
		}
		else if (instrName == L"recorded")
		{
			// instrument = new prerecorded synth.
		}
		else if (instrName == L"organ")
		{
			// instrument = new organ.
		}
		else if (instrName == L"wavetable")
		{
			instrument = new CWavetable;
		}

		if (instrument != nullptr)
		{
			// Configure the instrument object
			instrument->SetSampleRate(GetSampleRate(), m_bpm);
			instrument->SetNote(&note);
			instrument->Start();

			const std::wstring effectID = note.EffectID();
			if (effectID.length() > 0)
			{
				// Add effect sends.
				instrument->m_effect = m_effectCatalog[effectID];
			}

			m_instruments.push_back(instrument);
		}

		m_currentNote++;
	}

	//
	// Phase 2: Clear all channels to silence 
	//

	for (int c = 0; c < GetNumChannels(); c++)
	{
		frame[c] = 0;
	}

	//
	// Phase 3: Play an active instruments
	//

	//
	// We have a list of active (playing) instruments.  We iterate over 
	// that list.  For each instrument we call generate, then add the
	// output to our output frame.  If an instrument is done (Generate()
	// returns false), we remove it from the list.
	//

	for (list<CInstrument*>::iterator node = m_instruments.begin(); node != m_instruments.end(); )
	{
		// Since we may be removing an item from the list, we need to know in 
		// advance, what is after it in the list.  We keep that node as "next"
		list<CInstrument*>::iterator next = node;
		next++;

		// Get a pointer to the allocated instrument
		CInstrument* instrument = *node;

		// Call the generate function
		if (instrument->Generate())
		{
			// If we returned true, we have a valid sample.  Add it 
			// to the frame.
			for (int c = 0; c < GetNumChannels(); c++)
			{
				frame[c] += instrument->Frame(c);
			}

			// Do effects.
			if (instrument->m_effect != nullptr)
			{
				double* frameout = (double*)calloc(m_channels, sizeof(double));
				instrument->m_effect->Process(frame, frameout, m_time);

				std::copy(frameout, frameout + m_channels, frame);
				free(frameout);
			}
		}
		else
		{
			// If we returned false, the instrument is done.
			// Remove it from the list and delete it from memory.
			m_instruments.erase(node);
			delete instrument;
		}

		// Move to the next instrument in the list
		node = next;
	}

	//
	// Phase 3.1: Applying Recording-Specific Effects
	//
	if (m_recorded_effects.size() > 0 && m_time >= m_recorded_effect_timestamps[0] && m_recorded_effects[0] != -1)
	{
		switch (m_recorded_effects[0])
		{
		case 0: //Set Amplitude
			m_recorded.SetAmplitude(m_recorded_effect_parameters[0]);
			break;
		case 1: //Set Fuzz
			m_recorded.SetFuzz(m_recorded_effect_parameters[0]);
			break;
		case 2: //Enable/Disable Reson (Value of 0.0 is disable, anything else is enable)
			m_recorded.SetResonEnabled(m_recorded_effect_parameters[0]);
			break;
		case 3: //Set Reson Frequency
			m_recorded.SetResonFrequency(m_recorded_effect_parameters[0]);
			break;
		case 4: //Set Reson Band
			m_recorded.SetResonBand(m_recorded_effect_parameters[0]);
			break;
		default:
			break;
		}

		//Clearing the first item in all vectors to prepare for the next one
		m_recorded_effects.erase(m_recorded_effects.begin());
		m_recorded_effect_timestamps.erase(m_recorded_effect_timestamps.begin());
		m_recorded_effect_parameters.erase(m_recorded_effect_parameters.begin());
	}

	// Phase 3.2: Play Recorded Performance
	if (m_time >= m_recorded_start_time && m_recorded.Generate())
	{
		// If we returned true, we have a valid sample.  Add it 
		// to the frame.
		for (int c = 0; c < GetNumChannels(); c++)
		{
			double test = m_recorded.FrameValue(c);
			if (test != 0)
			{
				test = test;
			}
			frame[c] += m_recorded.FrameValue(c);
		}
	}

	//
	// Phase 3.5: Overlay Effects
	//
	//double* frameout = (double*)calloc(m_channels, sizeof(double));
	//for each (CEffect* effect in m_effects)
	//{
	//	// Process the frame. Make sure to use two different arrays to avoid
	//	// funny C++ activity.
	//	effect->Process(frame, frameout, m_time);
	//	
	//	for (int c = 0; c < m_channels; c++)
	//	{
	//		frame[c] = frameout[c];
	//	}
	//}
	//free(frameout);
	

	//
	// Phase 4: Advance the time and beats
	//

	// Time advances by the sample period
	m_time += GetSamplePeriod();

	// Beat advances by the sample period divided by the 
	// number of seconds per beat.  The inverse of seconds
	// per beat is beats per second.
	m_beat += GetSamplePeriod() / m_secperbeat;

	// When the measure is complete, we move to
	// a new measure.  We might be a fraction into
	// the new measure, so we subtract out rather 
	// than just setting to zero.
	if (m_beat > m_beatspermeasure)
	{
		m_beat -= m_beatspermeasure;
		m_measure++;
	}

	//
	// Phase 5: Determine when we are done
	//

	// We are done when there is nothing to play.  We'll put something more 
	// complex here later.
	return !m_instruments.empty() || m_currentNote < (int)m_notes.size();
}

void CSynthesizer::Clear(void)
{
	for each (CEffect * effect in m_effects)
	{
		delete effect;
	}

	for each (CInstrument * instrument in m_instruments)
	{
		delete instrument;
	}

	for each (CNote * note in m_notes)
	{
		delete note;
	}

	m_effects.clear();
	m_instruments.clear();
	m_notes.clear();
}


void CSynthesizer::OpenScore(CString& filename)
{
	Clear();

	//
	// Create an XML document
	//

	CComPtr<IXMLDOMDocument>  pXMLDoc;
	bool succeeded = SUCCEEDED(CoCreateInstance(CLSID_DOMDocument, NULL, CLSCTX_INPROC_SERVER,
		IID_IXMLDOMDocument, (void**)&pXMLDoc));
	if (!succeeded)
	{
		AfxMessageBox(L"Failed to create an XML document to use");
		return;
	}

	// Open the XML document
	VARIANT_BOOL ok;
	succeeded = SUCCEEDED(pXMLDoc->load(CComVariant(filename), &ok));
	if (!succeeded || ok == VARIANT_FALSE)
	{
		AfxMessageBox(L"Failed to open XML score file");
		return;
	}

	//
	// Traverse the XML document in memory!!!!
	// Top level tag is <score>
	//

	CComPtr<IXMLDOMNode> node;
	pXMLDoc->get_firstChild(&node);
	for (; node != NULL; NextNode(node))
	{
		// Get the name of the node
		CComBSTR nodeName;
		node->get_nodeName(&nodeName);

		if (nodeName == "score")
		{
			XmlLoadScore(node);
		}
	}

	// Sort the notes.
	sort(m_notes.begin(), m_notes.end(), [](CNote* n1, CNote* n2)
		{
			return n1->operator<(*n2);
		});
}

void CSynthesizer::XmlLoadScore(IXMLDOMNode* xml)
{
	// Get a list of all attribute nodes and the
	// length of that list
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	xml->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);

	// Loop over the list of attributes
	for (int i = 0; i < len; i++)
	{
		// Get attribute i
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);

		// Get the name of the attribute
		CComBSTR name;
		attrib->get_nodeName(&name);

		// Get the value of the attribute.  A CComVariant is a variable
		// that can have any type. It loads the attribute value as a
		// string (UNICODE), but we can then change it to an integer 
		// (VT_I4) or double (VT_R8) using the ChangeType function 
		// and then read its integer or double value from a member variable.
		CComVariant value;
		attrib->get_nodeValue(&value);

		if (name == L"bpm")
		{
			value.ChangeType(VT_R8);
			m_bpm = value.dblVal;
			m_secperbeat = 1 / (m_bpm / 60);
		}
		else if (name == L"beatspermeasure")
		{
			value.ChangeType(VT_I4);
			m_beatspermeasure = value.intVal;
		}

	}


	CComPtr<IXMLDOMNode> node;
	xml->get_firstChild(&node);
	for (; node != NULL; NextNode(node))
	{
		// Get the name of the node
		CComBSTR name;
		node->get_nodeName(&name);

		if (name == L"instrument")
		{
			XmlLoadInstrument(node);
		}
		else if (name == "effects")
		{
			XmlLoadEffectList(node);
		}
		else if (name == "recording")
		{
			XmlLoadRecording(node);
		}
	}
}

void CSynthesizer::XmlLoadInstrument(IXMLDOMNode* xml)
{
	wstring instrument = L"";

	// Get a list of all attribute nodes and the
	// length of that list
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	xml->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);

	// Loop over the list of attributes
	for (int i = 0; i < len; i++)
	{
		// Get attribute i
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);

		// Get the name of the attribute
		CComBSTR name;
		attrib->get_nodeName(&name);

		// Get the value of the attribute.  
		CComVariant value;
		attrib->get_nodeValue(&value);

		if (name == "instrument")
		{
			instrument = value.bstrVal;
		}
	}


	CComPtr<IXMLDOMNode> node;
	xml->get_firstChild(&node);
	for (; node != NULL; NextNode(node))
	{
		// Get the name of the node
		CComBSTR name;
		node->get_nodeName(&name);

		if (name == L"note")
		{
			XmlLoadNote(node, instrument);
		}
	}
}

void CSynthesizer::XmlLoadEffectList(IXMLDOMNode* xml)
{
	CEffectFactory effFactory(m_channels, m_sampleRate, m_samplePeriod);
	auto effects = effFactory.XmlLoadEffects(xml);
	
	for each (auto* eff in effects)
	{
		AddEffect(eff);
	}
}

void CSynthesizer::XmlLoadRecording(IXMLDOMNode* xml)
{
	wstring instrument = L"";

	// Get a list of all attribute nodes and the
	// length of that list
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	xml->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);

	// Loop over the list of attributes
	for (int i = 0; i < len; i++)
	{
		// Get attribute i
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);

		// Get the name of the attribute
		CComBSTR name;
		attrib->get_nodeName(&name);

		// Get the value of the attribute.  
		CComVariant value;
		attrib->get_nodeValue(&value);
		
		if (name == L"filename")
		{
			LoadRecordedSound(m_recorded, value.bstrVal);
		}
		else if (name == "measure")
		{
			// The file has measures that start at 1.  
			// We'll make them start at zero instead.
			value.ChangeType(VT_I4);
			m_recorded_start_time += (value.intVal - 1) * (m_bpm / 60.0) * m_beatspermeasure;
		}
		else if (name == "beat")
		{
			// Same thing for the beats.
			value.ChangeType(VT_R8);
			m_recorded_start_time += (value.dblVal - 1) * (m_bpm / 60.0);
		}
	}

	CComPtr<IXMLDOMNode> node;
	xml->get_firstChild(&node);
	for (; node != NULL; NextNode(node))
	{
		// Get the name of the node
		CComBSTR name;
		node->get_nodeName(&name);

		if (name == L"effectrecorded")
		{
			XmlLoadRecordedEffect(node);
		}
	}
}

void CSynthesizer::XmlLoadRecordedEffect(IXMLDOMNode* xml)
{
	// Get a list of all attribute nodes and the
	// length of that list
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	xml->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);

	int recording_effect_type = -1;
	double recording_effect_time = 0.0;
	double recording_effect_parameter = -1.0;

	// Loop over the list of attributes
	for (int i = 0; i < len; i++)
	{
		// Get attribute i
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);

		// Get the name of the attribute
		CComBSTR name;
		attrib->get_nodeName(&name);

		// Get the value of the attribute.  
		CComVariant value;
		attrib->get_nodeValue(&value);

		if (name == "measure")
		{
			// The file has measures that start at 1.  
			// We'll make them start at zero instead.
			value.ChangeType(VT_I4);
			recording_effect_time += (value.intVal - 1) * (m_bpm / 60.0) * m_beatspermeasure;
		}
		else if (name == "beat")
		{
			// Same thing for the beats.
			value.ChangeType(VT_R8);
			recording_effect_time += (value.intVal - 1) * (m_bpm / 60.0);
		}
		else if (name == "effect")
		{
			value.ChangeType(VT_I4);
			recording_effect_type = value.intVal;
		}
		else if (name == "parameter")
		{
			value.ChangeType(VT_R8);
			recording_effect_parameter = value.dblVal;
		}

	}

	m_recorded_effect_timestamps.push_back(recording_effect_time);
	m_recorded_effects.push_back(recording_effect_type);
	m_recorded_effect_parameters.push_back(recording_effect_parameter);
}

void CSynthesizer::AddEffect(CEffect* effect)
{
	m_effects.push_back(effect);
	m_effectCatalog[effect->m_id] = effect;
}

void CSynthesizer::XmlLoadNote(IXMLDOMNode* xml, std::wstring& instrument)
{
	CNote* note = new CNote();
	note->XmlLoad(xml, instrument);
	m_notes.push_back(note);
}

bool CSynthesizer::LoadRecordedSound(CRecordedAudio &source)
{
	static WCHAR BASED_CODE szFilter[] = L"Wave Files (*.wav)|*.wav|All Files (*.*)|*.*||";

	CFileDialog dlg(TRUE, L".wav", NULL, 0, szFilter, NULL);
	if (dlg.DoModal() != IDOK)
		return false;

	if (!source.m_wavein.Open(dlg.GetPathName()))
		return FALSE;

	m_sampleRate = source.m_wavein.SampleRate();
	m_channels = source.m_wavein.NumChannels();

	return TRUE;
}

bool CSynthesizer::LoadRecordedSound(CRecordedAudio& source, CString path)
{
	if (!source.m_wavein.Open(path))
		return FALSE;

	m_sampleRate = source.m_wavein.SampleRate();
	m_channels = source.m_wavein.NumChannels();

	return TRUE;
}