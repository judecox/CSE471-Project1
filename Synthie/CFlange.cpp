#include "pch.h"
#include "CFlange.h"
#include <cmath>

CFlange::CFlange(int channels, double sampleRate, double samplePeriod) : CEffect(channels, sampleRate, samplePeriod)
{
	m_phase = 0;
	m_frequency = 1;
	m_amplitude = 1;

	m_bufferIndex = 0;
	m_bufferSize = std::ceil(m_channels * m_amplitude * m_sampleRate);

	m_frameHistory = std::vector<double>(m_bufferSize);
}

CFlange::~CFlange()
{

}

void CFlange::Process(const double* frameIn, double* frameOut, const double& time)
{
	const int delayed = std::ceil(m_amplitude * sin(m_phase * 2 * PI) * m_sampleRate - m_amplitude);
	m_phase += m_frequency * m_samplePeriod;

	// Use frameHistory as a circular buffer.
	for (int c = 0; c < m_channels; c++)
	{
		m_frameHistory[m_bufferIndex] = frameIn[c];

		int i = std::ceil(std::fmod(m_bufferIndex - delayed, m_bufferSize));

		if (i < 0)
			i += m_bufferSize;

		frameOut[c] = (frameIn[c] + m_frameHistory[i]) / 2.0;

		m_bufferIndex = std::fmod(++m_bufferIndex, m_bufferSize);
	}
}

void CFlange::XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value)
{
	if (name == L"amplitude")
	{
		value.ChangeType(VT_R8);
		m_amplitude = value.dblVal;
	}
	else if (name == L"frequency")
	{
		value.ChangeType(VT_R8);
		m_frequency = value.dblVal;
	}
	else if (name == L"phase")
	{
		value.ChangeType(VT_R8);
		m_phase = value.dblVal;
	}
}
