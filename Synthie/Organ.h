#pragma once
#include "CInstrument.h"
#include "AR.h"
#include "OrganWave.h"

class COrgan :
    public CInstrument
{
public:
	COrgan();

	virtual void Start();
	virtual bool Generate();

	void SetNote(CNote* note);

	void SetFreq(double f) { m_wave.SetFreq(f); }
	void SetAmplitude(double a) { m_wave.SetAmplitude(a); }

	void SetDuration(double d) override {
		CInstrument::SetDuration(d);
		m_wave.SetDuration(d);
	};


private:
	COrganWave   m_wave;
	double m_time;
};

