// Issuer.cpp : Implementation of CIssuer
#include "stdafx.h"
#include "SecuritySetManagement.h"
#include "Issuer.h"
#include "HaspKey.h"
/////////////////////////////////////////////////////////////////////////////
// CIssuer
#include <windows.h>

/////////////////////////////////////////////////////////////////////////////
// CHaspKey
#import <msxml4.dll> raw_interfaces_only
using namespace MSXML2;
#define GIF(x) if (FAILED(hr=(x))) \
{MessageBoxA(NULL,#x,#x,MB_OK);\
goto clearup;}

const WCHAR *SSL_PROTOCOL=L"https://";

STDMETHODIMP CIssuer::issue(BSTR url, BSTR username, BSTR password, BSTR *result)
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
	HaspKey key;
	key.login(pass1,pass2);
#if  0
	if(_wcsnicmp(SSL_PROTOCOL,url,wcslen(SSL_PROTOCOL))!=0)
	{	
		MessageBox(NULL,L"必须使用HTTPS来访问",L"警告",MB_OK);
		*result = ::SysAllocString(L"");
		return 0;
	}
#endif
	GIF(pIXMLHTTPRequest.CreateInstance(L"MSXML2.ServerXMLHTTP"));
	GIF(pIXMLHTTPRequest->open(L"POST", url, varAsync));
	GIF(pIXMLHTTPRequest->setRequestHeader(L"User-Agent",L"LoginOcx"));

	wsprintfW(wbuffer,L"%s|%s|%s",username,L"applying",password);
	GIF(pIXMLHTTPRequest->send(_variant_t(wbuffer)));
	BSTR responseText;
	GIF(pIXMLHTTPRequest->get_responseText(&responseText));
	*result = responseText;
	if(wcsncmp(responseText,L"",2)==0){
		*result = ::SysAllocString(L"errorlogin");
		return hr;
	}

	memset(buffer,0,sizeof(buffer));

	::WideCharToMultiByte(0,0,responseText,wcslen(responseText),buffer,
		wcslen(responseText),NULL,NULL);

	if(key.write(buffer, 20)>0)
	{		
		*result = ::SysAllocString(L"ok");
	}else{
		*result = ::SysAllocString(L"");	
	}

	//::MultiByteToWideChar(0,0,buffer,48,wbuffer,64);

	//::SysFreeString(code);
clearup:
	return hr;
}
