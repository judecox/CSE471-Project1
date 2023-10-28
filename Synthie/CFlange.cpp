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

	m_feedback = 0.5;
	m_wetness = 0.5;

	m_frameHistory = std::vector<double>(m_bufferSize);
}

CFlange::~CFlange()
{

}

void CFlange::Process(const double* frameIn, double* frameOut, const double& time)
{
	// Calculate the delay due to rate and amount.
	const int delayed = std::ceil(m_amplitude * sin(m_phase * 2 * PI) * m_sampleRate - m_amplitude);
	m_phase += m_frequency * m_samplePeriod;

	// Use frameHistory as a circular buffer.
	for (int c = 0; c < m_channels; c++)
	{
		const double input = frameIn[c];
		double output = frameOut[c];

		int i = std::ceil(std::fmod(m_bufferIndex - delayed, m_bufferSize));

		if (i < 0)
			i += m_bufferSize;

		// Set output, include wetness.
		output = input * (1.0 - m_wetness);
		output += m_frameHistory[i] * m_wetness;


		// Feedback
		m_frameHistory[m_bufferIndex] = output * m_feedback + 
			frameIn[c] * (1 - m_feedback);

		// Next index
		m_bufferIndex = std::fmod(++m_bufferIndex, m_bufferSize);

		// Write output
		frameOut[c] = output;
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
