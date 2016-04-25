// CertificateManager.cpp: implementation of the CCertificateManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CertificateManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCertificateManager::CCertificateManager()
{
	tempCertBuffer=new BYTE[1024*2];
}

CCertificateManager::~CCertificateManager()
{
	this->ClearCerts();
	delete tempCertBuffer;
	tempCertBuffer=NULL;

}

DWORD CCertificateManager::GetCWById(DWORD cwId)
{
	map<DWORD, CBaseCertificate *, ltdword>::iterator loc;
	loc=preparedCerts.find(cwId);
	if(loc!=preparedCerts.end()){
		CBaseCertificate *p=loc->second;
		return p->GetCW();
	}
	return 0;
}

BOOL CCertificateManager::AddTask(DWORD cwId)
{
	requestQueue.push(cwId);
	return TRUE;	
}

void CCertificateManager::Report()
{
	printf("things in cerficate manager\n");
	printf("queued size=%d----------------------------\n",
		this->requestQueue.size());	
	int len=preparedCerts.size();

	printf("ready certs: %u\n",len);
	map<DWORD, CBaseCertificate*, ltdword>::iterator loc;
	for(loc=preparedCerts.begin(); loc!=preparedCerts.end();loc++)
	{
		CBaseCertificate *p=loc->second;
		printf("\t%.10u = %.10u\n",p->GetCWId(),p->GetCW());
	}
	printf("end report \n\n");
}

char* CCertificateManager::BuildApplyURL()
{
	return NULL;	
}

DWORD CCertificateManager::GetQueuedCWCount()
{
	return this->requestQueue.size();
}

BOOL CCertificateManager::StoreCertificate()
{
	return TRUE;
}

#include "HttpUtil.h"

BOOL CCertificateManager::DownloadCertificate(DWORD cwId, 
											  CBaseCertificate *cert)
{
	//add username, password and other info as the parameters
	//that transfer to the server
	//get a buffer from the server and parse it
	CHttpUtil util;
	DWORD maxLen=1024*2;
	util.ProcessGet("http://suddy/xmlcert.xml",this->tempCertBuffer,&maxLen);
	//how to par it
	return TRUE;
}

enum CERTIFICATE_STATE{
	CERT_UNPROCED=0,	//未处理
	CERT_PROCING,		//在处理
	CERT_ENCRYPTED,		//已经加密
	CERT_DOWNLOADED,	//已经加密
	CERT_STORED,		//已经保存
	CERT_DISCARD		//已经丢弃
};

#define CERT_INDEX_FILE		"F:\\SUDDY\\cert_index.dat"
BOOL CCertificateManager::LoadIndexes()
{
	HANDLE saveFile;
	saveFile = CreateFile(CERT_INDEX_FILE, 
		GENERIC_READ, FILE_SHARE_READ, NULL, 
		OPEN_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, NULL);
	
	DWORD len=1024*4;
	DWORD readlen=1024*4;
	char *buffer=new char [len];
	::ReadFile(saveFile,buffer,len-1,&readlen,NULL);
	delete buffer;
	return TRUE;
}

BOOL CCertificateManager::Process()
{
	DWORD cwId = 0;
	if(!this->requestQueue.empty()){
		cwId = this->requestQueue.front();

		CBaseCertificate *pCert=new CVolatileCertificate(cwId,cwId);


		if(this->DownloadCertificate(cwId,pCert)){
			//preparedMemoryCertificate.insert(cwId,p);
			preparedCerts[cwId] = pCert;
			//printf("%d\n",cwId);
			this->requestQueue.pop();	
			return TRUE;
		}else{
			return FALSE;
		}		
	}
	return FALSE;
	//printf("%d\n",cwId);
	
}
/*

*/


BOOL CCertificateManager::ParseFromBuffer(const BYTE *buffer, int len, CBaseCertificate *cert)
{
	
	return FALSE;
}

void CCertificateManager::ClearCerts()
{
	map<DWORD, CBaseCertificate*, ltdword>::iterator loc;
	for(loc=preparedCerts.begin(); loc!=preparedCerts.end();loc++)
	{
		CBaseCertificate *p=loc->second;
		delete p;
		p = NULL;
	}
}







/*============================================================*/
/*
int main() {
  queue<int> Q;
  Q.push(8);
  Q.push(7);
  Q.push(6);
  Q.push(2);
  
  assert(Q.size() == 4);
  assert(Q.back() == 2);

  assert(Q.front() == 8);
  Q.pop();

  assert(Q.front() == 7);
  Q.pop();

  assert(Q.front() == 6);
  Q.pop();
  
  assert(Q.front() == 2);
  Q.pop();

  assert(Q.empty());
}
*/