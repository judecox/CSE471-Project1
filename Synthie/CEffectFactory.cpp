#include "pch.h"
#include "CEffectFactory.h"
#include "CSerialEffects.h"
#include "CParallelEffects.h"
#include "CNoiseGate.h"
#include "CCompressor.h"
#include "CFlange.h"
#include "CChorus.h"
#include "xmlhelp.h"

CEffectFactory::CEffectFactory(int channels, double sampleRate, double samplePeriod)
{
	m_channels = channels;
	m_samplePeriod = samplePeriod;
	m_sampleRate = sampleRate;
}

std::vector<std::shared_ptr<CEffect>> CEffectFactory::XmlLoadEffects(IXMLDOMNode* xml)
{
	std::vector<std::shared_ptr<CEffect>> effects = std::vector<std::shared_ptr<CEffect>>();

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
			std::shared_ptr<CSerialEffects> sEffs = std::make_shared<CSerialEffects>(m_channels, m_sampleRate, m_samplePeriod);
			sEffs->XmlLoad(node);

			effects.push_back(sEffs);
		}
		else if (nodeName == L"parallel")
		{
			std::shared_ptr<CParallelEffects> pEffs = std::make_shared<CParallelEffects>(m_channels, m_sampleRate, m_samplePeriod);
			pEffs->XmlLoad(node);

			effects.push_back(pEffs);
		}
		else if (nodeName == L"gate")
		{
			std::shared_ptr<CNoiseGate> gate = std::make_shared<CNoiseGate>(m_channels, m_sampleRate, m_samplePeriod);
			gate->XmlLoad(node);

			effects.push_back(gate);
		}
		else if (nodeName == L"compress")
		{
			std::shared_ptr<CCompressor> compress = std::make_shared<CCompressor>(m_channels, m_sampleRate, m_samplePeriod);
			compress->XmlLoad(node);

			effects.push_back(compress);
		}
		else if (nodeName == L"flange")
		{
			std::shared_ptr<CFlange> flange = std::make_shared<CFlange>(m_channels, m_sampleRate, m_samplePeriod);
			flange->XmlLoad(node);

			effects.push_back(flange);
		}
		else if (nodeName == L"chorus" || nodeName == L"choir")
		{
			std::shared_ptr<CChorus> choir = std::make_shared<CChorus>(m_channels, m_sampleRate, m_samplePeriod);
			choir->XmlLoad(node);

			effects.push_back(choir);
		}
	}

	return effects;
}
