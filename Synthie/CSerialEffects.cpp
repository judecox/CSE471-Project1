#include "pch.h"
#include "CSerialEffects.h"
#include "xmlhelp.h"
#include "CEffectFactory.h"

CSerialEffects::~CSerialEffects()
{
	for each (auto * effect in m_serial)
	{
		delete effect;
	}

	m_serial.clear();
}

void CSerialEffects::Process(const double* frameIn, double* frameOut, const double& time)
{
	// Instantiate another frame that's a copy of frameIn (so that we can
	// modify it.)
	double* frame = (double*)calloc(m_channels, sizeof(double));

	for (int c = 0; c < m_channels; c++)
	{
		frame[c] = frameIn[c];
	}
	
	for each (CEffect * effect in m_serial)
	{
		// Process the frame. Make sure to use two different arrays to avoid
		// funny C++ activity.
		effect->Process(frame, frameOut, time);

		for (int c = 0; c < m_channels; c++)
		{
			frame[c] = frameOut[c];
		}
	}

	free(frame);
}

void CSerialEffects::XmlLoad(IXMLDOMNode* xml)
{
	CEffectFactory factory(m_channels);
	m_serial = factory.XmlLoadEffects(xml);
}

void CSerialEffects::XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value)
{
	// Do nothing lol.
}
