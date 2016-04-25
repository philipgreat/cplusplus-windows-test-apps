// SerializableCertificate.h: interface for the CSerializableCertificate class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  �ļ�: SerializableCertificate.h	
  ��Ȩ: ��ţ(����)�������޹�˾
  ����: 2005-09-05
  ����: ʹ��һ��֤���ʱ�򣬱����Ƚ����Ự�� �����Ự���Ի����Կ���ڻ�
	    ��������ʱ�򣬽����������, ����֤���ҵ���൱���ӣ�������θ���
  �ο�: CDirectoryHelper , CJavaScriptGenerator
  ����: zhangxl@channel.com
  �޶���¼:	

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
	//�ṹ��ķ���ʹ��Сд
	DWORD absolute();
	int  diff(ISOTIME &tm);
	//����Ƿ��ڵ�ǰ����֮�󣬴�ISOTIME�Ƿ��ѹ��ڡ�
	BOOL expired();
	BOOL before(ISOTIME &isotime);
	//��һ���ַ����г�ʼ��
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
	char  StartTime[20];  //֤�鿪ʼʱ��
	char  Expiration[20]; //֤��Ľ���ʱ��
	DWORD Amount;		  //֤���ʹ�ô���
	char  Unit[2];        //֤��ĵ�λ
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

	//�û�ʹ�õĴ��������ڼ�¼�û����õ���Ϣ
	DWORD usedCount;
	//�û�ʹ�õ����������ڼ�¼�û����õ���Ϣ
	DWORD usedSecond;
	
	//�ڲ�ʱ��ʹ���������㣬����ܹ���ʾ 2 ^ 32 / 86400 = 49710.20 ���֤�� (136��) 
	//�������ʱ�������� ;)

	//this is an enumeration value, now, this class supports 
	//three types of policy
	CONTROL_POLICY_ARG policyArgument1;
	CONTROL_POLICY_ARG policyArgument2;

public:
	//���ػ���ķ���
	DWORD GetControlWord();
	//���ػ��෽��
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
	//��ʼ����ɣ�����֤���ʱ�򣬱�����¼���һ��֤���ʹ�ô���
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
ÿ��֤��Ĵ洢�ռ�Ҫ��Ϊ 108 BYTES
*/


//2005-01-20lifg����
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
