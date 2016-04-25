/*
hook.def
LIBRARY 	HookDLL
VERSION 	2.3
SECTIONS
    ._WINCAP READ WRITE SHARED
EXPORTS

   InstallHook                  ; For Keyboard Hook
   KeyboardHook                 ; For Keyboard Hook

hook.h

#ifndef HOOK_HEADER
#define HOOK_HEADER
#include <windows.h>
#define WM_MAKE_SNAP			WM_USER+10000
#define WM_MAKE_SNAP_ACTIVE		WM_USER+10001
#ifdef __cplusplus
extern "C"{
#endif

int WINAPI InstallHook (HWND hWnd, BOOL bCode );
LRESULT CALLBACK KeyboardHook (int nCode, WORD wParam, DWORD lParam );

#ifdef __cplusplus
}
#endif
#endif


*/

#define     STRICT      // enable strict type checking


#include "hook.h"



// Globals for this module


#define     STRICT      // enable strict type checking

extern HWND     ghWndMain;      // Handle to main window -- used to post msgs

static HHOOK    hHook;          // A handle to our installed hook
static BOOL     bHookInstalled; // TRUE if hook has been installed

// External variables

extern HINSTANCE	ghDLLInst;   // Handle to the DLL's instance.  Set in DllMain.

// Local function.  Although this function is exported from our DLL (Windows
// needs to call it directly), no other app needs to call this, so we can
// just prototype it here. 

#pragma data_seg("._WINCAP")
    HWND ghWndMain = 0;         // Handle to main window -- used to post msgs
#pragma data_seg()


HINSTANCE ghDLLInst = 0;   // Handle to the DLL's instance.
WORD nLangID;


//**********************************************************************
// InstallHook()
//
// Installs/Removes Filter function for the WH_KEYBOARD hook.
//
// Parameters:
// HWND hWnd      Handle to main window to receive posted messages.  See
//                KeyboardHook() for more info on how it works.
// 
// BOOL bCode     TRUE to hook, FALSE to unhook
//
// Returns:
// 1 if successful, 0 if not.
//
//**********************************************************************

int WINAPI InstallHook (HWND hWnd, BOOL bCode )
{

    ghWndMain = hWnd;  // Store app's window handle in DLL global variable

    // Make sure that we are installing/removing in the proper order

    if (bCode == bHookInstalled)
        return 0;

    if (bCode)
    {
        hHook = (HHOOK)SetWindowsHookEx(WH_KEYBOARD_LL,(HOOKPROC)KeyboardHook,ghDLLInst, 0);

        if (!hHook)
            return 0;

        bHookInstalled = TRUE;
		return 1;
    }
	bHookInstalled = FALSE;
    return UnhookWindowsHookEx(hHook);   
}

//**********************************************************************
//
// KeyboardHook()
//
// This is the Keyboard Hook function which windows will call every
// time it gets a keyboard message.  In this function, we check to
// see if the key pressed was Ctrl+Alt+F[8,9,10], and if it is, we post
// the proper message to our main window which will do the right
// thing.  
//
// Note that the window handle that we post from was set by a call to
// InstallHook() above.
//
// Parameters/return value:
//
// Standard 3.1 KeyboardProc.  See docs for "KeyboardProc".
//
//*********************************************************************
#include <stdio.h>
BOOL isDoubleTyped(int expectedKeyCode,int currentKeyCode, int keyTime,int keyMaxInterval)
{
	static int PrevKeyCode=0;
	static int PrevKeyTime=0;
	char buffer[1000];
	sprintf(buffer,"expected: %d prev: %d current: %d current time: %d\n",expectedKeyCode,PrevKeyCode,currentKeyCode,keyTime);
	OutputDebugString(buffer);
	if(currentKeyCode!=expectedKeyCode){
		PrevKeyCode=currentKeyCode;
		return FALSE;
	}
	PrevKeyTime=keyTime;
	if(PrevKeyCode!=expectedKeyCode){
		PrevKeyCode=currentKeyCode;
		return FALSE;
	}
	if(keyTime-PrevKeyTime>keyMaxInterval){
		PrevKeyTime=keyTime;
		return FALSE;
	}
	return TRUE;

}
LRESULT CALLBACK KeyboardHook (int nCode, WORD wParam, DWORD lParam )
{
	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT) (lParam);
	if(nCode<0){
		return 0;
	}
	// Check to see if it's a key we're looking for	
	if (wParam != WM_KEYUP){
		return (int)CallNextHookEx(hHook, nCode, wParam, lParam);
	}
	

	switch (p->vkCode)
	{

	case VK_SNAPSHOT :
		if(GetKeyState(VK_MENU) < 0){
			PostMessage(ghWndMain, WM_COMMAND, WM_MAKE_SNAP, 0L);
			break;
		}
		//without alt
		PostMessage(ghWndMain, WM_MAKE_SNAP_ACTIVE , p->vkCode,p->time);		
		break;
	case VK_F12 :		
		PostMessage(ghWndMain, WM_MAKE_SNAP_ACTIVE, p->vkCode,p->time);				
		break;
	default:
		break;
	}

	
	if(isDoubleTyped(VK_CAPITAL,p->vkCode,p->time,1000)){
		PostMessage(ghWndMain, WM_MAKE_SNAP_ACTIVE, p->vkCode,p->time);	
	}
#ifdef _OLD_CODE
#endif


	//
	// If we haven't returned 1 by the time we get here, then we
	// need to pass on the message to CallNextHookEx.
	//
	return (int)CallNextHookEx(hHook, nCode, wParam, lParam);
}




BOOL WINAPI DllMain (HANDLE hModule, DWORD dwFunction, LPVOID lpNot)
{
    ghDLLInst = hModule;

    switch (dwFunction)
    {
        case DLL_PROCESS_ATTACH:
            nLangID = PRIMARYLANGID(GetUserDefaultLangID());            
            break;

        case DLL_PROCESS_DETACH:

               // When we are finally going away, do something here

        default:
            break;
    }
    return TRUE;
}
