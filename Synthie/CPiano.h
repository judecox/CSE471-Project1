#pragma once
#include "CInstrument.h"
#include "AR.h"
#include "CSineWave.h"
#include "CWaveformPiano.h"
#include "audio/DirSoundSource.h"

#include <vector>
#include <memory>

class CPiano : public CInstrument
{

public:
	CPiano();

public:
	virtual void Start();
	virtual bool Generate();
	virtual void SetNote(CNote* note);

	void SetAdvDynamic(char* loudFile, bool advDynamics) { m_loudFileName = loudFile; m_advDynamic = advDynamics; }
	void SetDuration(double d) { m_duration = d; }
	void SetPedal(bool pedal) { m_pedal = pedal; }
	void SetVolume(double vol) { m_volume = vol; }
	bool PlayPedalDown();
	bool PlayPedalUp();

	void ChangeDuration();
	void Envelope();
	bool LoadSample(const char* filename);
	bool Interpolate(const char* filename);

	CWaveformPiano* GetPlayer() { return &m_waveformPiano; }

private:
	CWaveformPiano m_waveformPiano;
	std::vector<short> m_wave;
	std::vector<short> m_pedalWave;

	double m_duration;
	double m_time;
	double m_attack;
	double m_release;
	double m_volume; 

	bool m_advDynamic;
	bool m_pedal;
	char* m_loudFileName;

	CAR m_ar;
};

