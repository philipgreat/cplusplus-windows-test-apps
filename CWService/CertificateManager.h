// CertificateManager.h: interface for the CCertificateManager class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  文件: CertificateManager.h	
  版权: 青牛(北京)技术有限公司
  日期: 2005-09-05
  描述: 证书管理的核心对象，该对象通常运行于某种容器中, 
		该对象对外提供服务, 是实现业务逻辑控制类
  参考: CUDPServer, CServiceObject
  作者: zhangxl@channel.com
  修订记录:	

\*===========================================================*/



#if !defined(AFX_CERTIFICATEMANAGER_H__135ACDE9_2B85_46DC_BB78_B9844BB8C9D9__INCLUDED_)
#define AFX_CERTIFICATEMANAGER_H__135ACDE9_2B85_46DC_BB78_B9844BB8C9D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#pragma warning(disable: 4786)
#include <windows.h>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
#include "ServiceObject.h"
#include "TaskDefine.h"
#include "BaseCertificate.h"
#include "VolatileCertificate.h"
#include "SerializableCertificate.h"
#include "RequestQueue.h"
#include "HttpUtil.h"

struct ltdword
{
	bool operator()(DWORD s1, DWORD s2) const
	{
		return s1 < s2;
	}
};
#define LESS_THAN_TEST(X,Y) if((X)<(Y)){return TRUE;}else if((X)>(Y)){return FALSE;}

struct lttask
{
	bool operator()(CERTIFICATE_REQUEST_TASK s1, CERTIFICATE_REQUEST_TASK s2) const
	{
		//return s1 < s2;
		LESS_THAN_TEST(s1.controlWordId,s2.controlWordId);
		LESS_THAN_TEST(s1.contentType,s2.contentType);
		LESS_THAN_TEST(s1.contentId,s2.contentId);
		LESS_THAN_TEST(s1.certificateTypeID,s2.certificateTypeID);
		if(strcmp(s1.cpID,s2.cpID)<0) return true; 
		else if(strcmp(s1.cpID,s2.cpID)>0) return false;
		return FALSE;
	}

};



/************************************************************************************\
	每次启动的时候应该把所有的证书都检查一次，删除已经过期的证书(检查);
\************************************************************************************/
//IsCertificateExists()
//TearDownSession(
class CCertificateManager : public CServiceObject  
{
private:
	const DWORD certBufferLength ;
	map<CERTIFICATE_REQUEST_TASK, CBaseCertificate *, lttask> preparedCerts;
	queue <CERTIFICATE_REQUEST_TASK> requestQueue;
	BYTE *tempCertBuffer;
	char *requestURLPrefix;
	CHttpUtil util;

private:
	char username[64];
	char password[64];
	char requestURL[1024*4];
	DWORD currentCW;
public:
	BOOL ClearInactiveCertificate();
	void RemoveFromMap(
		map<CERTIFICATE_REQUEST_TASK, CBaseCertificate*, lttask>::iterator &loc);
	BOOL TeardownSession(CERTIFICATE_REQUEST_TASK task);
	DWORD GetControlWord(CERTIFICATE_REQUEST_TASK task);
	DWORD AddTask(CERTIFICATE_REQUEST_TASK task);
	CBaseCertificate* ParseToCertificate();
	BOOL DownloadCertificate(
							char *username,
							char *password,
							CERTIFICATE_REQUEST_TASK task);
	//the three methods implement the serviceobject interface
	int Invoke(CServiceRequest *request,CServiceRequest *response);
	int OnEnd();
	int OnStart();
	CCertificateManager();
	virtual ~CCertificateManager();
private:
	void LoadConfiguration();
	void ClearCerts();
};

#endif // !defined(AFX_CERTIFICATEMANAGER_H__135ACDE9_2B85_46DC_BB78_B9844BB8C9D9__INCLUDED_)
