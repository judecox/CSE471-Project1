#pragma once
#include "CAudioNode.h"

class CAR :
    public CAudioNode
{
public:
	CAR();

	//! Start audio generation
	virtual void Start();

	//! Generate one frame of audio
	virtual bool Generate();

	void SetSource(CAudioNode* source) { m_source = source; }

	void SetDuration(double d) { m_duration = d; }

	double Duration() { return m_duration; }

	void SetAttack(double at) { m_attack = at; }

	double Attack() { return m_attack; }

	void SetRelease(double rl) { m_release = rl; }

	double Release() { return m_release; }

	// void SetTime(double t) { m_time = t; }

	// double Time() { return m_time; }

private:
	double m_duration;
	double m_time;
	double m_attack;
	double m_release;
	CAudioNode* m_source;

};

