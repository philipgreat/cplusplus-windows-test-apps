// TestServiceObject.h: interface for the CTestServiceObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTSERVICEOBJECT_H__8C58F049_46EC_40A1_A919_EF3E9580B9E6__INCLUDED_)
#define AFX_TESTSERVICEOBJECT_H__8C58F049_46EC_40A1_A919_EF3E9580B9E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ServiceObject.h"

class CTestServiceObject : public CServiceObject  
{
public:
	int Invoke(CServiceRequest *request,CServiceRequest *response);
	//调用自身的方法来处理请求
	//把结果封装在response中
	int OnEnd();
	int OnStart();
	CTestServiceObject();
	virtual ~CTestServiceObject();
	
};
enum  REQUEST_FUNCTION_NUM{
	OPER_ADD_CERT_REQ=1,
	OPER_GET_CERT_REQ=2

} ;
#endif // !defined(AFX_TESTSERVICEOBJECT_H__8C58F049_46EC_40A1_A919_EF3E9580B9E6__INCLUDED_)
