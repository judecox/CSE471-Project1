#include "pch.h"
#include "OrganWave.h"

COrganWave::COrganWave()
{
    m_amp = 0.1;
    m_freq = 440;

	m_harmonics.resize(9);
	m_harmonics[0] = harmonic(1, 8.0);
	m_harmonics[1] = harmonic(3, 0);
	m_harmonics[2] = harmonic(2, 0);
	m_harmonics[3] = harmonic(4, 0);
	m_harmonics[4] = harmonic(6, 0);
	m_harmonics[5] = harmonic(8, 0);
	m_harmonics[6] = harmonic(10, 0);
	m_harmonics[7] = harmonic(12, 0);
	m_harmonics[8] = harmonic(16, 0);

	m_time = 0;

	m_vibratoFreq = 0;
	m_vibratoMag = 0;

	m_leslieRadius = 0;
	m_leslieAttack = 0;
	m_leslieRelease = 0;
	m_leslie_phase = 0;
}

void COrganWave::Start()
{
    m_phase = 0;
	m_vibrato_phase = 0;
}

bool COrganWave::Generate()
{
	double output = 0;

	for (int i = 0; i < 9; i++) {
		harmonic temp = m_harmonics[i];
		output += temp.drawbars * sin(m_phase * temp.tonewheel);
	}

	m_frame[0] = output * m_amp;;
	m_frame[1] = m_frame[0];  // set the frame!

	// update phase
	m_phase += 2 * PI * ((m_freq + ((m_vibratoMag / 100.0) * m_freq) * sin(m_vibrato_phase)) * (1 + (m_leslieRadius * (cos(m_leslie_phase) / 340.3)))) * GetSamplePeriod();

	//update vibrato
	m_vibrato_phase += 2 * PI * m_vibratoFreq * GetSamplePeriod();

	UpdateLeslie();

	m_time += GetSamplePeriod();

	return true;
}

void COrganWave::SetDrawbar(int x)
{
	for (int i = 0; i < 9; i++) { 
		double temp = double(x % int(pow(10, (9 - i)))) / (int)pow(10, (8 - i));
		if (temp != 0)
		{
			m_harmonics[i].drawbars = pow(10.0, (((8 - temp) * -3) / 20));
		}
	}
}

void COrganWave::UpdateLeslie()
{
	if ((m_time < m_leslieAttack) && m_leslieChanged) {
		m_leslie_phase += 2 * PI * (m_leslieStart + ((m_leslieFreq - m_leslieStart) * (m_time / m_leslieAttack))) * GetSamplePeriod();
	}
	else if (m_time > (m_duration - m_leslieRelease)) {
		m_leslie_phase += 2 * PI * (m_leslieEnd + ((m_leslieFreq - m_leslieEnd) * (1 - ((m_time - m_duration + m_leslieRelease) / (m_duration - m_leslieRelease))))) * GetSamplePeriod();
		m_leslieStart = m_leslieEnd;
	}
	else {
		m_leslie_phase += 2 * PI * m_leslieFreq * GetSamplePeriod();
	}
}