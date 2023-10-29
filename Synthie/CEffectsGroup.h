#pragma once
#include "CEffect.h"
#include <vector>

class CEffectsGroup :
    public CEffect
{
    // Member variables
protected:
    std::vector<CEffect*> m_effects;

    // Constructor & Destructor
public:
    CEffectsGroup(int channels, double sampleRate, double samplePeriod) : CEffect(channels, sampleRate, samplePeriod) {}

    ~CEffectsGroup();

    // Methods
public:
    void XmlLoad(IXMLDOMNode* xml) override;
};

