#pragma once
#include "CInstrument.h"
#include <vector>

class CWaveform : public CAudioNode
{
public:
    CWaveform();

    void Start();

    virtual bool Generate();

    void SetTime(double t) { m_time = t; }

    void SetFreq(double f) { m_freq = f; }

    double Time() { return m_time; }

    double Freq() { return m_freq; }

private:
    double m_time;
    double m_freq = 1;

    // Lookup tables to be generated when the waveform is initialized
    std::vector<short> m_LookupTableL;
    std::vector<short> m_LookupTableR;
};
