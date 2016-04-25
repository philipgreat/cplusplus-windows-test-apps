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
	updateTime = GetTickCount();
}

CBaseCertificate::~CBaseCertificate()
{
	
}


BOOL CBaseCertificate::IsAvaliable()
{
	return TRUE;
}
BOOL CBaseCertificate::Teardown()
{
	return TRUE;
}
DWORD CBaseCertificate::GetInactiveTime()
{
	DWORD now = GetTickCount();
	return now - this->updateTime;
}

BOOL CBaseCertificate::IsNeedStore()
{
	if(this->ControlWord!=0)
	{
		return TRUE;
	}
	else
	{
		return false;
	}
}

DWORD CBaseCertificate::GetControlWord() 
{
	return this->ControlWord;
};

void CBaseCertificate::UpdateState()
{

}