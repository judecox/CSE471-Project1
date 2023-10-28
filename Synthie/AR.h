#pragma once
#include "CAudioNode.h"

class CAR :
    public CAudioNode
{
public:
	//! Start audio generation
	virtual void Start();

	//! Generate one frame of audio
	virtual bool Generate();

	void SetSource(CAudioNode* source) { m_source = source; }

	void SetDuration(double d) { m_duration = d; }

	double Duration() { return m_duration; }

	CAR();
private:
	double m_duration;
	double m_time;
	double m_attack;
	double m_release;
	CAudioNode* m_source;

};

