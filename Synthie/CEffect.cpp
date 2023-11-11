#include "pch.h"
#include "CEffect.h"

CEffect::CEffect(int channels, double sampleRate, double samplePeriod)
{
	m_channels = channels;
	m_sampleRate = sampleRate;
	m_samplePeriod = samplePeriod;
	m_id = L"";
	m_gain = 1;
}

void CEffect::XmlLoad(IXMLDOMNode* xml)
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

		if (name == L"id")
		{
			// Every effect would have an id.
			m_id = value.bstrVal;
		}
		else if (name == "gain")
		{
			value.ChangeType(VT_R8);
			m_gain = value.dblVal;
		}
		else
		{
			// Other attributes are passed to inherited.
			XmlLoadAttribute(name, value);
		}
	}
}
