#pragma once
#include "CEffect.h"
#include <vector>

class CNoiseGate :
	public CEffect
{
	// Enums
public:
	enum Phase
	{
		// No sound.
		Closed,
		// Input has reached threshold, and we are now
		// increasing volume to get to the volumn of the
		// open stage.
		Attack,
		// Max volumn. Same volumn as input.
		Open,
		// Keep at volumn of input after it has dipped
		// below threshold.
		Hold,
		// Decrease volumn until zero.
		Release
	};

	// Variables
private:
	std::vector<Phase> m_phases;

	std::vector<double> m_times;

	// Level of the threshold. Note that the volumn here ranges from 0-1.
	double m_threshold = 0.5;

	// Length of time to spend in attack stage.
	double m_attack = 0.1;

	// Length of time to spend in hold stage.
	double m_hold = 0.2;

	// Length of time to spend in release state.
	double m_release = 0.2;

	

public:
	CNoiseGate(int channels, double sampleRate, double samplePeriod);

	// Inherited via CEffect
	void Process(const double* frameIn, double* frameOut, const double& time) override;

protected:
	// Inherited via CEffect
	void XmlLoadAttribute(const CComBSTR & name, CComVariant & value) override;
};

