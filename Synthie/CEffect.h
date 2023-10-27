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
	}

	// Processes frameIn, places processed value into frameOut.
	virtual void Process(const double* frameIn, double* frameOut, const double& time) = 0;

	virtual void XmlLoad(IXMLDOMNode* xml) = 0;
};
