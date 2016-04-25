#ifndef HOOK_HEADER
#define HOOK_HEADER
#include <windows.h>
#define WM_MAKE_SNAP			WM_USER+10000
#define WM_MAKE_SNAP_ACTIVE		WM_USER+10001
#define WM_MAKE_SNAP_KEYPRESS	WM_USER+10002

#ifdef __cplusplus
extern "C"{
#endif

int WINAPI InstallHook (HWND hWnd, BOOL bCode );
LRESULT CALLBACK KeyboardHook (int nCode, WORD wParam, DWORD lParam );

#ifdef __cplusplus
}
#endif
#endif