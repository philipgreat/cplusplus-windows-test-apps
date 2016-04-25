// ServiceRequest.h: interface for the CServiceRequest class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVICEREQUEST_H__0AEB3446_F970_4698_94C1_2B9C087DD581__INCLUDED_)
#define AFX_SERVICEREQUEST_H__0AEB3446_F970_4698_94C1_2B9C087DD581__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CServiceRequest  
{
private:
	char id[8];
	//int  instanceRequested;
	int  oper;
	char data[1024];
public:
	char * GetData()  const;
	int GetOperation() const;
	void SetValue(int lv,const char *buffer);
	void Show();
	CServiceRequest();
	virtual ~CServiceRequest();

};

#endif // !defined(AFX_SERVICEREQUEST_H__0AEB3446_F970_4698_94C1_2B9C087DD581__INCLUDED_)
