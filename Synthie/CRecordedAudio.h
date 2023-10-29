#pragma once
#include "CAudioNode.h"
#include "audio/Wave.h"
#include "audio/WaveformBuffer.h"
#include "audio/DirSoundStream.h"
#include "audio/DirSoundSource.h"

class CRecordedAudio :
    public CAudioNode
{
public:
    CRecordedAudio();
    ~CRecordedAudio();
    void Start();
    bool Generate();
    CDirSoundSource   m_wavein;
    CWaveOut          m_waveout;
    CWaveformBuffer m_waveformBuffer;
    void SetFuzz(double fuzz) { m_fuzz = fuzz; }
    double FrameValue(int c) { return m_frame[c]; }
    void SetAmplitude(double amp) { m_amplitude = amp; }
    void SetResonFrequency(double freq) { m_reson_freq = freq; }
    void SetResonBand(double band) { m_reson_band = band; }
    
private:
    int m_duration; //duration in frames
    int m_start_frame; //The frame at which this starts
    int m_elapsed = 0;
    double m_time;
    double m_frame[2];
    double m_fuzz = 0.0;
    double m_amplitude = 1.0;

    bool m_reson_enabled = true;

    int m_delay_length = 88202; //Times the number of frames * channels to get queue size
    double m_delay = 1.0;
    double m_gain = 10.5;
    double m_reson_freq = 0.00998;
    double m_reson_band = 0.015;
    int wrloc;

    std::vector<double> xqueue;
    std::vector<double> yqueue;
};

