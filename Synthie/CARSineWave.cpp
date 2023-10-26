#include "pch.h"
#include "CARSineWave.h"

CARSineWave::CARSineWave(double duration, double attack, double release)
{
	m_attack = attack;
	m_release = release;
	m_duration = duration;
	m_time = 0;
}

bool CARSineWave::Generate()
{
	// Use base function to start generate.
	CSineWave::Generate();

	// Modify the frames to inclued attack/release.
	double a = GetSmoothedAmplitude();
	m_frame[0] *= a;
	m_frame[1] *= a;

	// Update time
	m_time += GetSamplePeriod();

	// We return true until the time reaches the duration.
	return m_time < m_duration;
}

double CARSineWave::GetSmoothedAmplitude()
{
	if (m_time < m_attack)
	{
		// Attack.
		return m_time / m_attack;
	}
	else if (m_duration - m_time < m_release)
	{
		// Release.
		return (m_duration - m_time) / m_release;
	}

	return 1.0;
}
