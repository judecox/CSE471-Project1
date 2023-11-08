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


private:
	COrganWave   m_wave;
	double m_duration;
	double m_time;
};

