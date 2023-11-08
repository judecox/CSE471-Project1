#include "pch.h"
#include "CWaveform.h"
#include "audio/DirSoundSource.h"
#include <algorithm>

using namespace std;

CWaveform::CWaveform()
{
	m_time = 0;

	PrepareFileList();

	// Fill the lookup table with empty vectors.
	for (int i = 0; i < m_fileList.size(); i++)
	{
		m_LookupTable.push_back(vector<short>());
	}
}

void CWaveform::PrepareFileList()
{
	int n = 0;
	for (int i = 1; i < 5; i++)
	{
		for (auto note : m_noteList)
		{
			std::wstring filename = L"wavetable_samples/wavetable_";
			if (n < 10)
			{
				filename += L"0";
			}
			filename += to_wstring(n) + L"_" + note + to_wstring(i) + L".wav";

			m_fileList.push_back(filename);
			n++;
		}
	}
}

void CWaveform::LoadSampleIntoTable(std::wstring note)
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

int CWaveform::GetSampleIdFromNote(std::wstring note)
{
	// Get octave number and name of note (without octave number)
	int octave = note[note.size() - 1] - '0';
	wstring name = note.substr(0, note.size() - 1);

	// Get position of note name in the note name list
	int noteNum = 0;
	if ((note.size() == 3) && (note[1] == '#'))
	{
		noteNum = distance(m_noteListAlt.begin(),
			find(m_noteListAlt.begin(), m_noteListAlt.end(), name));
	}
	else
	{
		noteNum = distance(m_noteList.begin(),
			find(m_noteList.begin(), m_noteList.end(), name));
	}

	// Calculate and return proper sample ID
	return (12 * (octave - 1)) + noteNum;
}

void CWaveform::Start()
{
	m_time = 0;
	m_amp = 0.5;
}

bool CWaveform::Generate()
{
	// Use base function to start generate.
	//int const i = int(m_time / GetSamplePeriod()) % m_LookupTable[m_noteToPlay].size();
	int const i = m_frameIndex % m_LookupTable[m_noteToPlay].size();
	m_frame[0] = double(m_LookupTable[m_noteToPlay][i]) / 65535.0;
	m_frame[0] *= m_amp;
	m_frame[1] = m_frame[0];

	m_frameIndex++;

	m_time += GetSamplePeriod();

	// If the note hasn't yet been played long enough
	// and the waveform's time is after the end of the loop,
	// set the waveform's time back to the start of the loop.
	if ((m_time < (m_duration - Release())) && (m_time >= LoopEnd()))
	{
		m_time = LoopStart();
		m_frameIndex = int(LoopStart() / GetSamplePeriod());
	}

	return true;
}
