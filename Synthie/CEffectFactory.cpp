#include "pch.h"
#include "CEffectFactory.h"
#include "CSerialEffects.h"
#include "CParallelEffects.h"
#include "CNoiseGate.h"
#include "CCompressor.h"
#include "CFlange.h"
#include "xmlhelp.h"

CEffectFactory::CEffectFactory(int channels, double sampleRate, double samplePeriod)
{
	m_channels = channels;
	m_samplePeriod = samplePeriod;
	m_sampleRate = sampleRate;
}

std::vector<CEffect*> CEffectFactory::XmlLoadEffects(IXMLDOMNode* xml)
{
	std::vector<CEffect*> effects = std::vector<CEffect*>();

	// Drop into child.
	CComPtr<IXMLDOMNode> node;
	xml->get_firstChild(&node);
	for (; node != NULL; NextNode(node))
	{
		// Get name of node and create effect from the name.

		// Get a list of all attribute nodes and the
		// length of that list
		CComPtr<IXMLDOMNamedNodeMap> attributes;
		node->get_attributes(&attributes);
		long len;
		attributes->get_length(&len);

		// Get the name of the node
		CComBSTR nodeName;
		node->get_nodeName(&nodeName);

		if (nodeName == L"serial")
		{
			CSerialEffects* sEffs = new CSerialEffects(m_channels, m_sampleRate, m_samplePeriod);
			sEffs->XmlLoad(node);

			effects.push_back(sEffs);
		}
		else if (nodeName == L"parallel")
		{
			CParallelEffects* pEffs = new CParallelEffects(m_channels, m_sampleRate, m_samplePeriod);
			pEffs->XmlLoad(node);

			effects.push_back(pEffs);
		}
		else if (nodeName == L"gate")
		{
			CNoiseGate* gate = new CNoiseGate(m_channels, m_sampleRate, m_samplePeriod);
			gate->XmlLoad(node);

			effects.push_back(gate);
		}
		else if (nodeName == L"compress")
		{
			CCompressor* compress = new CCompressor(m_channels, m_sampleRate, m_samplePeriod);
			compress->XmlLoad(node);

			effects.push_back(compress);
		}
		else if (nodeName == L"flange")
		{
			CFlange* flange = new CFlange(m_channels, m_sampleRate, m_samplePeriod);
			flange->XmlLoad(node);

			effects.push_back(flange);
		}
	}

	return effects;
}
