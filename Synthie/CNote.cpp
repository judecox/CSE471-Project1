#include "pch.h"
#include "CNote.h"

CNote::CNote(void)
{
    m_measure = 0;
    m_beat = 0;
}

CNote::~CNote(void)
{
}


bool CNote::operator<(const CNote& b)
{
    if (m_measure < b.m_measure)
        return true;
    if (m_measure > b.m_measure)
        return false;
    if (m_beat < b.m_beat)
        return true;

    return false;
}


void CNote::XmlLoad(IXMLDOMNode* xml,
    std::wstring instrument, double bpm)
{
    // Remember the and the instrument.
    m_instrument = instrument;

    // Get a list of all attribute nodes and the
    // length of that list
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    xml->get_attributes(&attributes);
    long len;
    attributes->get_length(&len);
    double durationModifier = 60.0 / bpm;

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
            m_measure = value.intVal - 1;
        }
        else if (name == "beat")
        {
            // Same thing for the beats.
            value.ChangeType(VT_R8);
            m_beat = value.dblVal - 1;
        }
        else if (name == "duration")
        {
            // Same for duration.
            value.ChangeType(VT_R8);
            m_duration = value.dblVal * durationModifier;
        }
        else if (name == "note")
        {
            m_note = value.bstrVal;
        }
    }
}
