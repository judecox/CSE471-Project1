#pragma once
#include "CInstrument.h"
#include "AR.h"
#include "CSineWave.h"

class CToneInstrument :
	public CInstrument
{
public:
	CToneInstrument();

	virtual void Start();
	virtual bool Generate();

	void SetNote(CNote* note);

	void SetFreq(double f) { m_sinewave.SetFreq(f); }
	void SetAmplitude(double a) { m_sinewave.SetAmplitude(a); }


private:
	CSineWave   m_sinewave;
	double m_duration;
	double m_time;
};

