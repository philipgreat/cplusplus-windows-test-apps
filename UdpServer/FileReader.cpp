// FileReader.cpp: implementation of the CFileReader class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FileReader.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileReader::CFileReader(char *fileName)
{
	OpenFile(fileName);
}

CFileReader::~CFileReader()
{
	CloseHandle(saveFile);
	saveFile = NULL;
}

BOOL CFileReader::OpenFile(char *fileName)
{
	BOOL ret = FALSE;

	saveFile = NULL;
	saveFile = CreateFile(fileName, 
		GENERIC_READ, FILE_SHARE_READ, NULL, 
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD error = ::GetLastError();
	//wprintf(L"\nwrite '%s'\n",fileName);

	//printf("write file returns: %d error: %u",ret,error);

	return ret;
}


static void toHex(unsigned char chr, char** buffer)
{

	char hex[]="0123456789ABCDEF";
	unsigned char high = (chr&0X000000F0)>>4;
	unsigned char low  =  chr&0X0000000F;
	(*buffer)[0]=hex[high];
	(*buffer)[1]=hex[low];

}


int CFileReader::ReadFile(char *buffer, int length)
{
	BOOL ret = FALSE;
	unsigned long acturalLength=0;
	ret  = ::ReadFile(saveFile,buffer,length,&acturalLength,NULL);
	return ret?acturalLength:0;
}
