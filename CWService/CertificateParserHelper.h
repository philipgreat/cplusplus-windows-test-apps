// CertificateParserHelper.h: interface for the CCertificateParserHelper class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  �ļ�: CertificateParserHelper.h	
  ��Ȩ: ��ţ(����)�������޹�˾
  ����: 2005-09-05
  ����: ��XML����Ϊ֤��������, �������ص��ı���������Ҫ��֤��
  �ο�: CGenericSAXParser
  ����: zhangxl@channel.com
  �޶���¼:	

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
	char  StartTime[20];  //֤�鿪ʼʱ��
	char  Expiration[20]; //֤��Ľ���ʱ��
	DWORD Amount;		  //֤���ʹ�ô���
	char  Unit[2];        //֤��ĵ�λ
	//����֤��XML��ʽ�е�����
	char  CertificateID[33];   //֤���ID�ţ���һ��Ψһ��GUID
	DWORD MajorTypeId;      //֤��������ͣ�Ŀǰ��4�֣�1��2��3ΪVOD,4Ϊֱ����ʱ��
	char  CpID[5];			//CPID��,5���ֽ�	
	DWORD ContentTypeID;    //��������ID�� 
	DWORD ContentId;        //����ID
	char  UserID[16];		    //�û�ID�ţ�4���ֽ�
	DWORD SubTypeID;	    //֤��������
	DWORD ControlWordId;	//��Կ��ID��
	//����֤��XML��ʽ�е�Ԫ��
	DWORD ControlWord;		//������Կ
	char  CreateTime[20];       //��Կ�ľ��崴��ʱ��  
	char AuthenticateResult[6]; //��֤�Ƿ�ɹ�
	char DescID[6];             //��������
	char *DescContent;          //������Ϣ����������
public:
	
	//��ȡ��֤���
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
	//��ȡ֤�鿪ʼʱ��
	char *GetStartTime()
	{
		return this->StartTime;
	};
	//��ȡ����ʱ��
	char *GetExpiration()
	{
		return this->Expiration;
	};
	//��ȡ֤��ʹ�õĴ���
	DWORD GetAmount()
	{
		return this->Amount;
	};
	//��ȡ֤��ĵ�λ
	char *GetUnit()
	{	
		return this->Unit;
	};
	//��ȡ֤���ID��
	char *GetCertificateID()
	{
		return this->CertificateID;
	};
	//��ȡ֤�������
	DWORD GetMajorTypeId()
	{
		return this->MajorTypeId;
	};
	//��ȡ֤���CPID
	char *GetCpID()
	{
		return this->CpID;
	};
	//��ȡ��������ID��
	DWORD GetContentTypeID()
	{
		return this->ContentTypeID;
	};
	//��ȡ����ID��
	DWORD GetContentId()
	{
		return this->ContentId;
	};
	//��ȡ�û�ID��
	char* GetUserID()
	{
		return this->UserID;
	};	
	//��ȡ֤��������
	DWORD GetSubTypeID()
	{
		return this->SubTypeID;
	};
	//��ȡ��Կ��ID��
	DWORD GetControlWordId()
	{
		return this->ControlWordId;
	};
	//��ȡ��Կ��
	DWORD GetControlWord()
	{
		return this->ControlWord;
	};
	//��ȡ��Կ�Ĵ���ʱ��
	char *GetCreateTime()
	{
		return this->CreateTime;
	};
	//��ȡ֤����������ID��
	char *GetDescID()
	{
		return this->DescID;
	};
	//��ȡ֤��������������
	char *GetDescContent()
	{
		return this->DescContent;
	};
	
	//�ж�֤���Ƿ���Ҫ�洢
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
