#pragma once
#include "CInstrument.h"
#include "CWaveform.h"

class CWavetable : public CInstrument
{
public:
	CWavetable();

	virtual void Start();
	virtual bool Generate();

	void SetNote(CNote* note);

	void SetFreq(double f) { m_waveform.SetFreq(f); }

	// Leftover from CToneInstrument
	// void SetAmplitude(double a) { m_waveform.SetAmplitude(a); }

private:
	CWaveform m_waveform;
	double m_duration;
	double m_time;
};
