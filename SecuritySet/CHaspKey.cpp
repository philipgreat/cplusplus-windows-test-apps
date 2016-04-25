// HaspKey.cpp : Implementation of CHaspKey
#include "stdafx.h"
#include "SecuritySet.h"
#include "CHaspKey.h"
#include "HaspKey.h"
#include <windows.h>

/////////////////////////////////////////////////////////////////////////////
// CHaspKey
#import <msxml4.dll> raw_interfaces_only
using namespace MSXML2;
#define GIF(x) if (FAILED(hr=(x))) \
{MessageBoxA(NULL,#x,#x,MB_OK);\
goto clearup;}


STDMETHODIMP CHaspKey::login(BSTR url, BSTR username, BSTR password,BSTR *result)
{
	// TODO: Add your implementation code here
	int pass1 = 5277;
	int pass2 = 24547;
	char buffer[64];
	WCHAR wbuffer[1024];

	HRESULT hr = 0;
	VARIANT varAsync;
	varAsync.boolVal = FALSE;
	varAsync.vt = VT_BOOL;
	IXMLHTTPRequestPtr pIXMLHTTPRequest = NULL;
	BSTR code;
	HaspKey key;
	key.login(pass1,pass2);	
	if(key.read(buffer, 20)>0){
		WCHAR wbuffer[64];
		::MultiByteToWideChar(0,0,buffer,48,wbuffer,64);
		code = ::SysAllocString(wbuffer);		
	}else{
		code = ::SysAllocString(L"");
		*result = code;
		return 100;
	}


	GIF(pIXMLHTTPRequest.CreateInstance(L"MSXML2.ServerXMLHTTP"));
	GIF(pIXMLHTTPRequest->open(L"POST", url, varAsync));
	GIF(pIXMLHTTPRequest->setRequestHeader(L"User-Agent",L"LoginOcx"));
	GIF(pIXMLHTTPRequest->setRequestHeader(L"Cookie",username));

	wsprintfW(wbuffer,L"%s|%s|%s",username,code,password);
	GIF(pIXMLHTTPRequest->send(_variant_t(wbuffer)));
	BSTR responseText;
	GIF(pIXMLHTTPRequest->get_responseText(&responseText));
	*result = responseText;
	//wprintf(L"result = %s\n",responseText);

clearup:
	return hr;
}


STDMETHODIMP CHaspKey::applyToken(BSTR url, BSTR cookie, BSTR *result)
{
	// TODO: Add your implementation code here
	//this->login
	return this->login(url,cookie,L"cookie",result);
}
