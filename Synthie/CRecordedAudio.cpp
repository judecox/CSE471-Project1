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
	
	m_frame[0] = (double)audio[0] / (double)32767; //Conversion between short and float
	if (m_frame[0] > (1.0 - m_fuzz))
	{
		m_frame[0] = (1.0 - m_fuzz);
	}
	if (m_frame[0] < (-1.0 + m_fuzz))
	{
		m_frame[0] = (-1.0 + m_fuzz);
	}
	m_frame[0] *= m_amplitude;

	m_frame[1] = (double)audio[1] / (double)32767;
	if (m_frame[1] > (1.0 - m_fuzz))
	{
		m_frame[1] = (1.0 - m_fuzz);
	}
	if (m_frame[1] < (-1.0 + m_fuzz))
	{
		m_frame[1] = (-1.0 + m_fuzz);
	}
	m_frame[1] *= m_amplitude;
	//m_time += GetSamplePeriod();
	m_elapsed++;

	return true; //return m_time < duration in 
}