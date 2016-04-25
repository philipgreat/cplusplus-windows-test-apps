// CommonState.cpp: implementation of the CCommonState class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CommonState.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCommonState::CCommonState()
{
	//i=0;
	InitializeCriticalSection (&this->safeStateSection);  ///��ʼ���ٽ�������
}

CCommonState::~CCommonState()
{

}

void CCommonState::SetState(int st)
{
    __try 
    {
       EnterCriticalSection (&safeStateSection);   	   ///��ʼ��������

       ///�˴���д����
	   	this->state=st;

    }
    __finally   ///�쳣���������Ƿ��쳣��ִ�д˶δ���
    {
       LeaveCriticalSection (&safeStateSection);  ///������������
    }
}

int CCommonState::GetState()
{    __try 
    {
       EnterCriticalSection (&safeStateSection);   	   ///��ʼ������
	   return this->state;
	}__finally   ///�쳣���������Ƿ��쳣��ִ�д˶δ���
    {
	   return this->state;
       LeaveCriticalSection (&safeStateSection);  ///������������
    }
}