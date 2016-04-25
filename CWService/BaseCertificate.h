// BaseCertificate.h: interface for the CBaseCertificate class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  �ļ�: BaseCertificate.h	
  ��Ȩ: ��ţ(����)�������޹�˾
  ����: 2005-09-05
  ����: һ������֤��Ļ������Ե���, ����֤����Ӹ���̳�
  �ο�: CSerializableCertificate, CVoletileCertificate
  ����: zhangxl@channel.com
  �޶���¼:	
     2006-01-19�ţ��޸�����֤ģ�� ���

\*===========================================================*/

#if !defined(AFX_BASECERTIFICATE_H__3C0BD2FC_ED73_4B29_9220_5C6437ED1D2A__INCLUDED_)
#define AFX_BASECERTIFICATE_H__3C0BD2FC_ED73_4B29_9220_5C6437ED1D2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>

enum MajorTypeEnum
{
	BYTIMEDURATION = 1, //ͨ��ʱ��
	BYDATETIME     = 2, //��������
	BYCOUNT       =  3,  //���մ���
	VOLATILE       = 4, //��ʱ֤��
};


class CBaseCertificate  
{
protected:
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
	//���ӵ�����
	DWORD updateTime;		  //���ϴθ��µ�ʱ��, ��λ��΢��
	
protected:

public:
	void SetCertificateID(const char *certificateIDParam)
	{
		int len = strlen(certificateIDParam)+1;
		if(len>33) len=33;    //���ɳ������ֵ��
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

	
	//��ȡ�����֣�����VODҵ��Ҫ����ʵ��
	virtual DWORD GetControlWord();
	//��ȡԭʼ��¼ʱ���뵱ǰʱ������ʱ�䡣
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
