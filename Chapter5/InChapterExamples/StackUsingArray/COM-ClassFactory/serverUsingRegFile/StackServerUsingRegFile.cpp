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
        CStack(int _capacity);

        ~CStack();

        //IUnkown methods
        HRESULT __stdcall QueryInterface(REFIID,void**);
        ULONG __stdcall AddRef();
        ULONG __stdcall Release();

        //IStack methods
        HRESULT __stdcall getSize(int*);
        BOOL __stdcall isempty() const;
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

//global variable declaration 
long glNumberOfActiveComponents = 0; // Number of active componenets
long glNumberOfServerLocks = 0; // NUmber of locks on this server

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID Reserved)
{
    //MessageBox(NULL,TEXT("IN DLLMAIN"),TEXT("ClassFactory"),MB_OK);
    switch(dwReason)
    {
        case DLL_PROCESS_ATTACH : 
            //MessageBox(NULL,TEXT("Process Attached"),TEXT("ClassFactory"),MB_OK);
            break;
        case DLL_PROCESS_DETACH :
            break;
        
    }

    return (true);
}  


//Implementation
CStack::CStack(int _capacity = 10)
{
    t  = -1;
    capacity = _capacity;
    S = new int[capacity];
    m_cRef = 1;
    InterlockedIncrement(&glNumberOfActiveComponents);
}

CStack::~CStack()
{
    delete(S);
    InterlockedDecrement(&glNumberOfActiveComponents);
}

        //IUnkown methods
HRESULT  CStack::QueryInterface(REFIID riid, void** ppv)
{
    if(riid == IID_IUnknown)
        *ppv = static_cast<IStack*>(this);
    else if(riid == IID_IStack)
        *ppv  = static_cast<IStack*>(this);
    else
    {
        *ppv = NULL;
        return(E_NOINTERFACE);

    }   

    reinterpret_cast<IUnknown*>(*ppv)->AddRef();
    return(S_OK); 
}

ULONG CStack::AddRef()
{
     InterlockedIncrement(&m_cRef);
    return(m_cRef);
}

ULONG CStack::Release()
{
     InterlockedDecrement(&m_cRef);
    return(m_cRef);
}

        //IStack methods
HRESULT CStack::getSize(int* Size)
{
    *Size = t + 1;
    return(S_OK);
}

BOOL CStack::isempty() const
{
    return (t < 0);
    
}

HRESULT CStack::top(int* top) const
{
      
        *top =  S[t];
        return(S_OK);
}

HRESULT CStack::push(const int& e)
{
    int size = 0;
    getSize(&size);
    if(size == capacity)
        return(E_NOT_VALID_STATE);
    else
        S[++t] = e;
    
    MessageBox(NULL,TEXT("Push opearation Successfull"),TEXT("Inner Class"),MB_OK);
    return(S_OK);

}

HRESULT CStack::pop()
{
    if(isempty())
        return(E_NOT_VALID_STATE);
    --t;
    return (S_OK);
} 

//Class Factory Implementation
CStackClassFactory::CStackClassFactory()
{
    m_cRef = 1;
}

CStackClassFactory::~CStackClassFactory()
{

}

        //IUnknowns Methods
HRESULT CStackClassFactory::QueryInterface(REFIID riid, void** ppv)
{
     if(riid == IID_IUnknown)
        *ppv = static_cast<IClassFactory*>(this);
    else if(riid == IID_IClassFactory)
        *ppv =static_cast<IClassFactory*>(this);
    else{
        *ppv  = NULL;
        return(E_NOINTERFACE);
    }

    reinterpret_cast<IUnknown*>(*ppv)->AddRef();
    return(S_OK);
}

ULONG CStackClassFactory::AddRef()
{
    InterlockedIncrement(&m_cRef);
    return (m_cRef);
}

ULONG CStackClassFactory::Release()
{
    InterlockedDecrement(&m_cRef);
    return(m_cRef);
}



        //IclassFactory Implementation
HRESULT CStackClassFactory::CreateInstance(IUnknown* PunkOuther, REFIID riid,void** ppv)
{
    CStack* stackptr = NULL;
    HRESULT hr;
    if(PunkOuther != NULL)
        return (CLASS_E_NOAGGREGATION);
    MessageBox(NULL,TEXT("IN createInstance"),TEXT("AGGREGATION"),MB_OK);
    stackptr = new CStack(100);
    if(stackptr == NULL)
        return(E_OUTOFMEMORY);
    MessageBox(NULL,TEXT("IN createInstance : Mempry Allocated"),TEXT("AGGREGATION"),MB_OK);
    hr = stackptr->QueryInterface(riid, (void**)ppv);
    stackptr->Release();
    return(hr);
    
}

HRESULT CStackClassFactory::LockServer(BOOL flock)
{
     if(flock)
        InterlockedIncrement(&glNumberOfServerLocks);
    else
        InterlockedDecrement(&glNumberOfServerLocks);
    return (S_OK);
}


//export methods

HRESULT __stdcall DllGetClassObject(REFCLSID rClsid, REFIID iid, void **ppv)
{
    CStackClassFactory* pCStackClassFactory;
    HRESULT hr;

    if(rClsid != CLSID_Stack)
        return(CLASS_E_CLASSNOTAVAILABLE);
    pCStackClassFactory = new CStackClassFactory();
    if(pCStackClassFactory == NULL)
        return(E_OUTOFMEMORY);
    hr =pCStackClassFactory->QueryInterface(iid,(void**)ppv);
    pCStackClassFactory->Release();
    return(hr);


}

HRESULT __stdcall DllCanUnloadNow(void)
{
    if((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
        return(S_OK);
    else
        return(S_FALSE);
}

//link.exe StackServerUsingRegFile.obj /DLL /DEF:classFactoryDllServerWithRegFile.def User32.lib GDI32.lib OLE32.lib OLEAUT32.lib /SUBSYSTEM:WINDOWS