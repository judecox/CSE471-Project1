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

/*

CAR::CAR()
{
	m_duration = 0.1;
	m_attack = 0.05;
	m_release = 0.05;
}

void CAR::Start()
{
	m_time = 0;
}

bool CAR::Generate()
{
	if (m_time < m_attack)
	{
		m_frame[0] = (m_source->Frame(0))*(m_time / m_attack);
		m_frame[1] = (m_source->Frame(1))*(m_time / m_attack);
	}
	else if(m_time > m_duration - m_release)
	{
		m_frame[0] = m_source->Frame(0)*((m_duration - m_time)/m_release);
		m_frame[1] = m_source->Frame(1)*((m_duration - m_time)/m_release);
	}
	else
	{
		m_frame[0] = m_source->Frame(0);
		m_frame[1] = m_source->Frame(1);
	}
	m_time += GetSamplePeriod();

	return m_time < m_duration;
}

*/
