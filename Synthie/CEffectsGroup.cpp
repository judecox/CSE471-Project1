#include "pch.h"
#include "CEffectsGroup.h"
#include "CEffectFactory.h"

CEffectsGroup::~CEffectsGroup()
{
	for each (auto * effect in m_effects)
	{
		delete effect;
	}

	m_effects.clear();
}

void CEffectsGroup::XmlLoad(IXMLDOMNode* xml)
{
	CEffectFactory factory(m_channels);
	m_effects = factory.XmlLoadEffects(xml);
}
