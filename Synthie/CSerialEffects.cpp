#include "pch.h"
#include "CSerialEffects.h"
#include "xmlhelp.h"
#include "CEffectFactory.h"

void CSerialEffects::Process(const double* frameIn, double* frameOut, const double& time)
{
	// Instantiate another frame that's a copy of frameIn (so that we can
	// modify it.)
	double* buffer = (double*)calloc(m_channels, sizeof(double));
	std::copy(frameIn, frameIn + m_channels, buffer);
	
	for each (CEffect * effect in m_effects)
	{
		// Process the frame. Make sure to use two different arrays to avoid
		// funny C++ activity.
		effect->Process(buffer, frameOut, time);
		std::copy(frameOut, frameOut + m_channels, buffer);

		for (int c = 0; c < m_channels; c++)
		{
			buffer[c] = frameOut[c];
		}
	}

	std::copy(buffer, buffer + m_channels, frameOut);
	free(buffer);
}

void CSerialEffects::XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value)
{
	// Do nothing lol.
}
