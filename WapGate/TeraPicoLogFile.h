
#ifndef  TERA_PICO_LOG_FILE_ClASS
#define  TERA_PICO_LOG_FILE_ClASS
#include "TeraPicoCommon.h"

namespace terapico{

class CTeraPicoLogFile
{
private:
	
	long	m_lngId;
	pchar	m_strFilePath;
	long	m_lngSize;
	long	m_lngFd;
	pchar	m_strChruck;
	pchar	m_strLogText;
	long    m_lngOfferSet;
	
	
public:
	int Logging(int i);
	int Logging(pchar logtext);


	CTeraPicoLogFile();
	CTeraPicoLogFile(
		long	id,
		pchar	file_path,
		long	size,
		long	fd,
		pchar	chruck,
		pchar	log_text);
	virtual ~CTeraPicoLogFile();

	bool Reset(
		pchar	file_path,
		long	size,
		long	fd,
		pchar	chruck,
		pchar	log_text);
	
	long GetId();
	void SetId(long id);
	
	pchar GetFilePath();
	void SetFilePath(pchar file_path);
	
	long GetSize();
	void SetSize(long size);
	
	long GetFd();
	void SetFd(long fd);
	
	pchar GetChruck();
	void SetChruck(pchar chruck);
	
	pchar GetLogText();
	void SetLogText(pchar log_text);
	

};//end of  class CTeraPicoLogFile

typedef CTeraPicoLogFile* pLogFile;
typedef CTeraPicoLogFile LogFile;

}//end of namespace terapico

#endif //TERA_PICO_LOG_FILE_ClASS




