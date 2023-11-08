#pragma once
#include "CAudioNode.h"
#include "CNote.h"
#include "AR.h"
#include "CEffect.h"
#include <vector>

class CInstrument :
    public CAudioNode
{
public:
    virtual void SetNote(CNote* note) = 0;

	void SetDuration(double d) { m_ar.SetDuration(d);}

	double Duration() { return m_ar.Duration(); }

	CEffect* m_effect;

protected:
	CAR m_ar;
};

