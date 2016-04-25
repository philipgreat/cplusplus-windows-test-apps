// CertificateManagerTestCase.h: interface for the CCertificateManagerTestCase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CERTIFICATEMANAGERTESTCASE_H__0BC08489_8D07_459E_AFFE_F6708B7BC680__INCLUDED_)
#define AFX_CERTIFICATEMANAGERTESTCASE_H__0BC08489_8D07_459E_AFFE_F6708B7BC680__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CertificateManager.h"
#include <windows.h>
class CCertificateManagerTestCase  
{
private:
	CCertificateManager testee;
public:
	char* testGetCWById(DWORD cwId);
	char* testProcess();
	char* testDownloadCertificate();
	char* testAddTask(DWORD taskId);
	void teardown();
	void setup();
	CCertificateManagerTestCase();
	virtual ~CCertificateManagerTestCase();

};

#endif // !defined(AFX_CERTIFICATEMANAGERTESTCASE_H__0BC08489_8D07_459E_AFFE_F6708B7BC680__INCLUDED_)
