// CertificateParserHelper.cpp: implementation of the CCertificateParserHelper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CertificateParserHelper.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CCertificateParserHelper::CCertificateParserHelper()
{
	//初始化代码
	this->Amount = 0;
	memset(this->AuthenticateResult,0,sizeof(this->AuthenticateResult));
	memset(this->CertificateID,0,sizeof(this->CertificateID));
	this->ContentId = 0;
	this->ContentTypeID =0;
	this->ControlWord = 0;
	this->ControlWordId = 0;
	memset(this->CpID,0,sizeof(this->CpID));
	memset(this->CreateTime,0,sizeof(this->CreateTime));
	this->DescContent=NULL;
	memset(this->DescID,0,sizeof(this->DescID));
	memset(this->Expiration,0,sizeof(this->Expiration));
	this->MajorTypeId = 0;
	memset(this->StartTime,0,sizeof(this->StartTime));
	this->SubTypeID = 0;
	memset(this->Unit,0,sizeof(this->Unit));
	memset(this->UserID,0,sizeof(this->UserID));
}


CCertificateParserHelper::~CCertificateParserHelper()
{
	if(this->DescContent) 
	{
		delete this->DescContent;
		this->DescContent = NULL;
	}
}


int	CCertificateParserHelper::StartDocument()
{
	//printf("start document\n");
	return 0;
}

int	CCertificateParserHelper::EndDocument()
{
	//printf("EndDocument\n");
	return 0;
}

int	CCertificateParserHelper::StartElement(const char *element)
{
	//printf("start element : %s \n",element);
	return 0;
}

int	CCertificateParserHelper::EndElement()
{
	//printf("EndElement\n");
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
功能强大的宏, 复杂! 令人十分惊恐! 这些宏查找相关的标签, 如果标签和属性名相同, 
则进行赋值, 然后使用goto跳到末尾
*/

#define STREQUAL(x,y)    strncmp((x),(y),strlen((x))+1)==0

#define ASIGN_STRING_VALUE(elementd,named,valued) \
	if(STREQUAL(elementd,element)&&STREQUAL(named, name)){unsigned int length = sizeof(valued);int copyLen=strlen(value)+1 < length ? strlen(value)+1:length ;memset(valued,0x00,length);memcpy(valued,value,copyLen); goto END;}
#define ASIGN_DWORD_VALUE(elementd,named,valued) \
	if(STREQUAL(elementd,element)&&STREQUAL(named, name)){valued=(DWORD)atol(value);  goto END;}
#define ASIGN_BOOL_VALUE(elementd,named,valued) \
	if(STREQUAL(elementd,element)&&STREQUAL(named, name)){if(strncmp("true",value,strlen("true")+1)==0) valued=TRUE;else valued = FALSE;  goto END;}

//printf("'%s' = '%s' \n", name, valued);
//printf("'%s.%s' = '%u' \n",element, name, valued);
//printf("'%s.%s' = '%u' \n",element, name, valued);
static inline void AsignValue(const char* elementd,
					   const char* element, 
					   const char*named,
					   const char*name, 
					   char  *valued, 
					   const char *value,
					   unsigned int length)
{
	if(STREQUAL(elementd,element)&&STREQUAL(named, name)){
		int copyLen=strlen(value)+1 < length ? strlen(value)+1:length ;
		memset(valued,0x00,length);
		memcpy(valued,value,copyLen);	
		printf("'%s' = '%s' \n", name, value);
	}
}
/*
<IPTVLicense 
	Save ='false' Version = '1.0' LicenceID='12312321' UserID= 'sdf'>	
	<Content ContentID = '1231' ContentType = '123123'/>
	<ControlWord ID = '12' Value ='56565'/>
	<Rights>
		<PlayCount Count = '100' />
		<TimeLength Value = '2' Unit = 'd'/>
		<Duration StartTime = '2004-08-09T12:00:00' EndTime = '2004-08-09T12:00:00'/>
	</Rights>
</IPTVLicense>
*/

/*
<?xml version="1.0" encoding="utf-8"?>
<soap:Envelope xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/">
<soap:Body>
	<AuthenticateResponse xmlns="http://tempuri.org/">
		<AuthenticateResult>boolean</AuthenticateResult>
		<certificate CertificateID="string" UserID="string" SubTypeId="string" MajorTypeId="int" CPID="string" ContentId="int" ContentTypeId="int" CWID="long">
			<StartTime>dateTime</StartTime>
			<Expiration>dateTime</Expiration>
			<Amount>int</Amount>
			<Unit>string</Unit>
			<CreateTime>dateTime</CreateTime>
			<CW>unsignedInt</CW>
		</certificate>
		<desc>
			<ID>string</ID>
			<Desc>string</Desc>
		</desc>
	</AuthenticateResponse>
</soap:Body>
</soap:Envelope> 
*/
int	CCertificateParserHelper::OnProperty(const char* element, const char* name, const char*value)
{
	ASIGN_STRING_VALUE("AuthenticateResult","AuthenticateResult",this->AuthenticateResult);
	ASIGN_STRING_VALUE("certificate","CertificateID",this->CertificateID);
	ASIGN_STRING_VALUE("certificate","UserID",this->UserID);
	ASIGN_DWORD_VALUE("certificate","SubTypeId",this->SubTypeID);
	ASIGN_DWORD_VALUE("certificate","MajorTypeId",this->MajorTypeId);
	ASIGN_STRING_VALUE("certificate","CPID",this->CpID);
	ASIGN_DWORD_VALUE("certificate","ContentTypeId",this->ContentTypeID);
	ASIGN_DWORD_VALUE("certificate","ContentId",this->ContentId);
	ASIGN_DWORD_VALUE("certificate","CWID",this->ControlWordId);
	ASIGN_STRING_VALUE("StartTime","StartTime",this->StartTime);
	ASIGN_STRING_VALUE("Expiration","Expiration",this->Expiration);
	ASIGN_DWORD_VALUE("Amount","Amount",this->Amount);
	ASIGN_STRING_VALUE("Unit","Unit",this->Unit);
	ASIGN_STRING_VALUE("CreateTime","CreateTime",this->CreateTime);
	ASIGN_DWORD_VALUE("CW","CW",this->ControlWord);
	ASIGN_STRING_VALUE("ID","ID",this->DescID);
	/*
	ASIGN_STRING_VALUE(AuthenticateResponse);
	//printf("'%16s.%20s' = '%s' \n", element, name, value);
	//ASIGNSTRING("IPTVLicense",element,"Version",name,version,value);

	//AsignValue("IPTVLicense",element,"Version",name,version,value,sizeof(version));
	ASIGN_STRING_VALUE("IPTVLicense","Version",this->version);
	ASIGN_DWORD_VALUE("IPTVLicense","LicenseID",this->licenseId);
	ASIGN_STRING_VALUE("IPTVLicense","UserID",this->userId);
	//ASIGN_STRING_VALUE("IPTVLicense","Version",version);
	ASIGN_BOOL_VALUE("IPTVLicense","Save",this->isNeedSave);

	ASIGN_DWORD_VALUE("Content","ContentID",this->contentId);
	ASIGN_DWORD_VALUE("Content","ContentType",this->contentType);

	ASIGN_DWORD_VALUE("ControlWord","ID",this->controlWordId);
	ASIGN_DWORD_VALUE("ControlWord","Value",this->controlWord);

	ASIGN_DWORD_VALUE("PlayCount","Count",this->playCount);

	ASIGN_DWORD_VALUE("TimeLength","Value",this->timeLengthValue);
	ASIGN_STRING_VALUE("TimeLength","Unit",&this->timeLengthUnit);

	ASIGN_STRING_VALUE("Duration","StartTime",this->startTime);
	ASIGN_STRING_VALUE("Duration","EndTime",this->endTime);
	*/
END:	
	return 0;
}

int CCertificateParserHelper::OnError(const char *element, const char *name, const char *value)
{
	return 0;
}

char* CCertificateParserHelper::ReadValue( 
	char *val, unsigned int len,const char *value)
{
	int copyLen=strlen(value)+1 < len ? strlen(value)+1:len ;
	memset(val,0x00,len);
	memcpy(val,value,copyLen);
	return val;
}

