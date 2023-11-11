#include "pch.h"
#include "CFlange.h"
#include <cmath>

CFlange::CFlange(int channels, double sampleRate, double samplePeriod) : CEffect(channels, sampleRate, samplePeriod)
{
	m_phase = 0;
	m_frequency = 1;
	m_amplitude = 1;

	Reset();

	m_feedback = 0.5;
	m_wetness = 0.5;
}

CFlange::~CFlange()
{

}

void CFlange::Process(const double* frameIn, double* frameOut, const double& time)
{
	// First calculate the waveform. This will be the waveform of the
	// distortion in samples.
	const double waveform = m_amplitude * sin(m_phase * 2 * PI);
	m_phase += m_frequency * m_samplePeriod;
	const int delay = int(0.01 * m_sampleRate + 0.5);

	for (size_t i = 0; i < m_channels; i++)
	{
		m_frameHistory.push(frameIn[i] * waveform * m_feedback +
			frameIn[i] * (1 - m_feedback));
	}

	for (size_t c = 0; c < m_channels; c++)
	{
		if (delay * m_channels <= m_frameHistory.size())
		{

			frameOut[c] = m_frameHistory.front() * m_wetness + 
				frameIn[c] * (1 - m_wetness);
			m_frameHistory.pop();
		}
		else
		{
			frameOut[c] = frameIn[c];
		}
	}
}

void CFlange::XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value)
{
	// These parameters are based off of 
	// https://blog.native-instruments.com/what-is-a-flanger/
	if (name == L"rate")
	{
		value.ChangeType(VT_R8);
		m_frequency = value.dblVal;
	}
	else if (name == L"amount")
	{
		value.ChangeType(VT_R8);
		m_amplitude = value.dblVal;
	}
	else if (name == L"phase")
	{
		value.ChangeType(VT_R8);
		m_phase = value.dblVal;
	}
	else if (name == L"feedback")
	{
		value.ChangeType(VT_R8);
		m_feedback = value.dblVal;
	}
	else if (name == L"mix" || name == L"wetness")
	{
		value.ChangeType(VT_R8);
		m_wetness = value.dblVal;
	}
}

void CFlange::Reset()
{
	//m_delayIndex = -(int)std::ceil(m_channels * m_sampleRate);
	m_delayIndex = 0;
	m_bufferIndex = 0;
	m_frameHistory = std::queue<double>();
}
