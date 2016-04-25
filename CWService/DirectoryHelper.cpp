// DirectoryHelper.cpp: implementation of the CDirectoryHelper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DirectoryHelper.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDirectoryHelper::CDirectoryHelper()
{
	
}

CDirectoryHelper::~CDirectoryHelper()
{
	
}

void CDirectoryHelper::ListFiles(const WCHAR* wildcard)
{
	//call me like this  
	WIN32_FIND_DATA findFileData = {0};
	
	HANDLE handle = ::FindFirstFile(wildcard,&findFileData);
	if(NULL != handle && INVALID_HANDLE_VALUE != handle){
		if(IsFile(findFileData)) printf("fileName: %s\n", findFileData.cFileName);
		//第一个文件
	}else{
		//第一个文件
		return;
	}
	while(FindNextFile( handle, &findFileData )){
		if(IsFile(findFileData)) printf("fileName: %s\n", findFileData.cFileName);
	}

}


//从文件fileName中，读取长度为len的char;读字符串。
char* CDirectoryHelper::ReadTextFile(const WCHAR* fileName,char *text, DWORD *len)
{
	HANDLE saveFile;
	DWORD  readLen = 0;
	saveFile = CreateFile(fileName, 
		GENERIC_READ, FILE_SHARE_READ, NULL, 
		OPEN_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, NULL);
	memset(text,0x00,*len);

	ReadFile(saveFile,text,*len,&readLen,NULL);
	//将字符串的最后一个置为零。
	*(text + readLen)=0;
	*len = readLen;

	CloseHandle(saveFile);	

	return text;
}

BOOL CDirectoryHelper::IsFile(WIN32_FIND_DATA &findFileData)
{
	if(findFileData.cFileName[0]=='.'){
		//本目录
		return FALSE;
	}else if (FILE_ATTRIBUTE_DIRECTORY==(FILE_ATTRIBUTE_DIRECTORY & findFileData.dwFileAttributes)){	
		return FALSE;
	}else{
		return TRUE;
	}
}

BOOL CDirectoryHelper::DeleteFile(const WCHAR *fileName)
{
	return ::DeleteFile(fileName);
}

//将长度为为len的text写入到名为fileName中。
DWORD CDirectoryHelper::WriteTextFile(const WCHAR *fileName, char *text, DWORD len)
{
	HANDLE saveFile = NULL;
	saveFile = CreateFile(fileName, 
		GENERIC_WRITE, FILE_SHARE_READ, NULL, 
		OPEN_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD writeLen;
	SetEndOfFile(saveFile);
	WriteFile(saveFile,text,len,&writeLen,NULL);
	CloseHandle(saveFile);
	return writeLen;
}

BOOL CDirectoryHelper::ReadBinaryFile(const WCHAR *fileName, BYTE *recv, DWORD *len)
{
	HANDLE saveFile = NULL;
	DWORD  readLen = 0;
	BOOL ret = FALSE;
	saveFile = CreateFile(fileName, 
		GENERIC_READ, FILE_SHARE_READ, NULL, 
		OPEN_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, NULL);
	memset(recv,0x00,*len);

	ret = ReadFile(saveFile,recv,*len,&readLen,NULL);
	*len = readLen;

	CloseHandle(saveFile);	

	return ret;
}

BOOL CDirectoryHelper::WriteBinaryFile(const WCHAR *fileName, const BYTE *data, DWORD len)
{

	BOOL ret = FALSE;

	HANDLE saveFile = NULL;
	saveFile = CreateFile(fileName, 
		GENERIC_WRITE, FILE_SHARE_READ, NULL, 
		OPEN_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD error = ::GetLastError();
	//wprintf(L"\nwrite '%s'\n",fileName);
	DWORD writeLen;
	SetEndOfFile(saveFile);
	ret  = WriteFile(saveFile,data,len,&writeLen,NULL);
	//printf("write file returns: %d error: %u",ret,error);
	CloseHandle(saveFile);

	return ret;
}

BOOL CDirectoryHelper::Exists(const WCHAR *fileName)
{
	HANDLE saveFile = NULL;
	BOOL exists = FALSE;

	//wprintf(L"\nexists: %s\n",fileName);
	saveFile = CreateFile(fileName, 
		GENERIC_READ, FILE_SHARE_READ, NULL, 
		OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, NULL);
	exists = (saveFile != (void*)-1);
	CloseHandle(saveFile);

	return exists;

}

void CDirectoryHelper::ListFileName(const WCHAR *wildcard, CFileListHandle *pHandle)
{
	WIN32_FIND_DATA findFileData = {0};

	if(NULL==pHandle){
		return;
	}
	pHandle->OnStart();
	HANDLE handle = ::FindFirstFile(wildcard,&findFileData);
	if(NULL != handle && INVALID_HANDLE_VALUE != handle){
		//if(IsFile(findFileData)) printf("fileName: %s\n", findFileData.cFileName);
		
		if(IsFile(findFileData)) pHandle->OnFileName(findFileData.cFileName);
		//第一个文件
	}else{
		//第一个文件
		return;
	}
	while(FindNextFile( handle, &findFileData )){
		if(IsFile(findFileData)) pHandle->OnFileName(findFileData.cFileName);
		//if(IsFile(findFileData)) printf("fileName: %s\n", findFileData.cFileName);
	}
	pHandle->OnEnd();
	
}
