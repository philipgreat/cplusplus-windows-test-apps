// HaspLoginTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <windows.h>

/////////////////////////////////////////////////////////////////////////////
// CHaspKey
#import <msxml4.dll> raw_interfaces_only
using namespace MSXML2;
#define GIF(x) if (FAILED(hr=(x))) \
{MessageBoxA(NULL,#x,#x,MB_OK);\
goto clearup;}


HRESULT login(BSTR url, BSTR username, BSTR password)
{
	// TODO: Add your implementation code here
	HRESULT hr = 0;
	VARIANT varAsync;
	varAsync.boolVal = FALSE;
	varAsync.vt = VT_BOOL;
	IXMLHTTPRequestPtr pIXMLHTTPRequest = NULL;
	GIF(pIXMLHTTPRequest.CreateInstance(L"MSXML2.ServerXMLHTTP"));
	GIF(pIXMLHTTPRequest->open(L"POST", url, varAsync));
	GIF(pIXMLHTTPRequest->setRequestHeader(L"User-Agent",L"LoginOcx"));
	WCHAR buffer[1024];
	wsprintfW(buffer,L"%s|%s|%s|%s",url,username,L"haspkey",password);
	GIF(pIXMLHTTPRequest->send(_variant_t(buffer)));
	BSTR result;
	GIF(pIXMLHTTPRequest->get_responseText(&result));
	wprintf(L"result = %s\n",result);

clearup:
	return hr;
}
int main(int argc, char* argv[])
{
	
	::CoInitialize(NULL);

	HRESULT hr = login(L"https://suddy.channel.com/haspauth/login_execute.jsp",
		L"user",
		L"pass");

	printf("hr = %u\n",hr);

	return 0;
}

