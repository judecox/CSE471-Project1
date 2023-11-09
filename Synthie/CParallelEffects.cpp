#include "pch.h"
#include "CParallelEffects.h"

void CParallelEffects::Process(const double* frameIn, double* frameOut, const double& time)
{
	// Instantiate another frame that's a copy of frameIn (so that we can
	// modify it.) Also make sure frameOut is zeroed.
	double* buffer = (double*)calloc(m_channels, sizeof(double));
	std::fill(frameOut, frameOut + m_channels, 0);

	for each (auto effect in m_effects)
	{
		// Process the frame. Make sure to use two different arrays to avoid
		// funny C++ activity.
		effect->Process(frameIn, buffer, time);

		for (int c = 0; c < m_channels; c++)
		{
			frameOut[c] += buffer[c];
			buffer[c] = 0;
		}
	}

	free(buffer);
}

void CParallelEffects::XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value)
{
	// Do nothing lol.
}
