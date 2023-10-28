#pragma once
#include "CInstrument.h"
#include "AR.h"
#include "CSineWave.h"
//#include "CSample.h"

#include <memory>

class CPiano : public CInstrument
{

public:
	CPiano();

	virtual void Start();
	virtual bool Generate();

	void SetNote(CNote* note);

	void SetFreq(double f) { m_sinewave.SetFreq(f); }
	void SetAmplitude(double a) { m_sinewave.SetAmplitude(a); }

	// below code is meant to interact with the CSample class, once/if it is implemented
	/*
		void SetSample(CSample* sample) { m_sample = sample; }
		double Duration() { return m_sample->Duration(); }
	*/

private:
	// std::unique_ptr<CSample> m_sample;
	CSineWave   m_sinewave;
	CAR m_ar;
	double m_time;


/*
	// The CSample class in this case would give the capability to access a set 
	// Piano audio sample.wav files and set whatever given sample to SetNote in CPiano

	#pragma once

	#include <string>
	#include <vector>

	class CSample
	{
	public:
		CSample(const std::string& filePath);

		double GetSampleRate() const { return m_sampleRate; }
		double GetDuration() const { return m_duration; }
		const std::vector<double>& GetSamples() const { return m_samples; }

	private:
		double m_sampleRate;
		double m_duration;
		std::vector<double> m_samples;
	};*/
};

