#include "pch.h"
#include "CAudioNode.h"

CAudioNode::CAudioNode()
{
    m_frame[0] = 0;
    m_frame[1] = 0;
    m_sampleRate = 44100;
    m_samplePeriod = 1.0 / 44100.0;
    m_bpm = 120;
}

void CAudioNode::SetSampleRate(double s, double bpm)
{
    m_sampleRate = s;
    m_samplePeriod = 1 / s;
    m_bpm = bpm;
}