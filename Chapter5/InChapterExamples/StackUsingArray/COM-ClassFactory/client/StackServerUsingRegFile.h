#pragma once

class IStack : public IUnknown
{
    public:
        virtual HRESULT __stdcall getSize(int*) = 0;
        virtual BOOL __stdcall isempty() const = 0;
        virtual HRESULT __stdcall top(int*) const  = 0;
        virtual HRESULT __stdcall push(const int& e) = 0;
        virtual HRESULT __stdcall pop() = 0;

};


const CLSID CLSID_Stack = 
// {D5B55525-DB58-434B-A3EA-B24471C909AE}
{0xd5b55525, 0xdb58, 0x434b, 0xa3, 0xea, 0xb2, 0x44, 0x71, 0xc9, 0x9, 0xae};

const IID IID_IStack = 
// {BA51F2EE-AE9A-49B7-B376-CDFF3C9CE324}
{0xba51f2ee, 0xae9a, 0x49b7, 0xb3, 0x76, 0xcd, 0xff, 0x3c, 0x9c, 0xe3, 0x24};
