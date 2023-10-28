#include "pch.h"
#include "CWaveform.h"
#include "audio/DirSoundSource.h"

CWaveform::CWaveform()
{
	m_time = 0;
	m_freq = 440;

	// Create lookup table
	CDirSoundSource audioin;

	if (!audioin.Open("wavetable_SDR_BA.wav"))
	{
		// Deal with the error
	}

	int numframes = audioin.NumSampleFrames();
	for (int i = 0; i < numframes; i++)
	{
		short audio[2];

		audioin.ReadFrame(audio);

		// Sample is mono, so both get same data
		m_LookupTableL.push_back(audio[0]);
		m_LookupTableR.push_back(audio[0]);
	}
}

void CWaveform::Start()
{
	m_time = 0;
}

bool CWaveform::Generate()
{
	// Use base function to start generate.
	int const i = int(m_time / GetSamplePeriod()) % m_LookupTableL.size();
	m_frame[0] = m_LookupTableL[i] * m_freq;
	m_frame[1] = m_LookupTableR[i] * m_freq;

	m_time += m_freq * GetSamplePeriod();

	return true;
}
