// WPLAYER.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include <commctrl.h>
#include <windows.h>
#include <mmsystem.h>
#include <streams.h>
#pragma comment(lib,"ole32")
#pragma comment(lib,"strmiids")
#pragma comment(lib,"strmbase")
#pragma comment(lib,"uuid")

int InitMediaEnviront();

#define MAX_LOADSTRING 100
#include <initguid.h>

DEFINE_GUID(CLSID_BouncingBall,
	0xfd501041, 0x8ebe, 0x11ce, 0x81, 0x83, 0x00, 0xaa, 0x00, 0x57, 0x7d, 0xa1);


HRESULT PlayMovie(LPTSTR lpszMovie);
HRESULT PlaySnow(LPTSTR lpszMovie);
IPin* GetFirstPin (IBaseFilter *inFilter);

void EnumPins (IBaseFilter *inFilter);
IPin* GetFirstPin (IBaseFilter *inFilter);
#define SAFE_RELEASE_COM(x)	if((x)!=NULL) {(x)->Release(); delete (x); (x)=NULL;}
//#define RIFF(x)			if(FAILED(hr=(x))){  printf(  }
#ifdef _WIN32_WCE
#define JIF(x) if (FAILED(hr=(x))) \
    {RETAILMSG(1, (TEXT("FAILED(hr=0x%x) in ") TEXT(#x) TEXT("\n"), hr)); printf("FAILED(hr=0x%x) in "); printf(#x); }
#else
#include <stdio.h>
#define JIF(x) if (FAILED(hr=(x))) \
    {printf("FAILED(hr=0x%x) in "); printf(#x); }

#endif
#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;
	
		::CoInitialize(NULL); 
	InitMediaEnviront();
	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WPLAYER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_WPLAYER);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}

//=======================================================================
	HRESULT hr;
	IGraphBuilder *pGB = NULL;

	IMediaControl *pMC = NULL;
	IMediaEventEx *pME = NULL;
	IVideoWindow  *pVW = NULL;
	IBaseFilter *pSnowFilter = NULL;
	IBaseFilter *pVMRFilter = NULL;
	IPin *pPinOut = NULL;
	IPin *pPinIn = NULL;

//=======================================================================

int InitMediaEnviront()
{

	
	JIF( CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC,
		IID_IGraphBuilder, (void **)&pGB));
	//add filter and connect them



	//hr=CoCreateInstance(INFINITEPINTEEFILTER, NULL, CLSCTX_INPROC_SERVER, IID_IBaseFilter, (void**)&pVideorenderFilter);
	JIF(CoCreateInstance(
		CLSID_VideoRenderer, 
		NULL, 
		CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, 
		(void**)&pVMRFilter));
	//pGB->FindFilterByName(
	//hr = pGB->FindFilterByName(L"Video Renderer", &pVMRFilter) ;

	JIF(CoCreateInstance(
		CLSID_BouncingBall, 
		NULL, 
		CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, 
		(void**)&pSnowFilter));
	//GET PINS
	JIF(pGB->QueryInterface(IID_IVideoWindow,(void **)&pVW));
	JIF(pGB->AddFilter(pVMRFilter,L"RENDER"));
	JIF(pGB->AddFilter(pSnowFilter,L"SOURCE"));

//	EnumPins(pSnowFilter);
//	EnumPins(pVMRFilter);

	//hr = pSnowFilter->FindPin(L"Output" , &pPinOut);
	pPinOut=GetFirstPin(pSnowFilter);
	//pVMRFilter
	//JIF( pVMRFilter->FindPin(L"VMR Input0" , &pPinIn));

	pPinIn=GetFirstPin(pVMRFilter);
	//pGB->AddSourceFilter(

	JIF(pGB->Connect (pPinOut,pPinIn));
	
	JIF( pGB->QueryInterface(IID_IMediaControl, (void **)&pMC));
	JIF( pGB->QueryInterface(IID_IMediaEventEx, (void **)&pME));

	return 0;	
}

void Play(HWND hWnd)
{
	//ShowWindow(hWnd, SW_SHOWNORMAL);

    RECT grc;
    GetClientRect(hWnd, &grc);
	JIF(pVW->put_Owner((OAHWND)hWnd));
    JIF(pVW->SetWindowPosition(0, 25, grc.right, grc.bottom));
	pMC->Run();
	::SetForegroundWindow(hWnd);

}
void ExitPlay()
{
	
	pMC->Stop();

}
int ProcessKeyDown(HWND hWnd,int msg){
	static int i=0;
	//case WM_COMMAND:
	//	R
	int c=VK_TAB;
	//WCHAR str[1024];
	//wsprintf(str,TEXT("%d"),msg);
	//::MessageBox(NULL,str,L"ddddddd",MB_OK);
#if 0
	switch(msg){
	case VK_TAB:
		//::MessageBox(NULL,str,L"ddddddd",MB_OK);
		Play(hWnd);
		break;
	case VK_RETURN:
		ExitPlay();
		break;
	
	}
#endif
	//E:/WINCE420/PUBLIC/stp_simple/RelDir/EMULATOR_X86Release/voices/WPlayer.exe
	if(i%2==0){
		Play(hWnd);
		i++;
	}else{
		ExitPlay();
		i++;	
	}
	return 0;

}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_WPLAYER);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_WPLAYER;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);

	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_TESTFOCUS:
					break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
			RECT rt;
			GetClientRect(hWnd, &rt);
			DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
			EndPaint(hWnd, &ps);
			break;
		case WM_CHAR:			
			ProcessKeyDown(hWnd,wParam & 0xff);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
IPin* GetFirstPin (IBaseFilter *inFilter)
{
	
	BOOL found=FALSE;
	IEnumPins * pEnum = NULL;
	IPin * pPin = NULL;

	if (SUCCEEDED(inFilter->EnumPins(&pEnum)))
	{
		//ASSERT(pEnum);
		printf("while(pSnowFilter)\n");
		while (pEnum->Next(1, &pPin, 0) == S_OK)
		{
			//_LOG_VAL(pinInfo.achName);
			printf("Next(pSnowFilter)\n");
			found=TRUE;
			pPin->Release();
		}
		pEnum->Release();
	}
	if(found){
		return pPin;
	}else{
		return NULL;
	}
	
}
