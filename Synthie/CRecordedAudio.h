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
    void Start();
    bool Generate();
    CDirSoundSource   m_wavein;
    CWaveOut          m_waveout;
    CWaveformBuffer m_waveformBuffer;
    void SetFuzz(double fuzz) { m_fuzz = fuzz; }
    
private:
    int m_duration; //duration in frames
    int m_start_frame; //The frame at which this starts
    int m_elapsed = 0;
    double m_time;
    double m_frame[2];
    double m_fuzz = 0.0;
};

