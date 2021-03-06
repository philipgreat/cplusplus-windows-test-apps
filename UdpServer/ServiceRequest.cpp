// ServiceRequest.cpp: implementation of the CServiceRequest class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ServiceRequest.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include <windows.h>
#define  REQ_FLAG   ("servreq")
CServiceRequest::CServiceRequest():oper(0)
{
	memset(data,0x00,1024);
	memcpy(id,REQ_FLAG,strlen(REQ_FLAG)+1);
}

CServiceRequest::~CServiceRequest()
{

	
}

void CServiceRequest::Show()
{
	printf("this= 0X%08X oper = %d data = %s\n",this,oper,data);
}

void CServiceRequest::SetValue(int op, const char *buff)
{
	memset(data,0x00,1024);
	this->oper=op;
	memcpy(this->data,buff,strlen(buff));
}

int CServiceRequest::GetOperation() const
{
	return this->oper;
}

char * CServiceRequest::GetData() const
{
	return (char *)this->data;

}
