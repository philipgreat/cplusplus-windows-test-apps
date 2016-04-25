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
	InitializeCriticalSection (&this->safeStateSection);  ///初始化临界区变量
}

CCommonState::~CCommonState()
{

}

void CCommonState::SetState(int st)
{
    __try 
    {
       EnterCriticalSection (&safeStateSection);   	   ///开始保护机制

       ///此处编写代码
	   	this->state=st;

    }
    __finally   ///异常处理，无论是否异常都执行此段代码
    {
       LeaveCriticalSection (&safeStateSection);  ///撤销保护机制
    }
}

int CCommonState::GetState()
{    __try 
    {
       EnterCriticalSection (&safeStateSection);   	   ///开始保护机
	   return this->state;
	}__finally   ///异常处理，无论是否异常都执行此段代码
    {
	   return this->state;
       LeaveCriticalSection (&safeStateSection);  ///撤销保护机制
    }
}