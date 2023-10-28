#pragma once
#include <vector>
#include "CEffect.h"
class CEffectFactory
{
	// Constructors & Methods
public:
	CEffectFactory() = delete;

	CEffectFactory(int channels, double sampleRate, double samplePeriod);

	std::vector<CEffect*> XmlLoadEffects(IXMLDOMNode* xml);

private:
	int m_channels;
	double m_sampleRate;
	double m_samplePeriod;
};

