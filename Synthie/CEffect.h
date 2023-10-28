#include "CInstrument.h"
#pragma once
class CEffect
{
protected:
	int m_channels = 2;

public:
	std::wstring m_id;

	CEffect(int channels)
	{
		m_channels = channels;
		m_id = L"";
	}

	// Processes frameIn, places processed value into frameOut.
	virtual void Process(const double* frameIn, double* frameOut, const double& time) = 0;

	virtual void XmlLoadAttribute(const CComBSTR& name, CComVariant& value) = 0;

	void XmlLoad(IXMLDOMNode* xml);
};
