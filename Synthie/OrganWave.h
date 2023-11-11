#pragma once
#include "CAudioNode.h"
#include <vector>

class COrganWave :
    public CAudioNode
{
public:
    COrganWave();

    //! Start audio generation
    virtual void Start();

    //! Generate one frame of audio
    virtual bool Generate();

    //! Set the sine wave frequency
    void SetFreq(double f) { m_freq = f; }

    //! Set the sine wave amplitude
    void SetAmplitude(double a) { m_amp = a; }

    void SetDuration(double d) { m_duration = d; }

    void SetLeslie(double x) { m_leslie = x; }

    void SetVibrato(double x) { m_vibrato = x; }

    void SetDrawbar(WCHAR* x);

private:
    double m_time;
    double m_freq;
    double m_amp;
    std::vector <double> m_phase;
    double m_vibrato;
    double m_leslie;
    double m_duration;

    void UpdateLeslie();

    void UpdateVibrato(int x, int i);

    struct harmonic {

        harmonic(int x, double y)
        {
            tonewheel = x;
            drawbars = y;
        };

        harmonic()
        {
            tonewheel = 0;
            drawbars = 0;
        };

        int tonewheel;
        double drawbars;
    };

    std::vector<harmonic> m_harmonics;

    double m_amps[9] = {0, 0.0089, 0.0126, 0.0178, 0.0251, 0.0355, 0.0501, 0.0708 , .1};

};

