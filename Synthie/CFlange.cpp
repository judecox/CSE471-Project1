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
	//const double waveform = m_amplitude * sin(m_phase * 2 * PI);
	//const double waveform = 1;

	//m_phase += m_frequency * m_samplePeriod;


	m_delayIndex = (m_delayIndex + 1) % m_frameHistory.size();
	m_frameHistory[m_delayIndex] = frameIn[0];

	int delaylength = int((2 * m_sampleRate + 0.5)) * 2;
	int rdloc = (m_delayIndex + m_frameHistory.size() - delaylength) % m_frameHistory.size();

	frameOut[0] = m_frameHistory[rdloc++];


	//// Next index
	//++m_bufferIndex;
	//++m_delayIndex;

	//// Use frameHistory as a circular buffer.
	//for (int c = 0; c < 1; c++)
	//{
	//	const double input = frameIn[c];
	//	double output = 0;

	//	if (m_delayIndex >= 0)
	//	{
	//		frameOut[c] = m_frameHistory.front();
	//		m_frameHistory.pop();
	//	}
	//	else
	//	{
	//		frameOut[c] = input;
	//	}
	//	m_frameHistory.push(input);


	//	// Next index
	//	++m_bufferIndex;
	//	++m_delayIndex;

	//	//// Set output, include wetness.
	//	//output = input * (1.0 - m_wetness);

	//	//if (m_delayIndex >= 0)
	//	//	output += m_frameHistory[m_delayIndex] * waveform * m_wetness;


	//	//// Feedback
	//	////m_frameHistory[m_bufferIndex] = input * waveform * m_feedback +
	//	////	input * (1 - m_feedback);
	//	//m_frameHistory.push_back(input);

	//	//// Next index
	//	//++m_bufferIndex;
	//	//++m_delayIndex;

	//	//// Write output
	//	//frameOut[c] = output;
	//}
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
	m_frameHistory = std::vector<double>(800000);
}
