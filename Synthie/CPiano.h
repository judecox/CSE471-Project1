#pragma once
#include "CInstrument.h"
#include "CARSineWave.h"

#include <memory>

class CPiano : public CInstrument
{

public:
	CPiano();

	virtual void Start();
	virtual bool Generate();

	void SetNote(CNote* note);

	void SetFreq(double f) { m_sinewave->SetFreq(f); }
	void SetAmplitude(double a) { m_sinewave->SetAmplitude(a); }
	
	double Duration() { return m_sinewave->Duration(); }

private:
	std::unique_ptr<CARSineWave> m_sinewave;
	double m_time;
};

