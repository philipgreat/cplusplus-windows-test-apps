// BaseCertificate.h: interface for the CBaseCertificate class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  文件: BaseCertificate.h	
  版权: 青牛(北京)技术有限公司
  日期: 2005-09-05
  描述: 一个描述证书的基本特性的类, 其他证书均从该类继承
  参考: CSerializableCertificate, CVoletileCertificate
  作者: zhangxl@channel.com
  修订记录:	
     2006-01-19号：修改了认证模块 李发根

\*===========================================================*/

#if !defined(AFX_BASECERTIFICATE_H__3C0BD2FC_ED73_4B29_9220_5C6437ED1D2A__INCLUDED_)
#define AFX_BASECERTIFICATE_H__3C0BD2FC_ED73_4B29_9220_5C6437ED1D2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>

enum MajorTypeEnum
{
	BYTIMEDURATION = 1, //通过时长
	BYDATETIME     = 2, //按照日期
	BYCOUNT       =  3,  //按照次数
	VOLATILE       = 4, //临时证书
};


class CBaseCertificate  
{
protected:
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
	//增加的属性
	DWORD updateTime;		  //在上次更新的时间, 单位是微秒
	
protected:

public:
	void SetCertificateID(const char *certificateIDParam)
	{
		int len = strlen(certificateIDParam)+1;
		if(len>33) len=33;    //不可超过最大值。
		memset(CertificateID,0,len);
		memcpy(CertificateID,certificateIDParam,len);
	};
	const char * GetCerficateId()
	{
		return this->CertificateID;
	};
	void SetMajorTypeId(const DWORD MajorTypeIdParam)
	{
		this->MajorTypeId = MajorTypeIdParam;
	};
	DWORD GetMajorTypeId() const
	{
		return this->MajorTypeId;
	};
	void SetCpID(const char *CpIDParam)
	{
		int len = strlen(CpIDParam) +1;
		if(len>5) len=5;
		memset(this->CpID,0,len);
		memcpy(this->CpID,CpID,len);
	};
	const char * GetCpid()
	{
		return this->CpID;
	};
	void SetContentTypeID(const DWORD ContentTypeIDParam)
	{
		this->ContentTypeID = ContentTypeIDParam;
	};
	DWORD GetContentTypeID() const
	{
		return this->ContentTypeID;
	};
	void SetContentId(const DWORD ContentIdParam)
	{
		this->ContentId = ContentIdParam;
	};
	DWORD GetConTentID() const
	{
		return this->ContentId;
	};
	void SetUserID(const char * UserIDParam)
	{
		int len = strlen(UserIDParam) + 1;
		if(len>16) len = 16;
		memset(this->UserID,0,len);
		memcpy(this->UserID,UserIDParam,len);
	};
	const char*  GetUserID()
	{
		return this->UserID;
	};
	void SetSubTypeID(const DWORD SubTypeIDParm)
	{
		this->SubTypeID = SubTypeIDParm;
	};
	DWORD GetSubTypeID() const
	{
		return this->SubTypeID;
	};
	void SetControlWordId(const DWORD ControlWordIdParam)
	{
		this->ControlWordId = ControlWordIdParam;
	};
	DWORD GetControlWordId() const
	{
		return this->ControlWordId;
	};
	void  SetControlWord(const DWORD ControlWordParam)
	{
		this->ControlWord = ControlWordParam;
	};
	void SetCreateTime(const char *CreateTimeParam)
	{
		int len = strlen(CreateTimeParam)+1;
		if(len>20) len=20;
		memset(CreateTime,0,len);
		memcpy(CreateTime,CreateTimeParam,len);
	};
	const char *GetCreateTime()
	{
		return this->CreateTime;
	};

	
	//获取控制字，对于VOD业务要重新实现
	virtual DWORD GetControlWord();
	//获取原始记录时间与当前时间的相对时间。
	DWORD GetInactiveTime();
	virtual void UpdateState();
	virtual BOOL Teardown();
	//virtual void  AddPlayCount();
	virtual BOOL IsAvaliable();
	virtual void Report() = 0;	
	virtual BOOL Store() = 0;
	virtual BOOL IsNeedStore();
	CBaseCertificate();
	virtual ~CBaseCertificate();
	
};

#endif // !defined(AFX_BASECERTIFICATE_H__3C0BD2FC_ED73_4B29_9220_5C6437ED1D2A__INCLUDED_)
