#include <string>

#pragma once
class CEffect
{
protected:
	int m_channels = 2;
	double m_sampleRate;
	double m_samplePeriod;

public:
	std::wstring m_id;
	double m_gain = 1;

	CEffect(int channels, double sampleRate, double samplePeriod);

	// Processes frameIn, places processed value into frameOut.
	virtual void Process(const double* frameIn, double* frameOut, const double& time) = 0;

	virtual void Reset() {  }

	virtual void XmlLoad(IXMLDOMNode* xml);

	// Member methods
protected:
	virtual void XmlLoadAttribute(const CComBSTR& name, CComVariant& value) = 0;
};
