#pragma once
#include "CPiano.h"


class CPianoBuild
{
public:
	CPianoBuild();

	CPiano* CreatePiano();
	void SetNote(CNote* note);

private:
	double m_duration;
	double m_volume;
	bool m_pedal;
	bool m_playPedalUp;
	bool m_playPedalDown;
	bool m_advancedDynamic;
	char* m_loudFileName;
};

