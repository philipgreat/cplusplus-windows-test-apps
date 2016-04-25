
#ifndef  TERA_PICO_WAP_GATE_SERVICE_ClASS
#define  TERA_PICO_WAP_GATE_SERVICE_ClASS
#include "TeraPicoCommon.h"

#include "TeraPicoLogFile.h"
	
namespace terapico{

class CTeraPicoWapGateService
{
private:
	
	long	m_lngId;
	pchar	m_strServiceName;
	long	m_lngStartTime;
	pLogFile	m_objLogFile;
	
	
public:

	CTeraPicoWapGateService();
	CTeraPicoWapGateService(
		long	id,
		pchar	service_name,
		long	start_time,
		pLogFile	log_file);
	virtual ~CTeraPicoWapGateService();

	bool Reset(
		pchar	service_name,
		long	start_time,
		pLogFile	log_file);
	
	long GetId();
	void SetId(long id);
	
	pchar GetServiceName();
	void SetServiceName(pchar service_name);
	
	long GetStartTime();
	void SetStartTime(long start_time);
	
	pLogFile GetLogFile();
	void SetLogFile(pLogFile log_file);
	

};//end of  class CTeraPicoWapGateService

typedef CTeraPicoWapGateService* pWapGateService;
typedef CTeraPicoWapGateService WapGateService;

}//end of namespace terapico

#endif //TERA_PICO_WAP_GATE_SERVICE_ClASS


