// CertificateManagerTestCase.cpp: implementation of the CCertificateManagerTestCase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CertificateManagerTestCase.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCertificateManagerTestCase::CCertificateManagerTestCase()
{

}

CCertificateManagerTestCase::~CCertificateManagerTestCase()
{

}

void CCertificateManagerTestCase::setup()
{

}

void CCertificateManagerTestCase::teardown()
{

}

char* CCertificateManagerTestCase::testAddTask(DWORD taskId)
{
	testee.AddTask(taskId);
	//testee.Report();
	return "ok";
}

char* CCertificateManagerTestCase::testProcess()
{
	testee.Process();
	//testee.Report();
	return "ok";
}

char* CCertificateManagerTestCase::testGetCWById(DWORD cwId)
{
	DWORD i=testee.GetCWById(cwId);
	if(i>0){
		//printf("cw  is %u",cwId);
		return "ok";
	}else{
		return "zero";	
	
	}
}
