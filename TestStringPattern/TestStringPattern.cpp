// TestStringPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestStringPattern.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
BOOL IsMatchExp(CString pattern, CString testString)
{
	int orpos=pattern.Find("|");
	int andpos=pattern.Find("&");
	/*
	abcd|12312
	01234567890123456789
	    ^ 
	*/
	
	if(orpos<1&&andpos<1){
		//-1 or zero
		return (testString.Find(pattern)>=0);
	}
	if(orpos>0){
		CString str1=pattern.Mid(0,orpos);
		CString str2=pattern.Mid(orpos+1);
		return (testString.Find(str1)>=0||testString.Find(str2)>=0);
	}
	if(andpos>0){
		CString str1=pattern.Mid(0,andpos);
		CString str2=pattern.Mid(andpos+1);
		return (testString.Find(str1)>=0&&testString.Find(str2)>=0);
	}
	//this should not happen here
	return FALSE;

}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		cout << (LPCTSTR)strHello << endl;
	}
	printf("IsMatchExp(\"32|33\",\"33\")=%d\n",IsMatchExp("32|33","33"));
	printf("IsMatchExp(\"32|33\",\"33\")=%d\n",IsMatchExp("32|33","333"));
	printf("IsMatchExp(\"32|33\",\"33\")=%d\n",IsMatchExp("32|33","332"));


	return nRetCode;
}


