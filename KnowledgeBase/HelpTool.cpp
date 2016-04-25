// HelpTool.cpp : Implementation of CHelpTool
#include "stdafx.h"
#include "KnowledgeBase.h"
#include "HelpTool.h"
#include <windows.h>
#include <stdio.h>

#define GIF(x) if (FAILED(hr=(x))) \
{wprintf(TEXT("\n0X%08X:  In: "),hr);MessageBoxA(NULL,#x,#x,MB_OK);\
printf(#x); printf("\n"); goto clearup;}

#import <msxml4.dll> raw_interfaces_only
using namespace MSXML2;

/////////////////////////////////////////////////////////////////////////////
// CHelpTool
static HWND hwndDialog = NULL;
static HINSTANCE hinst = NULL; 

const int titlemax = 1024;
const int contentmax = 1024*1024;
const int keywordmax = 1024;
const int locationmax = 1024*2;
//BOOL CALLBACK DlgProc(HWND hDlg, UINT message,WPARAM wParam, LPARAM lParam) 
static BSTR gTitle;
static BSTR gContent;
static BSTR gKeywords;
static BSTR gLocation;
static	WCHAR *wtitle = new WCHAR[titlemax] ;
static  WCHAR *wcontent = new WCHAR[contentmax];
static  WCHAR *wkeywords = new WCHAR[keywordmax];
static  WCHAR *wlocation = new WCHAR[locationmax];


static BOOL CALLBACK DeleteItemProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam) 
{ 
#if 1   
	//SetDlgItemText(hwndDlg,IDC_TITLE,gTitle);
	switch (message) 
    { 
	case WM_INITDIALOG:
		SetDlgItemText(hwndDlg,IDC_TITLE,gTitle);
		SetDlgItemText(hwndDlg,IDC_CONTENT,gContent);
		SetDlgItemText(hwndDlg,IDC_LOCATION,gLocation);

		break;
	case WM_MOUSEMOVE:
		
		break;
	case WM_COMMAND: 
		switch (LOWORD(wParam)) 
		{ 
		case IDOK: 
			::GetDlgItemText(hwndDlg,IDC_CONTENT,wcontent,contentmax);
			::GetDlgItemText(hwndDlg,IDC_TITLE,wtitle,titlemax);
			::GetDlgItemText(hwndDlg,IDC_KEYWORDS,wkeywords,keywordmax);
			::GetDlgItemText(hwndDlg,IDC_LOCATION,wlocation,locationmax);

		case IDCANCEL: 
			EndDialog(hwndDlg, wParam); 
			return TRUE; 
		}
		break;
	default:
		//DefDlgProc(hwndDlg,message,wParam,lParam);
		;
		break;
    } 
#endif
    return FALSE; 
} 
#if 0
	set obj=CreateObject("Knowledgebase.HelpTool")
	call obj.AddToHelpStore("±êÌâ", "ÄÚÈÝ", "BSTR keywords")
	set obj=nothing
#endif

STDMETHODIMP CHelpTool::AddToHelpStore(BSTR title, BSTR content, BSTR fromURL)
{
	int ret;
	HRESULT hr = 0;
	IXMLHTTPRequestPtr pIXMLHTTPRequest = NULL;

	LoadConfiguration();
	hinst = (HINSTANCE)_Module.m_hInst;

	
	gTitle=title;
	gContent=content;
	//gKeywords=fromURL;
	gLocation=fromURL;
	//Afx:400000:8:10011:0:103016f
	HWND window = ::FindWindow(NULL,gLocation);
	if(window==NULL){
		MessageBox(NULL,L"HI",L"HI",MB_OK);
	}
	WCHAR *buffer = NULL;
    ret=DialogBox(hinst,MAKEINTRESOURCE(IDD_DIALOG1),
		window,
		(DLGPROC)DeleteItemProc); 
	if(ret==IDOK){
		VARIANT varAsync;		
		varAsync.boolVal = FALSE;
		varAsync.vt = VT_BOOL;
		buffer=new WCHAR[contentmax+titlemax+keywordmax+locationmax];

		wsprintf(buffer,
			L"title=%s\r\nsendto=%s\r\nfrom=%s\r\nkeywords=%s\r\nlocation=%s\r\n\r\n",
			wtitle,this->sendTo,L"knowledgebasesucker@localhost",wkeywords,wlocation);
		GIF(pIXMLHTTPRequest.CreateInstance(L"MSXML2.XMLHTTP"));
		GIF(pIXMLHTTPRequest->open(L"POST", postURL, varAsync));

		GIF(pIXMLHTTPRequest->setRequestHeader(L"User-Agent",L"Knowledgebase Browser"));
		::wcsncat(buffer,wcontent,wcslen(wcontent));
		GIF(pIXMLHTTPRequest->send(_variant_t(buffer)));
		delete buffer;
		buffer=NULL;
		pIXMLHTTPRequest = NULL;
	}else{
		
	}
	//CloseHandle(hwndDialog);
	return S_OK;
clearup:
	if(buffer){
		delete buffer;
		buffer = NULL;
	};
	pIXMLHTTPRequest = NULL;
	return S_FALSE;
}




#define A2W2(W,A)     MultiByteToWideChar(936,0,(A),strlen((A))+1,(W),strlen((A))+1)

void CHelpTool::LoadConfiguration()
{
	WCHAR pchToolHome[MAX_PATH];
	//=::getenv("TOOL_HOME");
	A2W2(pchToolHome,getenv("TOOL_HOME"));
	WCHAR buffer[MAX_PATH];
	wsprintf(buffer,L"%s\\%s",pchToolHome,L"\\config.ini");
	GetPrivateProfileString(L"helpasset",L"sendto",L"chang.luminarc@gmail.com",
		this->sendTo,MAX_PATH,buffer);

	GetPrivateProfileString(L"helpasset",L"posturl",
		L"http://suddy.channel.com/workflow/smartMail.jsp",
		this->postURL,MAX_PATH,buffer);
}

STDMETHODIMP CHelpTool::setParent(CWindow window)
{
	// TODO: Add your implementation code here
	parentWindow =(HWND) window;
	return S_OK;
}
