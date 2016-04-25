// FileLogger.cpp: implementation of the CFileLogger class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FileLogger.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileLogger::CFileLogger(char *fileName)
{
	OpenFile(fileName);
}

CFileLogger::~CFileLogger()
{
	CloseHandle(saveFile);

	saveFile = NULL;
}

BOOL CFileLogger::OpenFile(char *fileName)
{
	BOOL ret = FALSE;

	saveFile = NULL;
	saveFile = CreateFile(fileName, 
		GENERIC_WRITE, FILE_SHARE_READ, NULL, 
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD error = ::GetLastError();
	//wprintf(L"\nwrite '%s'\n",fileName);
	SetEndOfFile(saveFile);

	//printf("write file returns: %d error: %u",ret,error);

	return ret;
}

int CFileLogger::WriteFile(char *buffer, int length)
{
	BOOL ret = FALSE;
	unsigned long acturalLength=0;
	ret  = ::WriteFile(saveFile,buffer,length,&acturalLength,NULL);
	return acturalLength;
}
static void toHex(unsigned char chr, char** buffer)
{

	char hex[]="0123456789ABCDEF";
	unsigned char high = (chr&0X000000F0)>>4;
	unsigned char low  =  chr&0X0000000F;
	(*buffer)[0]=hex[high];
	(*buffer)[1]=hex[low];

}

int CFileLogger::WriteHex(char *buffer, int length)
{
	BOOL ret = FALSE;
	unsigned long acturalLength=0;
	char *pbuffer=buffer;
	int writeLength=length*2 + (length*2 / 32) + 4;

	char *pwriterbuffer=new char[writeLength];
	//the allocated memo
	char *header = pwriterbuffer;
	int totalLength = 0;
	for(int i=0;i<length;i++){
		
		if(i%32==0){		
			*pwriterbuffer=13;
			pwriterbuffer++;
			*pwriterbuffer=10;
			pwriterbuffer++;
			totalLength +=2;
		}

		toHex(*pbuffer,&pwriterbuffer);
		pbuffer++;
		pwriterbuffer++;
		pwriterbuffer++;
		totalLength +=2;

	}

	ret  = ::WriteFile(saveFile,header,totalLength,&acturalLength,NULL);
	
	delete header;

	return acturalLength;
}

int CFileLogger::Log(const char *content)
{
	return this->WriteFile((char *)content,strlen(content));
}
