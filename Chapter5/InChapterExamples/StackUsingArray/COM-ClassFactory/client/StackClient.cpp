#include<windows.h>
#include "StackServerUsingRegFile.h"

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

IStack* pIStack = NULL;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wndclass;
    HWND hwnd;
    MSG msg;
    TCHAR AppName[] = TEXT("StackClient");
    HRESULT hr;

    hr = CoInitialize(NULL);

    if(FAILED(hr))
    {
        MessageBox(NULL, TEXT("Com Library initialization Failed"),TEXT("Program Error"),MB_OK);
        exit(0);
    }

    wndclass.cbSize = sizeof(wndclass);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
    wndclass.hInstance = hInstance;
    wndclass.lpszClassName = AppName;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);

    RegisterClassEx(&wndclass);

    hwnd = CreateWindow(AppName,TEXT("client of com server"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

    ShowWindow (hwnd,nCmdShow);

    UpdateWindow(hwnd);

    while(GetMessage(&msg,NULL,0,0))
    {
        //translate masage
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    
    CoUninitialize();
    return((int) msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT imsg, WPARAM wParam, LPARAM lParam)
{
    void SafeInterfaceRealease();

    HRESULT hr;
    TCHAR str[255];
    int size = 0;

    switch(imsg)
    {
        case WM_CREATE:
            hr  = CoCreateInstance(CLSID_Stack,NULL, CLSCTX_INPROC_SERVER,IID_IStack,(void**)&pIStack);

            wsprintf(str,TEXT("hr is %p"),hr);
            MessageBox(hwnd,str,TEXT("HR"),MB_OK);

            if(FAILED(hr))
            {
                MessageBox(hwnd,TEXT("IStack cannot be obtained"),TEXT("Error"),MB_OK);
                DestroyWindow(hwnd);
            }

            MessageBox(hwnd,TEXT("stack with default length is created Now You can do the operations"),TEXT("Error"),MB_OK);
            hr  = pIStack->getSize(&size);
            wsprintf(str,TEXT("Defalut stack Size is %d"),size);
            MessageBox(hwnd,str,TEXT("Stack "),MB_OK);
            MessageBox(hwnd,str,TEXT("Press Left key to push into the stack and press Right key to check the top"),MB_OK);
            //DestroyWindow(hwnd);
            break;
        
        case WM_LBUTTONDOWN:
            hr = pIStack->push(10);
            if(FAILED(hr))
            {
                MessageBox(hwnd,TEXT("Unable to push message"),TEXT("Error"),MB_OK);
                DestroyWindow(hwnd);
            }
            MessageBox(hwnd,TEXT("element pushed successfully"),TEXT("Error"),MB_OK);
            break;      
        case WM_RBUTTONDOWN:
            int top;
            hr = pIStack->top(&top);
            wsprintf(str,TEXT("Top of the stack is %d"),top);
            MessageBox(hwnd,str,TEXT("Stack "),MB_OK);
            break;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        
        default:
            break;



    }
    return(DefWindowProc(hwnd,imsg,wParam,lParam));
}

//link.exe StackClient.obj User32.lib GDI32.lib OLE32.lib OLEAUT32.lib /SUBSYSTEM:WINDOWS