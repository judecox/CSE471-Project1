#include "pch.h"
#include "OrganWave.h"

COrganWave::COrganWave()
{
    m_phase = 0;
    m_amp = 0.1;
    m_freq = 440;
}

void COrganWave::Start()
{
    m_phase = 0;
}

bool COrganWave::Generate()
{
    m_frame[0] = m_amp * sin(m_phase * 2 * PI);
    m_frame[1] = m_frame[0];

    m_phase += m_freq * GetSamplePeriod();

    return true;
}