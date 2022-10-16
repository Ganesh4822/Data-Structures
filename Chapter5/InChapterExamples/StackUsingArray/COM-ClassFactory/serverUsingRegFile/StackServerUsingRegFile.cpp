#include<windows.h>
#include "StackServerUsingRegFile.h"

class CStack : public IStack
{
    private:
        long m_cRef;
        int t;
        int capacity;
        int* S;
    
    public:
        CStack();

        ~CStack();

        //IUnkown methods
        HRESULT __stdcall QueryInterface(REFIID,void**);
        ULONG __stdcall AddRef();
        ULONG __stdcall Release();

        //IStack methods
        HRESULT __stdcall getSize(int*);
        HRESULT __stdcall isempty(int*) const;
        HRESULT __stdcall top(int*) const;
        HRESULT __stdcall push(const int& e);
        HRESULT __stdcall pop(); 


};

class CStackClassFactory : public IClassFactory
{
    private:
        long m_cRef;
    public:

        CStackClassFactory();

        ~CStackClassFactory();

        //IUnknowns Methods
        HRESULT __stdcall QueryInterface(REFIID,void**);
        ULONG __stdcall AddRef();
        ULONG __stdcall Release();

        //IclassFactory Implementation
        HRESULT __stdcall CreateInstance(IUnknown*, REFIID,void**);
        HRESULT __stdcall LockServer(BOOL);


};