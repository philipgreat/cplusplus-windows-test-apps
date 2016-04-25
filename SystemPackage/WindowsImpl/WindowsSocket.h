// WindowsSocket.h: interface for the CWindowsSocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOWSSOCKET_H__80031602_FBDE_49AE_91F4_7AA8934237AD__INCLUDED_)
#define AFX_WINDOWSSOCKET_H__80031602_FBDE_49AE_91F4_7AA8934237AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWindowsSocket  
{
public:
	int Send(char*buffer, int length);
	int Connect(string serveraddr, unsigned short port);
	int Connect();
	CWindowsSocket();
	CWindowsSocket(string serveraddr,unsigned short port);
	virtual ~CSocket();

};

#endif // !defined(AFX_WINDOWSSOCKET_H__80031602_FBDE_49AE_91F4_7AA8934237AD__INCLUDED_)
