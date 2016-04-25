// CertificateManager.h: interface for the CCertificateManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CERTIFICATEMANAGER_H__2B9237E1_7A3E_4E08_AF55_B40382E1263F__INCLUDED_)
#define AFX_CERTIFICATEMANAGER_H__2B9237E1_7A3E_4E08_AF55_B40382E1263F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
#pragma warning(disable:4786)
/**********************************************************************\
֤��Ĺ���, ��������Ҫ���ⲿϵͳ���н�������, ��Ҫ�Ľ���ϵͳ��ʹ��HTTP
���֤��, ���ҽ���, ���ܺ�������Կ��Էŵ��ڴ���, ������Ϊ���л�֤�鱣
�浽Ӳ���ϡ�
����֤��Ĵ洢����:

\**********************************************************************/

#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#include "BaseCertificate.h"
#include "VolatileCertificate.h"
struct ltdword
{
	bool operator()(DWORD s1, DWORD s2) const
	{
		return s1<s2;
	}
};



class CCertificateManager  
{
private:
	map<DWORD, CBaseCertificate *, ltdword> preparedCerts;
	queue<DWORD> requestQueue;
	BYTE *tempCertBuffer;
public:
	

	BOOL Process();

	BOOL DownloadCertificate(DWORD cwId, CBaseCertificate *cert);
	BOOL StoreCertificate();
	DWORD GetQueuedCWCount();
	void Report();
	BOOL AddTask(DWORD cwId);
	DWORD GetCWById(DWORD cwId);
	CCertificateManager();
	virtual ~CCertificateManager();
private:
	void ClearCerts();
	BOOL ParseFromBuffer(const BYTE* buffer, int len,CBaseCertificate *cert);
	BOOL LoadIndexes();
	char* BuildApplyURL();
};

#endif // !defined(AFX_CERTIFICATEMANAGER_H__2B9237E1_7A3E_4E08_AF55_B40382E1263F__INCLUDED_)
