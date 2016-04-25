// NetworkUtil.h: interface for the CNetworkUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETWORKUTIL_H__094CC8CD_7B29_41A9_BFA3_7364BF6600B8__INCLUDED_)
#define AFX_NETWORKUTIL_H__094CC8CD_7B29_41A9_BFA3_7364BF6600B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
#ifndef  _WIN32_WCE
	#pragma comment(lib,"ws2_32")
#else
	#pragma comment(lib,"ws2")
	#include <Winsock.h>
#endif
class CNetworkUtil  
{
public:
	static void UninitNetwork();
	static void InitNetwork();
	static BOOL SyncTime(const char* host, unsigned short port);
	CNetworkUtil();
	virtual ~CNetworkUtil();

};

#endif // !defined(AFX_NETWORKUTIL_H__094CC8CD_7B29_41A9_BFA3_7364BF6600B8__INCLUDED_)
