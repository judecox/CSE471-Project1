#include "pch.h"
#include "CChorus.h"
#include <cmath>

CChorus::CChorus(int channels, double sampleRate, double samplePeriod) : CEffect(channels, sampleRate, samplePeriod)
{
	m_frequency = 1;
	m_amplitude = 1;
	m_phase = 0;
	m_balanceOffset = 0;
	m_wetness = 0.5;
	m_delay = 1;

	Reset();
}

void CChorus::Process(const double* frameIn, double* frameOut, const double& time)
{
	// First calculate the waveform. This will be the waveform of the
	// distortion in samples.
	const int delay = int(m_delay * m_sampleRate + 0.5);
	m_phase += m_frequency * m_samplePeriod;

	for (size_t c = 0; c < m_channels; c++)
	{
		// Delayed signal
		const double waveform = m_amplitude * sin((m_phase - c * m_balanceOffset) * 2 * PI);
		m_frameHistory.push(frameIn[c] * waveform);
	}

	// Use frameHistory as a circular buffer.
	for (int c = 0; c < m_channels; c++)
	{
		const double input = frameIn[c];

		// Set output, include wetness.
		if (delay * m_channels <= m_frameHistory.size())
		{
			frameOut[c] = input * (1.0 - m_wetness) + m_frameHistory.front() * m_wetness;
			m_frameHistory.pop();
		}
		else
		{
			frameOut[c] = input;
		}
	}
}

void CChorus::XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value)
{
	// These parameters were optained from 
	// https://www.youtube.com/watch?v=zmN7fK3fKUE
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
	else if (name == L"channelOffset" || name == L"offset")
	{
		value.ChangeType(VT_R8);
		m_balanceOffset = value.dblVal;
	}
	else if (name == L"mix" || name == L"wetness")
	{
		value.ChangeType(VT_R8);
		m_wetness = value.dblVal;
	}
	else if (name == L"delay")
	{
		value.ChangeType(VT_R8);
		m_delay = value.dblVal;
	}
}

void CChorus::Reset()
{
	m_bufferIndex = 0;
	m_frameHistory = std::queue<double>();
}

