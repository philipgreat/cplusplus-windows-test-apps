// TeraPicoRegKey.cpp: implementation of the CTeraPicoRegKey class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TeraPicoRegKey.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//##ModelId=4095FA7B010A
CTeraPicoRegKey::CTeraPicoRegKey()
{
	
}

//##ModelId=4095FA7B010B
CTeraPicoRegKey::~CTeraPicoRegKey()
{

}

//##ModelId=4095FA7B00FA
bool CTeraPicoRegKey::SetValue(char *key, char *name, char *value)
{
	
	CRegKey m_RegKey;
	if(m_RegKey.Open(HKEY_LOCAL_MACHINE,key)!=ERROR_SUCCESS)
	{
		m_RegKey.Create(HKEY_LOCAL_MACHINE,key);
	}
	//m_RegKey.SetKeyValue("name","suddy","kiss");
	m_RegKey.SetValue (value,name);
	m_RegKey.Close();
	return true;
}

//##ModelId=4095FA7B00DD
bool CTeraPicoRegKey::SetValue(char *key, char *name, int value)
{
	char pv[TERAPICO_KEY_LENGTH]={0};
	sprintf(pv,"%d",value);
	return SetValue (key,name,pv);


}

//##ModelId=4095FA7B00CD
bool CTeraPicoRegKey::SetValue(char *key, char *name, long value)
{
	char pv[TERAPICO_KEY_LENGTH]={0};
	sprintf(pv,"%u",value);
	return SetValue (key,name,pv);
}

//##ModelId=4095FA7B00BB
bool CTeraPicoRegKey::SetValue(char *key, char *name, double value)
{
	char pv[TERAPICO_KEY_LENGTH]={0};
	sprintf(pv,"%f",value);
	return SetValue (key,name,pv);
}

//##ModelId=4095FA7B00A0
bool CTeraPicoRegKey::SetValue(char *key, char *name, float value)
{
	char pv[TERAPICO_KEY_LENGTH]={0};
	sprintf(pv,"%f",value);
	return SetValue (key,name,pv);
}

//##ModelId=4095FA7B008E
bool CTeraPicoRegKey::GetValue(char *key, char *name, int &value)
{
	char pv[TERAPICO_KEY_LENGTH]={0};
	GetValue(key,name,pv);
	value=atoi(pv);
	return true;
}

//##ModelId=4095FA7B007E
bool CTeraPicoRegKey::GetValue(char *key, char *name, long &value)
{
	char pv[TERAPICO_KEY_LENGTH]={0};
	GetValue(key,name,pv);
	value=atol(pv);
	return true;
}

//##ModelId=4095FA7B006D
bool CTeraPicoRegKey::GetValue(char *key, char *name, float &value)
{
	char pv[TERAPICO_KEY_LENGTH]={0};
	GetValue(key,name,pv);
	value=(float)atof(pv);
	return true;
}

//##ModelId=4095FA7B0050
bool CTeraPicoRegKey::GetValue(char *key, char *name, double &value)
{

	char pv[TERAPICO_KEY_LENGTH];
	GetValue(key,name,pv);
	value=atof(pv);
	return true;	
}

//##ModelId=4095FA7B003E
bool CTeraPicoRegKey::GetValue(char *key, char *name, char value[])
{

	CRegKey m_RegKey;
	if(m_RegKey.Open(HKEY_LOCAL_MACHINE,key)!=ERROR_SUCCESS)
	{
		m_RegKey.Create(HKEY_LOCAL_MACHINE,key);
	}

	char pv[TERAPICO_KEY_LENGTH]={0};
	DWORD size=TERAPICO_KEY_LENGTH;

	m_RegKey.QueryValue(value,name,&size);

	if(value[0]=='\0'){
		SetValue(key,name,"-1");
	}
	m_RegKey.Close();

	//m_RegKey.SetKeyValue("name","suddy","kiss");
	return true;
}
