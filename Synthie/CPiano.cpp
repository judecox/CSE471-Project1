#include "pch.h"
#include "CPiano.h"
#include "Notes.h"

CPiano::CPiano()
{
	m_bpm = 120;
}

void CPiano::Start()
{
	m_sinewave->SetSampleRate(GetSampleRate(), m_bpm);
	m_sinewave->Start();
	m_time = 0;
}

bool CPiano::Generate()
{
    // Tell the component to generate an audio sample
    m_sinewave->Generate();

    // Read the component's sample and make it our resulting frame.
    m_frame[0] = m_sinewave->Frame(0);
    m_frame[1] = m_sinewave->Frame(1);

    // Update time
    m_time += GetSamplePeriod();

    // We return true until the time reaches the duration.
    return m_time < Duration();
}

void CPiano::SetNote(CNote* note)
{
    // Get a list of all attribute nodes and the
    // length of that list
    m_sinewave = std::make_unique<CARSineWave>(note->Duration());
    SetFreq(NoteToAudioFile(note->NoteStr().c_str()));
}