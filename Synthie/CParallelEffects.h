#pragma once
#include "CEffectsGroup.h"
class CParallelEffects :
	public CEffectsGroup
{
	// Contructor & Destructor
public:
	CParallelEffects(int channels) : CEffectsGroup(channels) {}

	// Public methods
public:
	// Inherited via CEffect
	void Process(const double* frameIn, double* frameOut, const double& time) override;

	// Member methods
protected:
	void XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value) override;
};

