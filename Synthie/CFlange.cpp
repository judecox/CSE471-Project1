#include "pch.h"
#include "CFlange.h"

CFlange::CFlange(int channels, double sampleRate, double samplePeriod) : CEffect(channels, sampleRate, samplePeriod)
{
	m_delay = 0;
	m_phase = 0;
	m_frequency = 1;
	m_amplitude = 1;

	m_delayedFrame = (double*)calloc(m_channels, sizeof(double));
}

CFlange::~CFlange()
{
	if (m_delayedFrame != nullptr)
	{
		free(m_delayedFrame);
	}
}

void CFlange::Process(const double* frameIn, double* frameOut, const double& time)
{
	for (int c = 0; c < m_channels; c++)
	{
		double median = m_amplitude / -2.0;
		double delayedTime = time - sin(m_phase * 2 * PI);

		if (delayedTime <= 0)
		{
			// In negative time.
			std::copy(frameIn, frameIn + m_channels, m_delayedFrame);
		}

		//for (int c = 0; c < m_channels; c++)
		//{
		//	frameOut[c] = frameIn[c] + m_delayedFrames;
		//}
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
