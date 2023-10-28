#pragma once
#include "CEffect.h"
#include <vector>
class CFlange :
	public CEffect
{
	// Member variables
private:
	double m_amplitude;
	double m_frequency;
	double m_phase;
	double m_feedback;
	double m_wetness;

	std::vector<double> m_frameHistory;
	int m_bufferIndex;
	int m_bufferSize;

	// Contructors
public:
	CFlange(int channels, double sampelRate, double samplePeriod);

	~CFlange();

	// Public methods
public:
	// Inherited via CEffect
	virtual void Process(const double* frameIn, double* frameOut, const double& time);
	virtual void XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value);
};

