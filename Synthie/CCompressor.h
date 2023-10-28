#pragma once
#include "CEffect.h"
#include <vector>

class CCompressor :
	public CEffect
{
	// Enums
public:
	enum Phase
	{
		// Compressor not active, input is below threshold.
		Hold,
		// Compressor just got activated, moving into Active phase.
		Attack,
		// Compressor is fully active.
		Active,
		// Compressor just got deactivated as input is now below threshold.
		// Moving into Hold phase.
		Release
	};
	// Contructor & Methods
public:
	CCompressor(int channels);

	// Inherited via CEffect
	void Process(const double* frameIn, double* frameOut, const double& time) override;

	// Member variables
private:
	std::vector<Phase> m_stages;
	std::vector<double> m_times;


	// Threshold at which the compressor will activate [0-1]
	double m_threshold;

	// https://en.wikipedia.org/wiki/Dynamic_range_compression#Ratio
	// Input as a real number. A ratio of 4:1 would be inputted as 4.
	double m_ratio;

	// Length of time to spend in attack stage.
	double m_attack = 0.1;

	// Length of time to spend in release state.
	double m_release = 0.2;

	// If true, use upwards compression. Otherwise, use downwards compression.
	// Default is false.
	bool m_isUpwards = false;

	// The current volumn of the compressor.
	double m_currentVol = 0;

	// Helper functions
private:
	// Returns the gain needed to get from the input level to the output level.
	// This does not consider the attack and release phases.
	double GetDeltaGain(double frameIn);

	// Inherited via CEffect
	void XmlLoadAttribute(const CComBSTR& name, CComVariant& value) override;
};

