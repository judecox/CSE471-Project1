#include "pch.h"
#include "Organ.h"
#include "Notes.h"

COrgan::COrgan(void)
{
}

void COrgan::Start()
{
    m_wave.SetSampleRate(GetSampleRate());
    m_wave.Start();
    m_time = 0;

    // Tell the AR object it gets its samples from 
    // the sine wave object.
    m_ar.SetSource(&m_wave);
    m_ar.SetSampleRate(GetSampleRate());
    m_ar.Start();
}


bool COrgan::Generate()
{
    // Tell the component to generate an audio sample
    m_wave.Generate();
    bool valid = m_ar.Generate();

    // Read the component's sample and make it our resulting frame.
    m_frame[0] = m_ar.Frame(0);
    m_frame[1] = m_ar.Frame(1);

    // Update time
    m_time += GetSamplePeriod();

    // We return true until the time reaches the duration.
    return valid;
}

void COrgan::SetNote(CNote* note)
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

        // Get the value of the attribute.  A CComVariant is a variable
        // that can have any type. It loads the attribute value as a
        // string (UNICODE), but we can then change it to an integer 
        // (VT_I4) or double (VT_R8) using the ChangeType function 
        // and then read its integer or double value from a member variable.
        CComVariant value;
        attrib->get_nodeValue(&value);

        if (name == "duration")
        {
            value.ChangeType(VT_R8);
            SetDuration((value.dblVal) * (60.0 / m_bpm));
        }
        else if (name == "note")
        {
            SetFreq(NoteToFrequency(value.bstrVal));
        }
		else if (name == "leslie")
		{
			value.ChangeType(VT_R8);
			m_wave.SetLeslie(value.dblVal);
		}
		else if (name == "vibrato")
		{
			value.ChangeType(VT_R8);
			m_wave.SetVibrato(value.dblVal);
		}
        else if (name == "drawbar")
        {
            m_wave.SetDrawbar(value.bstrVal);
        }
		else if (name == "attack")
		{
			value.ChangeType(VT_R8);
			m_ar.SetAttack(value.dblVal);
		}
		else if (name == "release")
		{
			value.ChangeType(VT_R8);
			m_ar.SetRelease(value.dblVal);
		}
		else if (name == "amplitude")
		{
			value.ChangeType(VT_R8);
			SetAmplitude(value.dblVal);
		}
    }

}