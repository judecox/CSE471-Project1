#pragma once
#include "CAudioNode.h"
#include "CInstrument.h"
#include <vector>
#include <string>

class CWaveformPiano : public CAudioNode
{
public:
    CWaveformPiano();

    void PrepareFileList();

    void LoadSampleIntoTable(std::wstring note);

    int GetSampleIdFromNote(std::wstring note);

    void Start();

    virtual bool Generate();

    void SetTime(double t) { m_time = t; }

    double Time() { return m_time; }

    void SetDuration(double d) { m_duration = d; }

    double Duration() { return m_duration; }

    double Attack() { return m_attack; }

    double Release() { return m_release; }

    double LoopStart() { return m_loopStart; }

    double LoopEnd() { return m_loopEnd; }

private:
    double m_time;
    double m_amp;
    double m_duration;
    double m_attack = 0.01;
    double m_release = 0.03;
    double m_loopStart = 0.055;
    double m_loopEnd = 0.1;
    int m_noteToPlay;
    int frameIndex = 0;

    // List of notes
    std::vector<std::wstring> m_noteList { L"A0#l", L"A0#s", L"A0l", L"A0s", L"A1l", L"A1s", L"A1#l", L"A1#s", L"A2l", L"A2s", L"A2#l", L"A2#s", L"A3#l", L"A3#s", L"A3l", L"A3s", L"A4#l", L"A4#s", L"A4l", L"A4s", L"A5#l", L"A5#s", L"A5l", L"A5s", L"A6#l", L"A6#s", L"A6l", L"A6s", L"A7#l", L"A7#s", L"A7l", L"A7s", 
                                           L"B0l", L"B0s", L"B1l", L"B1s", L"B2l", L"B2s", L"B3l", L"B3s", L"B4l", L"B4s", L"B5l", L"B5s", L"B6l", L"B6s", L"B7l", L"B7s", 
    									   L"C0#l", L"C0#s", L"C0l", L"C0s", L"C1#l", L"C1#s", L"C1l", L"C1s", L"C2#l", L"C2#s", L"C2l", L"C2s", L"C3#l", L"C3#s", L"C3l", L"C3s", L"C4#l", L"C4#s", L"C4l", L"C4s", L"C5#l", L"C5#s", L"C5l", L"C5s", L"C6#l", L"C6#s", L"C6l", L"C6s", L"C7#l", L"C7#s", L"C7l", L"C7s",
                                           L"D1l", L"D1s", L"D1#l", L"D1#s", L"D2l", L"D2s", L"D2#l", L"D2#s", L"D3#l", L"D3#s", L"D3l", L"D3s", L"D4#l", L"D4#s", L"D4l", L"D4s", L"D5#l", L"D5#s", L"D5l", L"D5s", L"D6#l", L"D6#s", L"D6l", L"D6s", L"D7#l", L"D7#s", L"D7l", L"D7s",
                                           L"E1l", L"E1s", L"E2l", L"E2s", L"E3l", L"E3s", L"E4l", L"E4s", L"E5l", L"E5s", L"E6l", L"E6s", L"E7l", L"E7s",
                                           L"F1l", L"F1s", L"F1#l", L"F1#s", L"F2l", L"F2s", L"F2#l", L"F2#s", L"F3#l", L"F3#s", L"F3l", L"F3s", L"F4#l", L"F4#s", L"F4l", L"F4s", L"F5#l", L"F5#s", L"F5l", L"F5s", L"F6#l", L"F6#s", L"F6l", L"F6s", L"F7#l", L"F7#s", L"F7l", L"F7s",
                                           L"G1l", L"G1s", L"G1#l", L"G1#s", L"G2l", L"G2s", L"G2#l", L"G2#s", L"G3#l", L"G3#s", L"G3l", L"G3s", L"G4#l", L"G4#s", L"G4l", L"G4s", L"G5#l", L"G5#s", L"G5l", L"G5s", L"G6#l", L"G6#s", L"G6l", L"G6s", L"G7#l", L"G7#s", L"G7l", L"G7s",
                                           L"pedald", L"pedalu"};

    // File list
    std::vector<std::wstring> m_fileList;

    // Lookup table to be generated when the waveform is initialized
    std::vector<std::vector<short>> m_LookupTable;

};

