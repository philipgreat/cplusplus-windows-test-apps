// VolatileCertificate.cpp: implementation of the CVolatileCertificate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VolatileCertificate.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVolatileCertificate::CVolatileCertificate()
{
	
}
CVolatileCertificate::CVolatileCertificate(DWORD cwId,DWORD cw)
{
	this->cwId=cwId;
	this->cw=cw;
	
}
CVolatileCertificate::~CVolatileCertificate()
{
	
}

BOOL CVolatileCertificate::Store()
{
	return TRUE;
}


