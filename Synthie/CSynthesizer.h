#pragma once
#include "msxml2.h"

#include <list>
#include <string>
#include <vector>
#include "CInstrument.h"
#include "CNote.h"
#include "CEffect.h"

class CSynthesizer
{
public:
	CSynthesizer();

	void Start(void);

	bool Generate(double* frame);

	void Clear(void);

	void OpenScore(CString& filename);

	//! Number of audio channels
	int GetNumChannels() { return m_channels; }

	//! Sample rate in samples per second
	double GetSampleRate() { return m_sampleRate; }

	//! Sample period in seconds (1/samplerate)
	double GetSamplePeriod() { return m_samplePeriod; }

	//! Set the number of channels
	void SetNumChannels(int n) { m_channels = n; }

	//! Set the sample rate
	void SetSampleRate(double s) { m_sampleRate = s;  m_samplePeriod = 1.0 / s; }

	//! Get the time since we started generating audio
	double GetTime() { return m_time; }

private:
	int m_channels;
	double m_sampleRate;
	double m_samplePeriod;
	double m_time;
	/// <summary>
	/// Beats per minute
	/// </summary>
	double m_bpm;
	/// <summary>
	///  Beats per measure
	/// </summary>
	int m_beatspermeasure;
	/// <summary>
	/// Seconds per beat
	/// </summary>
	double m_secperbeat;
	/// <summary>
	/// The current note we are playing
	/// </summary>
	int m_currentNote;
	/// <summary>
	/// The current measure
	/// </summary>
	int m_measure;
	/// <summary>
	/// The current beat within the measure
	/// </summary>
	double m_beat;

	std::vector<CEffect*> m_effects;
	std::list<CInstrument*>  m_instruments;
	std::vector<CNote*> m_notes;

	void XmlLoadScore(IXMLDOMNode* xml);
	void XmlLoadInstrument(IXMLDOMNode* xml);
	void XmlLoadEffectList(IXMLDOMNode* xml);
	void XmlLoadEffect(IXMLDOMNode* xml);
	void XmlLoadNote(IXMLDOMNode* xml, std::wstring& instrument);	
};

#pragma comment(lib, "msxml2.lib")