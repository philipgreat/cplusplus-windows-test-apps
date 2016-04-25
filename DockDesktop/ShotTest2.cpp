// ShotTest2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include <windows.h>
#define MAX_LOADSTRING 100
#define WS_EX_LAYERED   0x80000
#define LWA_ALPHA       0x2
#define LWA_COLORKEY    0x1

static RECT orgRect;
//static CRemoteLogger logger;

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

HWND hWnd;


// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.
	MSG msg;
	
	
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SHOTTEST2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	
	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}
	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_SHOTTEST2);
	
	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	
	//SystemParametersInfo( SPI_SETWORKAREA, 1, &orgRect, 0 );
	SystemParametersInfo( SPI_SETWORKAREA, 1, &orgRect,SPIF_SENDCHANGE );
	//DWORD result=0;
	//SendMessageTimeout(HWND_BROADCAST,WM_SETTINGCHANGE,SPI_SETWORKAREA,(LPARAM)&orgRect,SMTO_NORMAL,100,&result);

	return msg.wParam;
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
	
	wcex.style			= CS_OWNDC;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= 0;//LoadIcon(hInstance, (LPCTSTR)IDI_SHOTTEST2);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;//(LPCSTR)IDC_SHOTTEST2;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= 0;//LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);
	
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
#if 0

#define WS_OVERLAPPED       0x00000000L
#define WS_POPUP            0x80000000L
#define WS_CHILD            0x40000000L
#define WS_MINIMIZE         0x20000000L
#define WS_VISIBLE          0x10000000L
#define WS_DISABLED         0x08000000L
#define WS_CLIPSIBLINGS     0x04000000L
#define WS_CLIPCHILDREN     0x02000000L
#define WS_MAXIMIZE         0x01000000L
#define WS_CAPTION          0x00C00000L     /* WS_BORDER | WS_DLGFRAME  */
#define WS_BORDER           0x00800000L
#define WS_DLGFRAME         0x00400000L
#define WS_VSCROLL          0x00200000L
#define WS_HSCROLL          0x00100000L
#define WS_SYSMENU          0x00080000L
#define WS_THICKFRAME       0x00040000L
#define WS_GROUP            0x00020000L
#define WS_TABSTOP          0x00010000L

#define WS_MINIMIZEBOX      0x00020000L
#define WS_MAXIMIZEBOX      0x00010000L

#endif



BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{

	
	hInst = hInstance; // Store instance handle in our global variable
	
	int scx = ::GetSystemMetrics(SM_CXSCREEN);
	int scy = ::GetSystemMetrics(SM_CYSCREEN);
	
	HWND hwnd=GetDesktopWindow();
	RECT rect;
	::GetClientRect(hwnd,&rect);
	
	RECT rcWorkArea = { 0 }; 
	
	SystemParametersInfo( SPI_GETWORKAREA, 0, &rcWorkArea, 0 );
	orgRect=rcWorkArea;
	rcWorkArea.right=rcWorkArea.right-200;
	SystemParametersInfo( SPI_SETWORKAREA, 1, &rcWorkArea,SPIF_SENDCHANGE );
	DWORD result=0;
	SendMessageTimeout(HWND_BROADCAST,WM_SETTINGCHANGE,SPI_SETWORKAREA,(LPARAM)&rcWorkArea,SMTO_NORMAL,100,&result);

	hWnd =::CreateWindowEx(
		
		WS_EX_TOOLWINDOW
		|WS_EX_RIGHTSCROLLBAR
		|WS_EX_LEFT
		|WS_EX_LTRREADING
		|WS_EX_LAYERED
		|WS_EX_TRANSPARENT
		,
		szWindowClass,"", WS_CAPTION
		|WS_CAPTION
		|WS_CLIPSIBLINGS
		|WS_POPUP
		//|TTS_NOPREFIX
		
			,
		rect.right-200, 0, 200, rcWorkArea.bottom,
		hwnd,NULL,hInstance,NULL);


	HMODULE hUser32 = GetModuleHandle(_T( "USER32.DLL"));
    typedef BOOL (WINAPI* ExtraFunction)(HWND hWnd,
               COLORREF crKey,
               BYTE bAlpha,
               DWORD dwFlags);

	::SetWindowTextA(hWnd,"ClipRoller");

    ExtraFunction SetLayeredWindowAttributes=(ExtraFunction)GetProcAddress(hUser32,"SetLayeredWindowAttributes");
    SetWindowLong(hWnd,GWL_EXSTYLE,GetWindowLong(hWnd,GWL_EXSTYLE)^0x80000);
    SetLayeredWindowAttributes(hWnd,RGB(100,100,200),150,LWA_ALPHA);
	

	SetWindowPos(hWnd,
		HWND_TOPMOST,
		rect.right-200, 0, 200, rect.bottom-30,
		SWP_NOMOVE|SWP_NOSIZE);

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
#if 0
#define WM_MOUSEFIRST                   0x0200
#define WM_MOUSEMOVE                    0x0200
#define WM_LBUTTONDOWN                  0x0201
#define WM_LBUTTONUP                    0x0202
#define WM_LBUTTONDBLCLK                0x0203
#define WM_RBUTTONDOWN                  0x0204
#define WM_RBUTTONUP                    0x0205
#define WM_RBUTTONDBLCLK                0x0206
#define WM_MBUTTONDOWN                  0x0207
#define WM_MBUTTONUP                    0x0208
#define WM_MBUTTONDBLCLK                0x0209
#endif 
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
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

		case WM_LBUTTONDOWN:
				break;
		case WM_RBUTTONDOWN:
			PostQuitMessage(0);
			break;

		case WM_KEYDOWN:
//			logger.Log(wParam);X

			if(wParam=='X'){
				PostQuitMessage(0);
			}
			break;
		case WM_PAINT:
			
			//HDC hdc=::GetDC(hWnd);	
			//::ReleaseDC(hWnd,hdc);
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
			RECT rt;
			
			GetClientRect(hWnd, &rt);
			DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
			
			EndPaint(hWnd, &ps);
			
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

#if 0 
logger.Log(LOWORD(lParam));
logger.Log(HIWORD(lParam));
#endif


/*

如果开始就是AA就是定义了全局窗口，AA仅仅是定义全部区域

定义窗口WW


*/