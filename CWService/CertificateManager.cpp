// CertificateManager.cpp: implementation of the CCertificateManager class.
//
//////////////////////////////////////////////////////////////////////

#include "CertificateManager.h"
#include "GenericSAXParser.h"
#include "CertificateParserHelper.h"
static const DWORD ClearInactiveThreholdTime = 3600*4*1000;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCertificateManager::CCertificateManager():
certBufferLength(1024*4)
{
	tempCertBuffer=new BYTE[certBufferLength];
	//初始化为零
	memset(tempCertBuffer,0,certBufferLength);
	CJavaScriptGenerator::UpdateJavaScript();
	requestURLPrefix = new char[1024];
	this->LoadConfiguration();
}

CCertificateManager::~CCertificateManager()
{
	this->ClearCerts();
	delete requestURLPrefix;
	delete tempCertBuffer;
	tempCertBuffer=NULL;
}

int CCertificateManager::OnStart()
{
	printf("CCertificateManager::OnStart() \n");
	return 0;
}

int CCertificateManager::OnEnd()
{
	printf("CCertificateManager::OnEnd() \n");
	return 0;
}
/****************************************************************************\
      oper				opernum			sample
==============================================================================
	  AddTask			1				contenttype=10;cwid=200;
	  GetControlWord	2				contenttype=10;cwid=200;
	  TeardownSession	3
\****************************************************************************/
static enum  CERT_OPER_NUMBER{
	OPER_ADD_TASK = 1, 
	OPER_GET_CONTROL_WORD,
	OPER_TEARDOWN
};

int CCertificateManager::Invoke(CServiceRequest *request, CServiceRequest *response)
{
	CERTIFICATE_REQUEST_TASK *ptask;
	
	//request->Show();
	memcpy(response,request,sizeof(CServiceRequest));
	//DWORD contentType, DWORD contentId, DWORD authorizeType, DWORD controlWordId
	ptask =(CERTIFICATE_REQUEST_TASK*)response->GetData();
	DWORD controlword = 0;

	switch(request->GetOperation()){
	case OPER_ADD_TASK:
		this->AddTask(*ptask);
		break;
	case OPER_GET_CONTROL_WORD:
		controlword = this->GetControlWord(*ptask);
		//ptask->report();
		printf("controlword = %u\n",controlword);
		response->SetValue(request->GetOperation(),controlword);
		break;
	case OPER_TEARDOWN:	
		//printf("try to teardown the session\n");
		this->TeardownSession(*ptask);
		break;
	}
	return 0;
}


	
//this code like this: 
//	http://certificateserver/certificateservice/?
//  username=<username>&password=<password>&contentType=vod&contentid=100&cwid=100
//  so the parameters looks like this
/*
	username: <username>
	password: <password>
	contentType: <contentType>
	contentId: <contentId>
	cwid: <cwid>
*/



BOOL CCertificateManager::DownloadCertificate(char *username,
											  char *password,
											  CERTIFICATE_REQUEST_TASK task
											  )
{
	POSTDATA_INFO postData;
	postData.certificateTypeID = task.certificateTypeID;
	postData.contentId = task.contentId;
	postData.contentType = task.contentType;
	postData.controlWordId = task.controlWordId;
	postData.cpID = task.cpID;
	postData.password = password;
	postData.username = username;

	DWORD max = certBufferLength;
	util.ProcessPost(requestURLPrefix,postData,this->tempCertBuffer,&max);
	return TRUE;
}

void CCertificateManager::ClearCerts()
{
	map<CERTIFICATE_REQUEST_TASK, CBaseCertificate*, lttask>::iterator loc;
	for(loc=preparedCerts.begin(); loc!=preparedCerts.end();loc++)
	{
		CBaseCertificate *p=loc->second;
		//char *key = loc -> first;
		//delete key;
		//if was not online, then 
		delete p;
		p = NULL;
	}
}

#include "STBConfiguration.h"
#define  SERVER_CONFIG_ITEM   "CWService.URLPrefix"
void CCertificateManager::LoadConfiguration()
{
	CSTBConfiguration *config=new CSTBConfiguration();
	//requestURLPrefix="http://suddy/dl/lic.jsp";
	sprintf(requestURLPrefix,"%s",config->GetValue(SERVER_CONFIG_ITEM));
	sprintf(username,"%s",config->GetUsername());
	sprintf(password,"%s",config->GetPassword());
	delete config;


}
CBaseCertificate* CCertificateManager::ParseToCertificate()
{
	CGenericSAXParser *parser=new  CGenericSAXParser();
	CCertificateParserHelper *handle = new CCertificateParserHelper();
	parser->SetHandle(handle);
	
	//如果服务器请求失败
	if(this->tempCertBuffer==NULL||strlen((char*)this->tempCertBuffer)==0||(char)this->tempCertBuffer=='\0')
	{
		return new CSerializableCertificate();
	}
	//得到的字符串进行处理,首先将http头去除
	while(*(this->tempCertBuffer)!='<')
	{
		this->tempCertBuffer++;
	}
	parser->Parse((char*)this->tempCertBuffer);
	CBaseCertificate *ret = NULL;

	if(handle->IsNeedSave())
	{
		//if yes , comes very complex parsing 
		//and very very complex processing
		// (0_0)
		//printf("found license need to be save\n");
		ret=new CSerializableCertificate();
		CSerializableCertificate *p = 
			static_cast <CSerializableCertificate *> (ret);
		p->FromSaxHandle(handle);
		//need to config the store path, and make them store it

	}
	else
	{
		//printf("found license not need to be save\n");
		ret=new CVolatileCertificate();
		ret->SetCertificateID(handle->GetCertificateID());
		ret->SetContentId(handle->GetContentId());
		ret->SetContentTypeID(handle->GetContentTypeID());
		ret->SetControlWord(handle->GetControlWord());
		ret->SetControlWordId(handle->GetControlWordId());
		ret->SetCpID(handle->GetCpID());
		ret->SetCreateTime(handle->GetCreateTime());
		ret->SetMajorTypeId(handle->GetMajorTypeId());
		ret->SetSubTypeID(handle->GetSubTypeID());
		ret->SetUserID(handle->GetUserID());
	}
	//ret->Store();
	delete handle;
	delete parser;

	return ret;
}

DWORD CCertificateManager::AddTask(CERTIFICATE_REQUEST_TASK task)
{

	//requestQueue.push(task);

	//task.report();
	//如果请求已经存在则证明是重复请求， 所以直接可以加入
	//但是必须释放先前使用的
	map<CERTIFICATE_REQUEST_TASK, CBaseCertificate*, lttask>::iterator loc;
	loc = preparedCerts.find(task);
	if(loc==this->preparedCerts.end())
	{
		//没有证书，有两种情况，一种是该证书没有申请，另外一种情况是有证书，
		//但是该证书没有在内存，在外存里面
		//首先应该检查本地有没有证书
		//如果有，则不需要申请新的证书
		CBaseCertificate *pCert = NULL;	
		BOOL exists = CSerializableCertificate::IsCertExistsOnDisk(task.contentType,task.controlWordId);
		if(exists)
		{
			printf("this file is on the disk\n");

			//该证书一定是可以保存的证书
			pCert=new  CSerializableCertificate();
			CSerializableCertificate *psc = static_cast<CSerializableCertificate*>(pCert);
			psc->FromLocalFile(task.contentType,task.controlWordId);
			preparedCerts[task] = pCert;
			
		}
		else
		{
			printf("it is does not on the disk\n");
			//内存和外存都没有的情况下，必须下载证书才能够满足要求
			this->DownloadCertificate(
				this->username,
				this->password,
				task);
			pCert=this->ParseToCertificate();
			if(pCert->IsNeedStore())
			{
				preparedCerts[task] = pCert;
				//可用才保存该证书， 可能下载就不可用
				pCert->Store();
			}		
		}
		pCert->Report();

	}else{
		//有证书，在内存里面
		
		//printf("in memory\n");

	}

	return 0;
}

DWORD CCertificateManager::GetControlWord(CERTIFICATE_REQUEST_TASK task)
{
	//when a request send to the server, the server should determine where is
	//the certificate requested, perhaps it is unavailable, or stored as a file, 
	//in memory should in the map
	//when a certificate download, a use use to be
	map<CERTIFICATE_REQUEST_TASK, CBaseCertificate*, lttask>::iterator loc;
	loc = preparedCerts.find(task);
	DWORD controlWord = 0;
	if(loc!=this->preparedCerts.end())
	{
		CBaseCertificate *p=loc->second;
		controlWord =  p->GetControlWord();
		if(controlWord==0){
			this->RemoveFromMap(loc);
		}
	}
	else
	{
		//找不到也删除
		controlWord = 0L;
	}
	return controlWord;
}


BOOL CCertificateManager::TeardownSession(CERTIFICATE_REQUEST_TASK task)
{
	map<CERTIFICATE_REQUEST_TASK, CBaseCertificate*, lttask>::iterator loc;
	//task.report();
	loc = preparedCerts.find(task);
	if(loc != this->preparedCerts.end())
	{
		printf("CCertificateManager::TeardownSession\n");
		CBaseCertificate *p=loc->second;
		p->Teardown();
		//终止会话
		//return p->GetControlWord();
		//TODO: 加入时间控制机制
		//比如时间短于某个数值的时候, 不计入
		//p->Report();
		this->RemoveFromMap(loc);
	}
	this->ClearInactiveCertificate();
	//使用终止会话的机会, 清理不活动的CW
	CJavaScriptGenerator::UpdateJavaScript();
	return 0;
}


void CCertificateManager::RemoveFromMap(
		map<CERTIFICATE_REQUEST_TASK, CBaseCertificate*, lttask>::iterator &loc)
{
	CERTIFICATE_REQUEST_TASK task;
	task = loc->first;
	CBaseCertificate *p=loc->second;
	delete p;
	preparedCerts.erase(task);
}

BOOL CCertificateManager::ClearInactiveCertificate()
{
	map<CERTIFICATE_REQUEST_TASK, CBaseCertificate*, lttask>::iterator loc;
	for(loc = this->preparedCerts.begin();
		loc != this->preparedCerts.end(); loc++)
	{
		CBaseCertificate *p=loc->second;
		if(p->GetInactiveTime()>=ClearInactiveThreholdTime){
			//如果四个小时没有更新, 则从内存中清除
			this->RemoveFromMap(loc);
		}

	}
	return TRUE;
}
