#define WINVER	0x0500
#include "windows.h"
#include "imm.h"

#pragma data_seg(".freepydic")
DWORD       dwMapFileOffset = 0;
DWORD       dwMapFileUsrOffset = 0;
WORD        wMapCount = 0;
WORD        wConversionSet = 0;
#pragma data_seg()

BOOL WINAPI DllMain (
					 HINSTANCE    hInstDLL,
					 DWORD        dwFunction,
					 LPVOID       lpNot)
{
	
 
    return TRUE;
}

/**********************************************************************/
/*      ImeInquire()                                                  */
/*                                                                    */
/**********************************************************************/
BOOL WINAPI ImeInquire(LPIMEINFO lpImeInfo,LPTSTR lpszClassName,DWORD dwSystemInfoFlags)
{
if (!lpImeInfo)
      return (FALSE);
   lpImeInfo->dwPrivateDataSize = sizeof(PRIVCONTEXT);
   lpImeInfo->fdwProperty = IME_PROP_KBD_CHAR_FIRST|
                             IME_PROP_CANDLIST_START_FROM_1|
                             IME_PROP_IGNORE_UPKEYS;
   lpImeInfo->fdwConversionCaps =      IME_CMODE_NATIVE|IME_CMODE_NATIVE|IME_CMODE_FULLSHAPE|IME_CMODE_CHARCODE
|IME_CMODE_SOFTKBD|IME_CMODE_NOCONVERSION;
  lpImeInfo->fdwSentenceCaps = 0;
  lpImeInfo->fdwUICaps = UI_CAP_ROT90|UI_CAP_SOFTKBD;
  lpImeInfo->fdwSCSCaps = SCS_CAP_COMPSTR|SCS_CAP_MAKEREAD;
  lpImeInfo->fdwSelectCaps = (DWORD)0;
  lstrcpy(lpszWndCls, (LPTSTR)szUIClassName);
  return (TRUE);
    return TRUE;
}

/**********************************************************************/
/*      ImeConversionList()                                           */
/*                                                                    */
/**********************************************************************/
DWORD WINAPI ImeConversionList(HIMC hIMC,LPCTSTR lpSource,LPCANDIDATELIST lpCandList,DWORD dwBufLen,UINT uFlags)
{
    

    return 0;
}

/**********************************************************************/
/*      ImeDestroy()                                                  */
/*                                                                    */
/**********************************************************************/
BOOL WINAPI ImeDestroy(UINT uForce)
{
   

    return TRUE;
}

/**********************************************************************/
/*      ImeEscape()                                                   */
/*                                                                    */
/**********************************************************************/
LRESULT WINAPI ImeEscape(HIMC hIMC,UINT uSubFunc,LPVOID lpData)
{
 
    return 0;
}

/**********************************************************************/
/*      ImeSetActiveContext()                                         */
/*                                                                    */
/**********************************************************************/
BOOL WINAPI ImeSetActiveContext(HIMC hIMC,BOOL fFlag)
{
    

    return TRUE;
}

/**********************************************************************/
/*      ImeProcessKey()                                               */
/*                                                                    */
/**********************************************************************/
BOOL WINAPI ImeProcessKey(HIMC hIMC,UINT vKey,LPARAM lKeyData,CONST LPBYTE lpbKeyState)
{
   
    return 0;
}

/**********************************************************************/
/*      NotifyIME()                                                   */
/*                                                                    */
/**********************************************************************/
BOOL WINAPI NotifyIME(HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue)
{

    return 1;
}

/**********************************************************************/
/*      ImeSelect()                                                   */
/*                                                                    */
/**********************************************************************/
BOOL WINAPI ImeSelect(HIMC hIMC, BOOL fSelect)
{
 
    return TRUE;
}


/**********************************************************************/
/*      ImeSetCompositionString()                                     */
/*                                                                    */
/**********************************************************************/
BOOL WINAPI ImeSetCompositionString(HIMC hIMC, DWORD dwIndex, LPVOID lpComp, DWORD dwComp, LPVOID lpRead, DWORD dwRead)
{
   

    return FALSE;
}

/**********************************************************************/
/*      ImeGetImeMenuItemInfo()                                       */
/*                                                                    */
/**********************************************************************/
DWORD WINAPI ImeGetImeMenuItems(HIMC hIMC, DWORD dwFlags, 
								DWORD dwType, 
								LPIMEMENUITEMINFO lpImeParentMenu, 
								LPIMEMENUITEMINFO lpImeMenu, 
								DWORD dwSize)
{


    return 0;
}

LRESULT CALLBACK StatusWndProc(HWND hStatusWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	return 0;
}

//编码窗口过程
LRESULT CALLBACK CompWndProc(HWND hCompWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	return 0;
}

//侯选汉字窗口过程
LRESULT CALLBACK CandWndProc(HWND hCandWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	return 0;
}
//设置输入法状态函数，如光标跟随等
BOOL WINAPI ImeConfigure(HKL hKL,HWND hAppWnd,DWORD dwMode,LPVOID  lpData)
{
    switch (dwMode)
   {
       case IME_CONFIG_GENERAL:
             //DialogBox(hInst, MAKEINTRESOURCE(SETIME), (HWND)hAppWnd, (DLGPROC)ImeSetDlgProc);
            break;
       default:
           return (FALSE);
          break;
      }
     return (TRUE);
}
//将用户按键转换为汉字编码
UINT WINAPI ImeToAsciiEx(UINT uVirtKey,UINT uScanCode,CONST LPBYTE lpbKeyState,LPTRANSMSGLIST lpTransBuf,UINT fuState,HIMC hIMC)  
{
	return 0;
}

BOOL WINAPI ImeUnregisterWord(LPCTSTR lpszReading,DWORD dwStyle,LPCTSTR lpszString)
{
    return (FALSE);
}


//自定义汉字编码格式，未作处理。
BOOL WINAPI ImeRegisterWord(LPCTSTR lpszReading,DWORD dwStyle,LPCTSTR lpszString)
{
    return (FALSE);
}


//自定义汉字编码格式，未作处理。
UINT WINAPI ImeGetRegisterWordStyle(UINT nItem,LPSTYLEBUF lpStyleBuf)
{
    return (FALSE);
}

//自定义汉字编码格式，未作处理。
UINT WINAPI ImeEnumRegisterWord(REGISTERWORDENUMPROC lpfnRegisterWordEnumProc,
    LPCTSTR lpszReading,DWORD dwStyle,LPCTSTR lpszString,LPVOID lpData)
{
    return (FALSE);
}

LRESULT CALLBACK E2CWndProc( hWnd, message, wParam, lParam )
{
	return 0;
}


