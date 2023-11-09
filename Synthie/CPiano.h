#pragma once
#include "CInstrument.h"
#include "AR.h"
#include "CSineWave.h"
#include "CWaveformPiano.h"
//#include "CSample.h"

#include <memory>

class CPiano : public CInstrument
{

public:
	CPiano();

	virtual void Start();
	virtual bool Generate();

	void SetNote(CNote* note);

	//void SetFreq(double f) { m_sinewave.SetFreq(f); }
	//void SetAmplitude(double a) { m_sinewave.SetAmplitude(a); }

	// below code is meant to interact with the CSample class, once/if it is implemented
	/*
		void SetSample(CSample* sample) { m_sample = sample; }
		double Duration() { return m_sample->Duration(); }
	*/

private:
	
	CWaveformPiano m_waveform;
	double m_time;

};

