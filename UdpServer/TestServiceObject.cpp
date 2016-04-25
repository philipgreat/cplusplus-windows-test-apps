// TestServiceObject.cpp: implementation of the CTestServiceObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestServiceObject.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTestServiceObject::CTestServiceObject()
{

}

CTestServiceObject::~CTestServiceObject()
{
	
}

int CTestServiceObject::OnStart()
{
	return 0;
}

int CTestServiceObject::OnEnd()
{
	return 0;
}

int CTestServiceObject::Invoke(CServiceRequest *request, CServiceRequest *response)
{
	printf("ProcessRequest\n");
	
	switch(request->GetOperation()){

	case OPER_ADD_CERT_REQ:
		printf("\tAddReq Called\n");
		break;
	case OPER_GET_CERT_REQ:
		printf("\tGetReq Called\n");
		break;
	default:
		printf("\t!Unknown Called\n");
		break;
	
	}

	response->SetValue(request->GetOperation(),request->GetData());
	return 0;

}
