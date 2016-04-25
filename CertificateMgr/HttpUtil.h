// HttpUtil.h: interface for the CHttpUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HTTPUTIL_H__0C7CDE16_8D2C_4E4E_8F29_AC848033DF3D__INCLUDED_)
#define AFX_HTTPUTIL_H__0C7CDE16_8D2C_4E4E_8F29_AC848033DF3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once

#endif // _MSC_VER > 1000
#include <windows.h>


class CHttpUtil  
{

private:
	char *buffer;
public:
	enum HTTP_UTIL_STATE{HTTP_ERROR_CONNECT=1,HTTP_ERROR_DNSFAIL,HTTP_ERROR_REQFAIL};

	int ParseURL(const char*url,
		char **proto,
		char **host,unsigned short *port,char **path);
	int ProcessPost(const char *url,BYTE *retData,DWORD *maxLen);
	int ProcessGet(
		const char *url, //URL TO PRC
		BYTE *retData,//in out, a sequence of data
		DWORD *maxLen//in,out
		);
	CHttpUtil();
	virtual ~CHttpUtil();

};

#endif // !defined(AFX_HTTPUTIL_H__0C7CDE16_8D2C_4E4E_8F29_AC848033DF3D__INCLUDED_)
