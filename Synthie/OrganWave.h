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

    void SetLeslieAttack(double x) { m_leslieAttack = x; }
    void SetLeslieRelease(double x) { m_leslieRelease = x; }
    void SetLeslieStart(double x) { m_leslieStart = x; }
    void SetLeslieEnd(double x) { m_leslieEnd = x; }
    void SetLeslieFreq(double x) { m_leslieFreq = x; }
    void SetLeslieChanged(bool x) { m_leslieChanged = x; }
    void SetLeslieRad(double x) { m_leslieRadius = x; }
    void SetVibratoMag(double x) { m_vibratoMag = x; }
    void SetVibratoFreq(double x) { m_vibratoFreq = x; }


    void SetDrawbar(int x);

private:
    double m_time;
    double m_freq;
    double m_amp;
    double m_phase;
    double m_vibrato_phase;
    double m_vibratoFreq;
    double m_vibratoMag;
    bool m_leslieChanged;
    double m_leslie_phase;
    double m_leslieFreq;
    double m_leslieStart;
    double m_leslieEnd;
    double m_leslieRadius;
    double m_leslieAttack;
    double m_leslieRelease;
    double m_duration;

    void UpdateLeslie();

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

};

