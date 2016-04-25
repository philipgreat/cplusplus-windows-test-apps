// BaseCertificate.cpp: implementation of the CBaseCertificate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BaseCertificate.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBaseCertificate::CBaseCertificate()
{

}
CBaseCertificate::CBaseCertificate(DWORD id, DWORD cw)
{
	this->cwId=id;
	this->cw=cw;

}
CBaseCertificate::~CBaseCertificate()
{

}

DWORD CBaseCertificate::GetCW()
{
	return this->cw;	
}

DWORD CBaseCertificate::GetCWId()
{	
	return this->cwId;

}

char* CBaseCertificate::ToString()
{
	return NULL;
}
