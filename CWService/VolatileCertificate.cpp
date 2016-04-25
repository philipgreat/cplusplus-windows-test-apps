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
CVolatileCertificate::~CVolatileCertificate()
{
	
}

BOOL CVolatileCertificate::Store()
{
	return TRUE;
}



void CVolatileCertificate::Report()
{
	printf("CVolatileCertificate CertificateID:%s,ControlWordId:%u = ControlWord:%u\n",
		this->CertificateID,
		this->ControlWordId,
		this->ControlWord);
}

void CVolatileCertificate::UpdateState()
{
	DWORD now = GetTickCount();
	DWORD span = (DWORD)((double)(now - this->updateTime)/(double)(1000));

	if(span>=10){
		//如果时间到达5s则保存一次
		this->updateTime = now;	
		this->Store();
	}
}
