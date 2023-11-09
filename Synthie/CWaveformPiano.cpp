#include "pch.h"
#include "CWaveformPiano.h"
#include "audio/DirSoundSource.h"
#include <algorithm>

using namespace std;

CWaveformPiano::CWaveformPiano()
{
	m_time = 0;

	PrepareFileList();

	// Fill the lookup table with empty vectors.
	for (int i = 0; i < m_fileList.size(); i++)
	{
		m_LookupTable.push_back(vector<short>());
	}
}


void CWaveformPiano::PrepareFileList()
{
	for (auto note : m_noteList)
	{
		std::wstring filename = L"CompletePiano/";
			
		filename += note + L".wav";

		m_fileList.push_back(filename);
	}
}

void CWaveformPiano::LoadSampleIntoTable(std::wstring note)
{
	// Get sample number from note name
	m_noteToPlay = GetSampleIdFromNote(note);

	// Check if the sample is already in the table.
	// If it is, don't read it in again!
	if (m_LookupTable[m_noteToPlay].size() != 0)
		return;

	CDirSoundSource audioin;

	if (!audioin.Open(m_fileList[m_noteToPlay].c_str()))
		return;

	// Read the sample into memory
	for (int i = 0; i < audioin.NumSampleFrames(); i++)
	{
		short audio[2];

		audioin.ReadFrame(audio);

		m_LookupTable[m_noteToPlay].push_back(audio[0]);
	}

	audioin.Close();

}

int CWaveformPiano::GetSampleIdFromNote(std::wstring note)
{
	// Get number and name of note
	wstring name = note.substr(0, note.size() - 1);

	// Get position of note name in the note name list
	int noteNum = 0;
	noteNum = distance(m_noteList.begin(),
			find(m_noteList.begin(), m_noteList.end(), name));

	// Calculate and return proper sample ID
	return noteNum;
}

void CWaveformPiano::Start()
{
	m_time = 0;
	m_amp = 0.1;
}

bool CWaveformPiano::Generate()
{
	// Use base function to start generate.
	int const i = frameIndex % m_LookupTable[m_noteToPlay].size(); //int const i = int(m_time / GetSamplePeriod()) % m_LookupTable[m_noteToPlay].size();
	m_frame[0] = double(m_LookupTable[m_noteToPlay][i]) / 65535.0;
	m_frame[0] *= m_amp;
	m_frame[1] = m_frame[0];


	frameIndex++;

	m_time += GetSamplePeriod();

	// If the note hasn't yet been played long enough
	// and the waveform's time is after the end of the loop,
	// set the waveform's time back to the start of the loop.
	if ((m_time < (m_duration - Release())) && (m_time >= LoopEnd()))
	{
		m_time = LoopStart();
	}

	return true;
}