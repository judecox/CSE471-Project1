#include "pch.h"
#include "CEffectsGroup.h"
#include "CEffectFactory.h"

CEffectsGroup::~CEffectsGroup()
{
	m_effects.clear();
}

void CEffectsGroup::XmlLoad(IXMLDOMNode* xml)
{
	CEffect::XmlLoad(xml);

	CEffectFactory factory(m_channels, m_sampleRate, m_samplePeriod);
	m_effects = factory.XmlLoadEffects(xml);
}
