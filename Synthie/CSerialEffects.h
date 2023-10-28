#pragma once
#include "CEffect.h"
#include <vector>
class CSerialEffects :
    public CEffect
{
    // Member variables
private:
    std::vector<CEffect*> m_serial;

public:
    ~CSerialEffects();

    // Inherited via CEffect
    void Process(const double* frameIn, double* frameOut, const double& time) override;

    void XmlLoad(IXMLDOMNode* xml) override;

protected:
    void XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value) override;
};

