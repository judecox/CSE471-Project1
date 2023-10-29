#include "pch.h"
#include "CRecordedAudio.h"
#include "pch.h"
#include "CRecordedAudio.h"

CRecordedAudio::CRecordedAudio()
{
	m_duration = 0;
	m_elapsed = 0;
	m_start_frame = 0;
}

CRecordedAudio::~CRecordedAudio()
{

}

void CRecordedAudio::Start()
{
	m_elapsed = 0;
	wrloc = 0;
	xqueue.resize(m_delay_length);
	yqueue.resize(m_delay_length);
}

bool CRecordedAudio::Generate()
{
	short audio[2];
	int test = m_wavein.NumSampleFrames();
	if (m_elapsed >= m_wavein.NumSampleFrames())
	{
		return false;
	}

	m_wavein.ReadFrame(audio);
	short test2 = audio[0];
	
	//Fuzz
	if (audio[0] > 32767 * (1.0 - m_fuzz))
	{
		audio[0] = 32767 * (1.0 - m_fuzz);
	}
	if (audio[0] < 32767 * (-1.0 + m_fuzz))
	{
		audio[0] = 32767 * (-1.0 + m_fuzz);
	}

	if (audio[1] > 32767 * (1.0 - m_fuzz))
	{
		audio[1] = 32767 * (1.0 - m_fuzz);
	}
	if (audio[1] < 32767 * (-1.0 + m_fuzz))
	{
		audio[1] = 32767 * (-1.0 + m_fuzz);
	}

	audio[0] *= m_amplitude;
	audio[1] *= m_amplitude;

	if (m_reson_enabled)
	{
		float R = 1. - (m_reson_band / 2.);

		float cosine_value = (2. * R * cos(2 * 3.14159265358979323846 * m_reson_freq)) / (1. + (R * R));
		float A = sin(acos(cosine_value)) * (1. - (R * R)) * m_gain;


		wrloc = (wrloc + 2) % m_delay_length;
		if (wrloc >= m_delay_length)
		{
			wrloc -= m_delay_length;
		}

		//Save X Terms
		xqueue[wrloc] = audio[0];
		xqueue[wrloc + 1] = audio[1];
		audio[0] = 0;
		audio[1] = 0;

		int rdloc = (wrloc + m_delay_length) % m_delay_length; //Delaylength is int((delay + 0.5)) * 2;
		if (rdloc >= m_delay_length)
		{
			rdloc -= m_delay_length;
		}

		//Process X Terms
		audio[0] += (audio[0] / 2 + xqueue[rdloc++] / 2) * A;
		if (rdloc >= m_delay_length)
		{
			rdloc -= m_delay_length;
		}
		audio[1] += (audio[1] / 2 + xqueue[rdloc] / 2) * A;

		//Process Y Terms
		
		rdloc = (wrloc + m_delay_length - int((1 + 0.5)) * 2) % m_delay_length;
		audio[0] += (audio[0] / 2 + yqueue[rdloc++] / 2) * (2. * R * cosine_value);
		if (rdloc >= m_delay_length)
		{
			rdloc -= m_delay_length;
		}
		audio[1] += (audio[1] / 2 + yqueue[rdloc] / 2) * (2. * R * cosine_value);
		

		rdloc = (wrloc + m_delay_length - int((2 + 0.5)) * 2) % m_delay_length;
		audio[0] += (audio[0] / 2 + yqueue[rdloc++] / 2) * ( - 1 * R * R);
		if (rdloc >= m_delay_length)
		{
			rdloc -= m_delay_length;
		}
		audio[1] += (audio[1] / 2 + yqueue[rdloc] / 2) * ( - 1 * R * R);
		

		//Write Y Terms
		yqueue[wrloc] = audio[0];
		yqueue[wrloc + 1] = audio[1];
	}

	m_frame[0] = (double)audio[0] / (double)32767; //Conversion between short and float
	


	m_frame[1] = (double)audio[1] / (double)32767;
	

	//m_frame[0] *= m_amplitude;
	//m_frame[1] *= m_amplitude;

	
	//m_time += GetSamplePeriod();
	m_elapsed++;

	return true; //return m_time < duration in 
}