// Parameters.h: interface for the CParameters class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  �ļ�: Parameters.h:	
  ��Ȩ: ��ţ(����)�������޹�˾
  ����: 2005-09-05
  ����: ������Parameter.hʵ��������������Դ��ļ������кͷ����У�
	    ���ڴ洢����
  �ο�: 
  ����: zhangxl@channel.com
  �޶���¼:	

\*===========================================================*/
#if !defined(AFX_PARAMETERS_H__7691EE96_6FE3_400D_88CE_C1102414E998__INCLUDED_)
#define AFX_PARAMETERS_H__7691EE96_6FE3_400D_88CE_C1102414E998__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4786)

#include <map>
#include <string>
#include <windows.h>
#include "Parameter.h"
using namespace std;
struct ltstr
{
	bool operator()(const char* s1, const char* s2) const
	{
		//printf("compare %s %s \n",s1,s2);
		return strcmp(s1, s2) < 0;
	}
};
//�Լ������ڴ�
class CParameters  
{
protected:
	int  ParseExpression(
		const char *str2parse,
		char nameValueSeperator='=',
		char itemSeperator=';');

private:
	map<const char*, CParameter*, ltstr> parameters;

public:
	void Clear();
	void Load(WCHAR *fileName);
	int Save(const WCHAR *fileName);
	void Report();
	char * GetValue(const char *name);
	int Parse(const char* data);
	virtual BOOL AddParameter(const char *name, const char *value);
	CParameters();
	virtual ~CParameters();

};

#endif // !defined(AFX_PARAMETERS_H__7691EE96_6FE3_400D_88CE_C1102414E998__INCLUDED_)
