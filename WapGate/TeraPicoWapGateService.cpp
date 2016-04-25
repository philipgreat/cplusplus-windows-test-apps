
#include "TeraPicoWapGateService.h"
#include "TeraPicoServerSocket.h"
namespace terapico{

CTeraPicoWapGateService::CTeraPicoWapGateService()
{
#ifdef WIN32	
	WINSOCKET_INIT;
	printf("Init Socket!");
#endif

	//这里初始化一个ServerSocket
	ServerSocket *pss=new ServerSocket();


	//getchar();

#ifdef WIN32	
	WINSOCKET_UNINIT;
#endif
}

CTeraPicoWapGateService::CTeraPicoWapGateService(
		long	id,
		pchar	service_name,
		long	start_time,
		pLogFile	log_file)
{

	SetId(id);
	SetServiceName(service_name);
	SetStartTime(start_time);
	SetLogFile(log_file);
}


CTeraPicoWapGateService::~CTeraPicoWapGateService()
{

}

bool CTeraPicoWapGateService::Reset(
		pchar	service_name,
		long	start_time,
		pLogFile	log_file)
{
	
	SetServiceName(service_name);
	SetStartTime(start_time);
	SetLogFile(log_file);
	return true;
}


void  CTeraPicoWapGateService::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoWapGateService::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoWapGateService::SetServiceName(pchar service_name)
{
	this->m_strServiceName=service_name;
}
pchar CTeraPicoWapGateService::GetServiceName()
{
	return this->m_strServiceName;
}

void  CTeraPicoWapGateService::SetStartTime(long start_time)
{
	this->m_lngStartTime=start_time;
}
long CTeraPicoWapGateService::GetStartTime()
{
	return this->m_lngStartTime;
}

void  CTeraPicoWapGateService::SetLogFile(pLogFile log_file)
{
	this->m_objLogFile=log_file;
}
pLogFile CTeraPicoWapGateService::GetLogFile()
{
	return this->m_objLogFile;
}


}//end of namespace terapico


