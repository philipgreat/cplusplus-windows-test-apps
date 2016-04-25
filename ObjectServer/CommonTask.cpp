// CommonTask.cpp: implementation of the CCommonTask class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CommonTask.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCommonTask::CCommonTask()
{

}

CCommonTask::~CCommonTask()
{

}


int CCommonTask::SetContext(CCommonContext *pContext)
{
	this->m_pContext = pContext;
	return 0;
}


