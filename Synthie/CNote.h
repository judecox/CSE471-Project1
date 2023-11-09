#pragma once
#include <string>

class CNote
{
public:
    CNote(void);
    virtual ~CNote(void);

    bool operator<(const CNote& b);

    void XmlLoad(IXMLDOMNode* xml, std::wstring& instrument, std::wstring & effect);
    IXMLDOMNode* Node() { return m_node; }

    int Measure() const { return m_measure; }
    double Beat() const { return m_beat; }
    const std::wstring& Instrument() const { return m_instrument; }
    const std::wstring& EffectID() const { return m_effectID; }

private:
    std::wstring m_instrument;
    std::wstring m_effectID;
    int m_measure;
    double m_beat;
    CComPtr<IXMLDOMNode> m_node;
};

