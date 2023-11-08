#pragma once
#include "CAudioNode.h"
#include "CNote.h"
#include "AR.h"
#include <vector>

class CInstrument :
    public CAudioNode
{
public:
    virtual void SetNote(CNote* note) = 0;

	void SetDuration(double d) { m_ar.SetDuration(d);}

	double Duration() { return m_ar.Duration(); }

	std::wstring m_effectID = std::wstring();

protected:
	CAR m_ar;
};

