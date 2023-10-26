#include "pch.h"
#include "CNoiseGate.h"

void CNoiseGate::ChannelsSet()
{
	m_stages = std::vector<Stage>(m_channels);
	m_times = std::vector<double>(m_channels);
}

void CNoiseGate::LoadXML(IXMLDOMNode* xml)
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


		if (name == L"threshold")
		{
			value.ChangeType(VT_R8);
			m_threshold = value.dblVal;
		}
		else if (name == L"attack")
		{
			value.ChangeType(VT_R8);
			m_attack = value.dblVal;
		}
		else if (name == L"hold")
		{
			value.ChangeType(VT_R8);
			m_hold = value.dblVal;
		}
		else if (name == L"release")
		{
			value.ChangeType(VT_R8);
			m_release = value.dblVal;
		}
	}
}

// Implements a attack, hold, release noise gate.
// Source: https://en.wikipedia.org/w/index.php?title=Noise_gate&oldid=1180959855#Controls_and_parameters
void CNoiseGate::Process(const double* frameIn, double* frameOut, const double& time)
{
	for (int i = 0; i < m_channels; i++)
	{
		switch (m_stages[i])
		{
		case Closed:
		{
			frameOut[i] = 0;
			if (frameIn[i] >= m_threshold)
			{
				// Move into attack. Use m_times to keep track of when
				// we entered a stage.
				m_stages[i] = Attack;
				m_times[i] = time;
			}
			break;
		}
		case Attack:
		{
			const double fAtk = (time - m_times[i]) / m_attack;
			frameOut[i] = fAtk * frameIn[i];

			if (fAtk >= 1)
			{
				m_stages[i] = Open;
			}
			break;
		}
		case Open:
		{
			frameOut[i] = frameIn[i];
			if (frameIn[i] < m_threshold)
			{
				m_stages[i] = Hold;
				m_times[i] = time;
			}
			break;
		}
		case Hold:
		{
			frameOut[i] = frameIn[i];

			if (time - m_times[i] >= m_hold)
			{
				m_stages[i] = Release;
				m_times[i] = time;
			}
		}
		case Release:
		{
			const double fRls = (time - m_times[i]) / m_release;
			frameOut[i] = frameIn[i] * (1 - fRls);

			if (fRls >= 1)
			{
				m_stages[i] = Closed;
			}
			break;
		}
		}
	}
}