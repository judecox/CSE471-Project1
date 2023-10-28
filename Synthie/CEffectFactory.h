#pragma once
#include <vector>
#include "CEffect.h"
class CEffectFactory
{
	// Constructors & Methods
public:
	CEffectFactory() = delete;

	CEffectFactory(int channels);

	std::vector<CEffect*> XmlLoadEffects(IXMLDOMNode* xml);

private:
	int m_channels;
};

