// Socket.h: interface for the CSocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOCKET_H__43D90E94_9F80_4279_981D_090D19BEECA3__INCLUDED_)
#define AFX_SOCKET_H__43D90E94_9F80_4279_981D_090D19BEECA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
using namespace std;
class CSocket  
{
public:
	int Send(byte *buffer, int length);
	int Connect(string serveraddr, unsigned short port);
	int Connect();
	CSocket();
	CSocket(string serveraddr,unsigned short port);
	virtual ~CSocket();

};

#endif // !defined(AFX_SOCKET_H__43D90E94_9F80_4279_981D_090D19BEECA3__INCLUDED_)
