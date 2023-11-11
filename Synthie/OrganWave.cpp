#include "pch.h"
#include "OrganWave.h"

COrganWave::COrganWave()
{
    m_amp = .9;
    m_freq = 440;

	m_harmonics.resize(9);
	m_harmonics[0] = harmonic(1, m_amps[8]);
	m_harmonics[1] = harmonic(3, 0);
	m_harmonics[2] = harmonic(2, 0);
	m_harmonics[3] = harmonic(4, 0);
	m_harmonics[4] = harmonic(6, 0);
	m_harmonics[5] = harmonic(8, 0);
	m_harmonics[6] = harmonic(10, 0);
	m_harmonics[7] = harmonic(12, 0);
	m_harmonics[8] = harmonic(16, 0);

	m_vibrato = 0;
	m_leslie = 0;
}

void COrganWave::Start()
{
	m_time = 0;

	m_phase.resize(9);
}

bool COrganWave::Generate()
{
	double output = 0;

	for (int i = 0; i < 9; i++) {
		harmonic temp = m_harmonics[i];
		output += temp.drawbars * sin(2* PI *m_phase[i]);
		UpdateVibrato(temp.tonewheel*m_freq, i);
	}

	m_frame[0] = (output * m_amp);
	m_frame[1] = m_frame[0];

	UpdateLeslie();

	m_time += GetSamplePeriod();

	return true;
}

int char2int(char x)
{
	return int(x - '0');
}

void COrganWave::SetDrawbar(WCHAR* x)
{
	for (int i = 0; i < 9; i++) { 
		m_harmonics[i].drawbars = m_amps[char2int(x[i])];
	}
}

void COrganWave::UpdateLeslie()
{
	double rate = m_time * (m_leslie*12);
	m_frame[0] = m_frame[0] * (1 - (0.5 * sin(2 * PI * rate)));
	m_frame[1] = m_frame[1] * (1 - (0.5 * cos(2 * PI * rate)));
}

void COrganWave::UpdateVibrato(int x, int i)
{
	double vibMag = m_vibrato * (.05*(x / 2));
	double vibFreq = m_vibrato*48;
	double temp = x + (vibMag * sin(m_time * vibFreq));
	m_phase[i] += temp * GetSamplePeriod();
}