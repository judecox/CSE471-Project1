#include "pch.h"
#include "CPianoBuild.h"
#include <string> 
using namespace std;

CPianoBuild::CPianoBuild()
{
	m_duration = 1.0;
	m_volume = 2.5;
	m_pedal = false;
	m_playPedalDown = false;
	m_playPedalUp = false;
	m_advancedDynamic = false;
}

CPiano* CPianoBuild::CreatePiano()
{
	CPiano* instrument = new CPiano();

	instrument->SetDuration(m_duration);
	instrument->SetPedal(m_pedal);
	instrument->SetVolume(m_volume);

	if (m_playPedalDown) {
		instrument->PlayPedalDown();
		m_playPedalDown = false;
	}
	if (m_playPedalUp) {
		instrument->PlayPedalUp();
		m_playPedalUp = false;
	}

	return instrument;
}

void CPianoBuild::SetNote(CNote* note)
{
	// Get a list of all attribute nodes and the
	// length of that list
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	note->Node()->get_attributes(&attributes);
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

		CComVariant value;
		attrib->get_nodeValue(&value);

		if (name == "duration")
		{
			value.ChangeType(VT_R8);
			m_duration = value.dblVal;
		}
		else if (name == "pedal")
		{
			value.ChangeType(VT_BSTR);
			char pedal[100];
			wcstombs(pedal, value.bstrVal, 100);
			string pedal_str(pedal);

			if (pedal_str == "pressed") {
				m_playPedalDown = true;
				m_pedal = true;
			}
			if (pedal_str == "released") {
				m_playPedalUp = true;
				m_pedal = false;
			}
		}
		else if (name == "keydynamic")
		{
			value.ChangeType(VT_R8);
			m_volume = value.dblVal;
		}
	}
}
