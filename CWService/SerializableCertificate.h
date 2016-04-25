// SerializableCertificate.h: interface for the CSerializableCertificate class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  文件: SerializableCertificate.h	
  版权: 青牛(北京)技术有限公司
  日期: 2005-09-05
  描述: 使用一个证书的时候，必须先建立会话， 建立会话可以获得密钥，在会
	    话结束的时候，进行相关清理, 该类证书的业务相当复杂，经过多次更改
  参考: CDirectoryHelper , CJavaScriptGenerator
  作者: zhangxl@channel.com
  修订记录:	

\*===========================================================*/
#if !defined(AFX_SERIALIZABLECERTIFICATE_H__56656ED2_7ED9_4BEC_A10B_2230269BEA19__INCLUDED_)
#define AFX_SERIALIZABLECERTIFICATE_H__56656ED2_7ED9_4BEC_A10B_2230269BEA19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BaseCertificate.h"
#include "CertificateParserHelper.h"
#include <stdlib.h>



//cplusplus style struct!
struct ISOTIME{
	short	year;
	short	month;
	char	day;
	char	hour;
	char	minute;
	char	second;
public:
	BOOL arrive();
	//结构体的方法使用小写
	DWORD absolute();
	int  diff(ISOTIME &tm);
	//检查是否在当前日期之后，此ISOTIME是否已过期。
	BOOL expired();
	BOOL before(ISOTIME &isotime);
	//从一个字符串中初始化
	void init(const char * timestring);
	int operator- (ISOTIME &isotime);
}; 

union CONTROL_POLICY_ARG    // Declare union type
{
	struct ISOTIME timeArg; //stores time
	char   unit;	//for TimeLength-Unit
	DWORD  count;	//for both PlayCount-Count and TimeLength Value
};  

// Optional declaration of union variable
#include "FileListHandle.h"
class CJavaScriptGenerator : public CFileListHandle
{
public:
	static BOOL  UpdateJavaScript();
	BOOL OnFileName(const WCHAR* fileName);
	void OnEnd();
	void OnStart();
};

class CSerializableCertificate : public CBaseCertificate 
{
protected:
	char  StartTime[20];  //证书开始时间
	char  Expiration[20]; //证书的结束时间
	DWORD Amount;		  //证书的使用次数
	char  Unit[2];        //证书的单位
public:
	void SetStartTime(const char *StartTimeParam)
	{
		int len = strlen(StartTimeParam) + 1;
		if(len>20) len=20;
		memset(StartTime,0,len);
		memcpy(StartTime,StartTimeParam,len);
	};
	const char* GetStartTime()
	{
		return this->StartTime;
	};
	void SetExpiration(const char *ExpirationParam)
	{
		int len = strlen(ExpirationParam) +1;
		if(len>20) len = 20;
		memset(Expiration,0,len);
		memcpy(Expiration,ExpirationParam,len);
	}
	const char* GetExporation()
	{
		return this->Expiration;
	}
	void SetAmount(const DWORD AmountParam)
	{
		this->Amount = AmountParam;
	}
	const DWORD GetAmount()
	{
		return this->Amount;
	}
	void SetUnit(const char *UnitParam)
	{
		int len = strlen(UnitParam) + 1;
		if(len>5) len = 5;
		memset(this->Unit,0,len);
		memcpy(this->Unit,UnitParam,len);
	}
	const char *GetUnit()
	{
		return this->Unit;
	}
private:
	BOOL IsExpired();
	char version[8];

	//用户使用的次数，用于记录用户所用的信息
	DWORD usedCount;
	//用户使用的秒数，用于记录用户所用的信息
	DWORD usedSecond;
	
	//内部时间使用秒来计算，最多能够表示 2 ^ 32 / 86400 = 49710.20 天的证书 (136年) 
	//超过这个时间有问题 ;)

	//this is an enumeration value, now, this class supports 
	//three types of policy
	CONTROL_POLICY_ARG policyArgument1;
	CONTROL_POLICY_ARG policyArgument2;

public:
	//重载基类的方法
	DWORD GetControlWord();
	//重载基类方法
	BOOL IsAvaliable();
	BOOL Teardown();
	BOOL IsNeedDiscard();
	BOOL IsNeedStore();
	void UpdateState();
	char * GenerateJavaScriptObject(char *ret,DWORD len, int index);
	BOOL Discard();
	BOOL FromLocalFile(DWORD contentType,DWORD controlWord);
	static BOOL IsCertExistsOnDisk(DWORD contentType,
									DWORD controlWordId);
	void AddPlayCount();
	//初始化完成，生成证书的时候，必须从新计算一个证书的使用次数
	BOOL FromLocalFile(const WCHAR* fileName);
	BOOL FromSaxHandle(CCertificateParserHelper *handle);
	//this is a heavy method to parse xml file into a certificate!
	void Report();
	BOOL Store();
	//this is really hard to implement
	CSerializableCertificate();
	//CSerializableCertificate(DWORD cwid,DWORD cw);
	virtual ~CSerializableCertificate();
};

#endif // !defined(AFX_SERIALIZABLECERTIFICATE_H__56656ED2_7ED9_4BEC_A10B_2230269BEA19__INCLUDED_)

/*
-------------------------------------------
this							 4
DWORD controlWordId;			 4
DWORD controlWord;				 4
DWORD streamId;					 4
char version[8];				 8
char contentId[16];				16
char contentType[16];			16
char licenseId[16];				16
char userId[16];				16
DWORD policyType;				 4
CONTROL_POLICY_ARG argument1;	 8
CONTROL_POLICY_ARG argument2;	 8
-------------------------------------------
	   							108
								108 - 4 (this pointer) = 104
每个证书的存储空间要求为 108 BYTES
*/


//2005-01-20lifg增加
/*
-------------------------------------------
this							 4

char CertificateID[32]			 32
DWORD MajorType                  4
DWORD subType                    4
DWORD controlWordId;			 4
DWORD controlWord;				 4
char  version[8];				 8
DWORD contentId;				 4
DWORD contentType;			     4
char  userId[16];				 16
CONTROL_POLICY_ARG argument1;	 8
CONTROL_POLICY_ARG argument2;	 8
-------------------------------------------
*/
