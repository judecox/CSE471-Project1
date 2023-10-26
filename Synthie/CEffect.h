#include "CInstrument.h"
#pragma once
class CEffect
{
protected:
	int m_channels = 2;

public:
	CEffect(int channels)
	{
		m_channels = channels;
		ChannelsSet();
	}

	// Processes frameIn, places processed value into frameOut.
	virtual void Process(const double* frameIn, double* frameOut, const double& time) = 0;

private:
	// Called immediatly after the number of channels is known.
	virtual void ChannelsSet() { }
};
