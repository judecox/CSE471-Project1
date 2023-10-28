#include "pch.h"
#include "CChorusEffect.h"
#include <cmath>

CChorusEffect::CChorusEffect(int channels, double sampleRate, double samplePeriod) : CEffect(channels, sampleRate, samplePeriod)
{
	m_phase = 0;
	m_frequency = 1;
	m_amplitude = 1;

	m_bufferIndex = 0;
	m_bufferSize = std::ceil(m_channels * m_amplitude * m_sampleRate);

	m_wetness = 0.5;

	m_frameHistory = std::vector<double>(m_bufferSize);
}

void CChorusEffect::Process(const double* frameIn, double* frameOut, const double& time)
{
}

void CChorusEffect::XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value)
{
}
