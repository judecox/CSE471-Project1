#include "pch.h"
#include "CNoiseGate.h"

void CNoiseGate::ChannelsSet()
{
	m_stages = new Stage[m_channels];
	m_times = new double[m_channels];
}

// Implements a attack, hold, release noise gate.
// Source: https://en.wikipedia.org/w/index.php?title=Noise_gate&oldid=1180959855#Controls_and_parameters
void CNoiseGate::Process(const double* frameIn, double* frameOut, const double& time)
{
	for (int i = 0; i < m_channels; i++)
	{
		switch (m_stages[i])
		{
		case Closed:
		{
			frameOut[i] = 0;
			if (frameIn[i] >= m_threshold)
			{
				// Move into attack. Use m_times to keep track of when
				// we entered a stage.
				m_stages[i] = Attack;
				m_times[i] = time;
			}
			break;
		}
		case Attack:
		{
			const double fAtk = (time - m_times[i]) / m_attack;
			frameOut[i] = fAtk * frameIn[i];

			if (fAtk >= 1)
			{
				m_stages[i] = Open;
			}
			break;
		}
		case Open:
		{
			frameOut[i] = frameIn[i];
			if (frameIn[i] < m_threshold)
			{
				m_stages[i] = Hold;
				m_times[i] = time;
			}
			break;
		}
		case Hold:
		{
			frameOut[i] = frameIn[i];

			if (time - m_times[i] >= m_hold)
			{
				m_stages[i] = Release;
				m_times[i] = time;
			}
		}
		case Release:
		{
			const double fRls = (time - m_times[i]) / m_release;
			frameOut[i] = frameIn[i] * (1 - fRls);

			if (fRls >= 1)
			{
				m_stages[i] = Closed;
			}
			break;
		}
		}
	}
}