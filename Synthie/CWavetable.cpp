#include "pch.h"
#include "CWavetable.h"
#include "Notes.h"

CWavetable::CWavetable()
{
    m_duration = 0.1;
}

void CWavetable::Start()
{
    m_waveform.SetSampleRate(GetSampleRate());
    m_waveform.Start();
    m_time = 0;

    // Tell the AR object it gets its samples from 
    // the sine wave object.
    m_ar.SetSource(&m_waveform);
    m_ar.SetSampleRate(GetSampleRate());

    // Chnage the AR object's parameters
    m_ar.SetAttack(0.01);
    m_ar.SetRelease(0.03);
    
    // Start the AR object
    m_ar.Start();
}

bool CWavetable::Generate()
{
    // Tell the component to generate an audio sample
    m_waveform.Generate();
    bool valid = m_ar.Generate();

    // Read the component's sample and make it our resulting frame.
    m_frame[0] = m_ar.Frame(0);
    m_frame[1] = m_ar.Frame(1);

    // Update time
    m_time += GetSamplePeriod();

    // Loop waveform if duration is not yet reached
    /*
    if ((m_time < (m_duration - m_ar.Release())) &&
        (m_waveform.Time() >= (m_ar.Duration() - m_ar.Release())))
    {
        m_waveform.SetTime(m_ar.Attack());
    }
    */

    // We return true until the time reaches the duration.
    return valid;
}

void CWavetable::SetNote(CNote* note)
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

    }
}
