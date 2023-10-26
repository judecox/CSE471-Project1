#pragma once
#include <string>

class CNote
{
public:
    CNote(void);
    virtual ~CNote(void);

    bool operator<(const CNote& b);

    void XmlLoad(IXMLDOMNode* xml, std::wstring instrument, double bpm);

    const std::wstring& NoteStr() const { return m_note; }
    int Measure() const { return m_measure; }
    double Beat() const { return m_beat; }
    double Duration() const { return m_duration; }
    const std::wstring& Instrument() const { return m_instrument; }

private:
    std::wstring m_instrument;
    std::wstring m_note;
    int m_measure;
    double m_beat;
    double m_duration;
};

