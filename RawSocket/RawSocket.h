// RawSocket1.h: interface for the CRawSocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAWSOCKET1_H__341240FC_0A87_47F8_B56B_2A2E9AE2D6FB__INCLUDED_)
#define AFX_RAWSOCKET1_H__341240FC_0A87_47F8_B56B_2A2E9AE2D6FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <winsock2.h> 
#include <Ws2tcpip.h> 
#include <stdio.h> 
//#include <mstcpip.h>
#include <stdlib.h> 

#include "TCPprotocol.h"

class CRawSocket  
{
public:
	int m_intSocket;
	unsigned short filteredPorts[1024];
	int filteredPortsCount;
public:
	void SetFilteredPorts(const char *portsExpr);
	int Monitor();
	int SetMixtureMode();
	int SetDestAddress(const char* dest);
	int SetOptions();
	int InitializeSocket();
	char* GetProtocolName(unsigned char proto );
	USHORT CheckSum(USHORT *buffer, int size);
	CRawSocket();
	virtual ~CRawSocket();

private:
	bool isNeedShowContent(unsigned port);
};




#endif // !defined(AFX_RAWSOCKET1_H__341240FC_0A87_47F8_B56B_2A2E9AE2D6FB__INCLUDED_)
