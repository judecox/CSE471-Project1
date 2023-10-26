#pragma once
#include "CSineWave.h"
class CARSineWave :
    public CSineWave
{
public:
    CARSineWave() : CARSineWave(0.1) {}

    CARSineWave(double duration) : CARSineWave(duration, 0.05, 0.05) {}

    CARSineWave(double duration, double attack, double release);

    double Duration() { return m_duration; }

    virtual bool Generate();

    double GetSmoothedAmplitude();
private:
    double m_attack;
    double m_release;
    double m_duration;
    double m_time;
};

