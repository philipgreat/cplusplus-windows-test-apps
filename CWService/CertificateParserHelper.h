// CertificateParserHelper.h: interface for the CCertificateParserHelper class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  文件: CertificateParserHelper.h	
  版权: 青牛(北京)技术有限公司
  日期: 2005-09-05
  描述: 将XML解析为证书对象的类, 该类把相关的文本解析成需要的证书
  参考: CGenericSAXParser
  作者: zhangxl@channel.com
  修订记录:	

\*===========================================================*/
#if !defined(AFX_CERTIFICATEPARSERHELPER_H__55BE1AA3_FD3B_469E_BAFB_0F57AD9E2170__INCLUDED_)
#define AFX_CERTIFICATEPARSERHELPER_H__55BE1AA3_FD3B_469E_BAFB_0F57AD9E2170__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AbstractHandle.h"
#include "BaseCertificate.h"
/*
<IPTVLicense 
	Save ='false' Version = '1.0' LicenceID='12312321' UserID= 'sdf'>	
	<Content ContentID = '1231' ContentType = '123123'/>
	<ControlWord ID = '12' Value ='5656565'/>
	<Rights>
		<PlayCount Count = '100' />
		<TimeLength Value = '2' Unit = 'd'/>
		<Duration StartTime = '2004-08-09T12:00:00' EndTime = '2004-08-09T12:00:00'/>
	</Rights>
</IPTVLicense>
*/

class CCertificateParserHelper : public CAbstractHandle  
{
private:
	char  StartTime[20];  //证书开始时间
	char  Expiration[20]; //证书的结束时间
	DWORD Amount;		  //证书的使用次数
	char  Unit[2];        //证书的单位
	//返回证书XML格式中的属性
	char  CertificateID[33];   //证书的ID号，是一个唯一的GUID
	DWORD MajorTypeId;      //证书的主类型，目前有4种，1、2、3为VOD,4为直播和时移
	char  CpID[5];			//CPID号,5个字节	
	DWORD ContentTypeID;    //内容类型ID号 
	DWORD ContentId;        //内容ID
	char  UserID[16];		    //用户ID号，4个字节
	DWORD SubTypeID;	    //证书子类型
	DWORD ControlWordId;	//密钥的ID号
	//返回证书XML格式中的元素
	DWORD ControlWord;		//具体密钥
	char  CreateTime[20];       //密钥的具体创建时间  
	char AuthenticateResult[6]; //认证是否成功
	char DescID[6];             //错误描述
	char *DescContent;          //错误信息的描述内容
public:
	
	//获取认证结果
	BOOL GetAuthenticateResult()
	{
		if(strcmp(AuthenticateResult,"true"))
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	//获取证书开始时间
	char *GetStartTime()
	{
		return this->StartTime;
	};
	//获取结束时间
	char *GetExpiration()
	{
		return this->Expiration;
	};
	//获取证书使用的次数
	DWORD GetAmount()
	{
		return this->Amount;
	};
	//获取证书的单位
	char *GetUnit()
	{	
		return this->Unit;
	};
	//获取证书的ID号
	char *GetCertificateID()
	{
		return this->CertificateID;
	};
	//获取证书的主类
	DWORD GetMajorTypeId()
	{
		return this->MajorTypeId;
	};
	//获取证书的CPID
	char *GetCpID()
	{
		return this->CpID;
	};
	//获取内容类型ID号
	DWORD GetContentTypeID()
	{
		return this->ContentTypeID;
	};
	//获取内容ID号
	DWORD GetContentId()
	{
		return this->ContentId;
	};
	//获取用户ID号
	char* GetUserID()
	{
		return this->UserID;
	};	
	//获取证书子类型
	DWORD GetSubTypeID()
	{
		return this->SubTypeID;
	};
	//获取密钥的ID号
	DWORD GetControlWordId()
	{
		return this->ControlWordId;
	};
	//获取密钥字
	DWORD GetControlWord()
	{
		return this->ControlWord;
	};
	//获取密钥的创建时间
	char *GetCreateTime()
	{
		return this->CreateTime;
	};
	//获取证书错误的描述ID号
	char *GetDescID()
	{
		return this->DescID;
	};
	//获取证书错误的描述内容
	char *GetDescContent()
	{
		return this->DescContent;
	};
	
	//判断证书是否需要存储
	BOOL IsNeedSave()
	{
		if(this->MajorTypeId==BYTIMEDURATION||
		   this->MajorTypeId==BYDATETIME||
		   this->MajorTypeId==BYCOUNT)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	char* ReadValue(char *val, unsigned int len,const char *value);
	int StartDocument() ; 
	int EndDocument() ; 
	int StartElement(const char *element) ;
	int EndElement() ;
	int OnProperty(const char* element, const char* name, const char*value) ; 
	int OnError(const char* element, const char* name, const char*value);
	CCertificateParserHelper();
	virtual ~CCertificateParserHelper();

};

#endif // !defined(AFX_CERTIFICATEPARSERHELPER_H__55BE1AA3_FD3B_469E_BAFB_0F57AD9E2170__INCLUDED_)
