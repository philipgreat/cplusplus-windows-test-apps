
#include "TeraPicoLogFile.h"

namespace terapico{

CTeraPicoLogFile::CTeraPicoLogFile()
{
	m_lngOfferSet=0;
}

CTeraPicoLogFile::CTeraPicoLogFile(
		long	id,
		pchar	file_path,
		long	size,
		long	fd,
		pchar	chruck,
		pchar	log_text)
{
#ifdef WIN32
	HANDLE filefd=NULL;
	HANDLE mapfd=NULL;
#else
	long filefd=0;
	long mapfd=0;
#endif

#ifdef WIN32
	filefd=CreateFile(
			file_path,
			GENERIC_WRITE | GENERIC_READ,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			0);

	if(INVALID_HANDLE_VALUE==filefd){
		//that->errid=MMAP_FILE_ERROR;
		printf("\nif(INVALID_HANDLE_VALUE==filefd)");

		goto ERROR_PROC;

	}

	mapfd = CreateFileMapping(filefd,
			NULL,PAGE_READWRITE,
			0,
			(DWORD)size,
			NULL);
	if(NULL==mapfd){
		//that->errid=MMAP_MAPPING_ERROR;
		printf("\nif(NULL==mapfd)");
	}

	chruck=(char *)MapViewOfFile(
			mapfd,
			FILE_MAP_ALL_ACCESS,
			0,
			0,
			0);
	if(NULL==chruck){
		printf("\nif(NULL==mapfd)");
	}
ERROR_PROC:

	CloseHandle(filefd);
#else

	filefd= open(
		file_path,
		O_RDWR);

	if(filefd<0){
		//that->errid=MMAP_FILE_ERROR;
		close(filefd);
		goto ERROR_PROC;
	}

	chruck= mmap(
		0,
		getpagesize(),
		PROT_READ | PROT_WRITE,
		MAP_SHARED,
		fd,
		0);
	if(NULL==chruck){
		//that->errid=MMAP_MAPVIEW_ERROR;
		goto ERROR_PROC;
	}
ERROR_PROC:

#endif

	SetId(id);
	SetFilePath(file_path);
	SetSize(size);
	SetFd(fd);
	SetChruck(chruck);
	SetLogText(log_text);
	m_lngOfferSet=0;


}


CTeraPicoLogFile::~CTeraPicoLogFile()
{

}

bool CTeraPicoLogFile::Reset(
		pchar	file_path,
		long	size,
		long	fd,
		pchar	chruck,
		pchar	log_text)
{
	
	SetFilePath(file_path);
	SetSize(size);
	SetFd(fd);
	SetChruck(chruck);
	SetLogText(log_text);
	return true;
}


void  CTeraPicoLogFile::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoLogFile::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoLogFile::SetFilePath(pchar file_path)
{
	this->m_strFilePath=file_path;
}
pchar CTeraPicoLogFile::GetFilePath()
{
	return this->m_strFilePath;
}

void  CTeraPicoLogFile::SetSize(long size)
{
	this->m_lngSize=size;
}
long CTeraPicoLogFile::GetSize()
{
	return this->m_lngSize;
}

void  CTeraPicoLogFile::SetFd(long fd)
{
	this->m_lngFd=fd;
}
long CTeraPicoLogFile::GetFd()
{
	//::SetFileAttributes
	return this->m_lngFd;
}

void  CTeraPicoLogFile::SetChruck(pchar chruck)
{
	this->m_strChruck=chruck;
}
pchar CTeraPicoLogFile::GetChruck()
{
	return this->m_strChruck;
}

void  CTeraPicoLogFile::SetLogText(pchar log_text)
{
	this->m_strLogText=log_text;
}
pchar CTeraPicoLogFile::GetLogText()
{
	return this->m_strLogText;
}


int CTeraPicoLogFile::Logging(pchar logtext)
{
	int len=strlen(logtext);

	if(m_lngOfferSet+len < this->m_lngSize ){
		strncpy(this->m_strChruck + this->m_lngOfferSet,
			logtext,
			len);
		this->m_lngOfferSet+=len;
		return len;
	
	}else{		
		return 0;	
	}
}


int CTeraPicoLogFile::Logging(int i)
{
	int len=sizeof(i);

	if(m_lngOfferSet+len < this->m_lngSize ){
		int *pi=(int*)(this->m_strChruck + this->m_lngOfferSet);
		*pi=i;
		this->m_lngOfferSet+=len;
		return len;
	
	}else{		
		return 0;	
	}
}

}//end of namespace terapico





