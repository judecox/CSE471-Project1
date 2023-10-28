#include "pch.h"
#include "CNoiseGate.h"

CNoiseGate::CNoiseGate(int channels, double sampleRate, double samplePeriod) : CEffect(channels, sampleRate, samplePeriod)
{
	m_phases = std::vector<Phase>(m_channels, Open);
	m_times = std::vector<double>(m_channels, 0);
}

void CNoiseGate::XmlLoadAttribute(const CComBSTR & name, CComVariant & value)
{
	if (name == L"threshold")
	{
		value.ChangeType(VT_R8);
		m_threshold = value.dblVal;
	}
	else if (name == L"attack")
	{
		value.ChangeType(VT_R8);
		m_attack = value.dblVal;
	}
	else if (name == L"hold")
	{
		value.ChangeType(VT_R8);
		m_hold = value.dblVal;
	}
	else if (name == L"release")
	{
		value.ChangeType(VT_R8);
		m_release = value.dblVal;
	}
}

// Implements a attack, hold, release noise gate.
// Source: https://en.wikipedia.org/w/index.php?title=Noise_gate&oldid=1180959855#Controls_and_parameters
void CNoiseGate::Process(const double* frameIn, double* frameOut, const double& time)
{
	for (int c = 0; c < m_channels; c++)
	{
		switch (m_phases.at(c))
		{
		case Closed:
		{
			frameOut[c] = 0;
			if (frameIn[c] >= m_threshold)
			{
				// Move into attack. Use m_times to keep track of when
				// we entered a stage.
				m_phases.at(c) = Attack;
				m_times.at(c) = time;
			}
			break;
		}
		case Attack:
		{
			const double fAtk = (time - m_times.at(c)) / m_attack;

			if (fAtk >= 1)
			{
				m_phases.at(c) = Open;
				frameOut[c] = frameIn[c];
			}
			else
			{
				frameOut[c] = fAtk * frameIn[c];
			}
			break;
		}
		case Open:
		{
			frameOut[c] = frameIn[c];
			if (frameIn[c] < m_threshold)
			{
				m_phases.at(c) = Hold;
				m_times.at(c) = time;
			}
			break;
		}
		case Hold:
		{
			if (frameIn[c] >= m_threshold)
			{
				// Back in threshold. Go back to open state.
				frameOut[c] = frameIn[c];
				m_phases.at(c) = Open;
			}
			else
			{
				frameOut[c] = frameIn[c];

				if (time - m_times.at(c) >= m_hold)
				{
					m_phases.at(c) = Release;
					m_times.at(c) = time;
				}
			}
			break;
		}
		case Release:
		{
			if (frameIn[c] >= m_threshold)
			{
				// Back in threshold. Go back to open state.
				frameOut[c] = frameIn[c];
				m_phases.at(c) = Open;
			}
			else
			{
				const double fRls = (time - m_times.at(c)) / m_release;

				if (fRls >= 1)
				{
					m_phases.at(c) = Closed;
					frameOut[c] = 0;
				}
				else
				{
					frameOut[c] = frameIn[c] * (1 - fRls);
				}
			}
			break;
		}
		}
	}
}