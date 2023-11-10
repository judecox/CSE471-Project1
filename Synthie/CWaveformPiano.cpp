#include "pch.h"
#include "CWaveformPiano.h"
#include "audio/DirSoundSource.h"
#include <algorithm>





using namespace std;

CWaveformPiano::CWaveformPiano(void)
{
	m_samples = NULL;
	m_numsamples = 0;
}

CWaveformPiano::~CWaveformPiano(void)
{
}

void CWaveformPiano::Start()
{
	m_position = 0;
}

bool CWaveformPiano::Generate()
{
	if (m_position < m_numsamples)
	{
		m_frame[0] = m_samples[m_position++] / 32768.0;
		m_frame[1] = m_frame[0];
		return true;
	}
	else
	{
		m_frame[1] = m_frame[0] = 0;
		return false;
	}
}