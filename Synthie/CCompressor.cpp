#include "pch.h"
#include "CCompressor.h"

CCompressor::CCompressor(int channels, double sampleRate, double samplePeriod) : CEffect(channels, sampleRate, samplePeriod)
{
	m_currentVol = 0.0;
	m_stages = std::vector<Phase>(m_channels, Hold);
	m_times = std::vector<double>(m_channels, 0);
}

void CCompressor::Process(const double* frameIn, double* frameOut, const double& time)
{
	for (int c = 0; c < m_channels; c++)
	{
		double in = frameIn[c];
		double inAmp = abs(in);
		const int inSign = signbit(in) ? -1 : 1;
		double out = in;

		const double delta = in - (inSign * m_threshold);
		const double target = (inSign * m_threshold) + delta / m_ratio;

		Phase phase = m_stages.at(c);

		switch (phase)
		{
		case Hold:
		{
			if (inAmp < m_threshold)
			{
				// Input remains below threshold.
				out = in;
			}
			else
			{
				// Above threshold. Enter attack phase.
				out = in;
				m_times.at(c) = time;
				phase = Attack;
			}
			break;
		}
		case Attack:
		{
			if (inAmp < m_threshold)
			{
				// Input has fallen below threshold.
				// Go to Release phase.
				m_times.at(c) = time;
				phase = Release;
				break;
			}

			const double fAtk = (time - m_times.at(c)) / m_attack;

			if (fAtk < 1)
			{
				// Attack phase active. Decrease the output level
				// gradually until we reach target.
				out = target - (delta * fAtk);
			}
			else
			{
				// Attack is done. Go into Active phase.
				out = target;
				phase = Active;
			}
			break;
		}
		case Active:
		{
			if (inAmp > m_threshold)
			{
				// Input remains above threshold.
				out = target;
			}
			else
			{
				// Input has fallen below threshold.
				// Go to Release phase.
				m_times.at(c) = time;
				phase = Release;
			}
			break;
		}
		case Release:
		{
			if (inAmp > m_threshold)
			{
				// Input is now above threshold.
				// Go to Attack phase.
				m_times.at(c) = time;
				phase = Attack;
				break;
			}

			const double fRls = (time - m_times.at(c)) / m_attack;

			if (fRls < 1)
			{
				// Release phase active. Increase the output level
				// gradually until we reach the input.
				out = in + (delta * fRls);
			}
			else
			{
				// Release is done. Go into Hold phase.
				out = in;
				phase = Hold;
			}
			break;
		}
		}

		frameOut[c] = out;
		m_stages[c] = phase;
	}
}

double CCompressor::GetDeltaGain(double frameIn)
{
	double deltaGain = 0.0;

	if (m_isUpwards)
	{
		if (frameIn < m_threshold)
		{
			// Below threshold and upwards compression.
			// Start increasing the gain.
			deltaGain = (frameIn - m_threshold) / m_ratio;
		}
	}
	else if (!m_isUpwards && frameIn > m_threshold)
	{
		// Above threshold and downwards compression.
		// Start decreasing the gain.
		deltaGain = (m_threshold - frameIn) / m_ratio;
	}

	return deltaGain;
}

void CCompressor::XmlLoadAttribute(const CComBSTR& name, CComVariant& value)
{
	if (name == L"threshold")
	{
		value.ChangeType(VT_R8);
		m_threshold = value.dblVal;
	}
	else if (name == L"ratio")
	{
		value.ChangeType(VT_R8);
		m_ratio = value.dblVal;
	}
	else if (name == L"attack")
	{
		value.ChangeType(VT_R8);
		m_attack = value.dblVal;
	}
	else if (name == L"release")
	{
		value.ChangeType(VT_R8);
		m_release = value.dblVal;
	}
	else if (name == L"isUpwards")
	{
		value.ChangeType(VT_BOOL);
		m_isUpwards = value.boolVal;
	}
}
