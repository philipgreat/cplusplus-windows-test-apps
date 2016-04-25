// STBConfiguration.cpp: implementation of the CSTBConfiguration class.
//
//////////////////////////////////////////////////////////////////////

#include "STBConfiguration.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#ifdef _WIN32_WCE
#define INI_FILE	(L"\\hard disk\\settopbox\\stbapplication.ini")
#else
#define INI_FILE	(L"d:\\settopbox\\stbapplication.ini")
#endif
//#define INI_FILE	(L"\\storage card\\stbapplication.ini")
//stbapplication.ini

CSTBConfiguration::CSTBConfiguration()
{
	templistCount=0;
	this->Load();	
}

CSTBConfiguration::~CSTBConfiguration()
{
	this->Save();
}

int CSTBConfiguration::Load()
{
	//params.Clear();
	params.Load(INI_FILE);
	
	return 0;
}

int CSTBConfiguration::Save()
{
	params.Save(INI_FILE);
	return 0;
}

char* CSTBConfiguration::GetValue(const char *key)
{
	
	return params.GetValue(key);
}

char* CSTBConfiguration::GetCWProviderURL()
{
	return this->GetValue("CWService.ProviderURL");
}

void CSTBConfiguration::Report()
{
	params.Report();
}


int CSTBConfiguration::Parse(const char *data)
{	
	return params.Parse(data);
}

int CSTBConfiguration::SetValue(const char *key, const char *value)
{
	return params.AddParameter(key,value);
}

char* CSTBConfiguration::GetUsername()
{
	return this->GetValue("User.Name");
}

char* CSTBConfiguration::GetPassword()
{
	return this->GetValue("User.Pass");
}

void CSTBConfiguration::SaveLastViewed(const char *url)
{
	this->SetValue("User.LastView",url);
}

char* CSTBConfiguration::GetLastViewURL()
{
	return this->GetValue("User.LastView");
}

char* CSTBConfiguration::GetHomePage() 
{
	return this->GetValue("User.HomePage");
}

char* CSTBConfiguration::GetCWServiceProviderURL()
{
	return this->GetValue("CWService.ProviderURL");
}
#if 0
	CWService.BackProviderURL = http://10.130.100.149/epg/cwservice.aspx
	CWService.ProviderURL = http://10.130.100.149/epg/cwservice.aspx
	CWService.StorePath = \hard disk\cwstore
	DigitalTV = null
	EPG.InternetEntry = http://www.google.com
	EPG.LoginURL = http://10.130.100.149/epg/cwservice.aspx
	Player = null
	UpgradeServer.HostName = 10.130.100.149
	User.HomePage = http://10.130.200.146/urllist.html
	User.LastView = ligang
	User.Name = ligang
	User.Pass = ligang
	User.XXX = male
	User.YYY = male
#endif