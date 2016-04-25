// listFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "listFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

void MoveFile(char *pPathName)
{
	CFileFind finder;
	char pathName[MAX_PATH],childPath[MAX_PATH];
	BOOL flag;
	CString childDir;

	memset(pathName,0x00,MAX_PATH);
	sprintf(pathName,"%s\\*",pPathName);
	printf("%s\n",pathName);
	flag=finder.FindFile();
	while(flag)
	{
		flag=finder.FindNextFile();
		
		if(finder.IsDots())
			continue;
		memset(childPath,0x00,MAX_PATH);
		childDir=finder.GetFileName();
		
		if(finder.IsDirectory())
		{
			MoveFile(childPath);//递归调用
		}else{
			//操作文件
			printf("%s\\%s\n",pPathName,childDir);
		}
	}
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	
	MoveFile("D:\\settopbox\\*");
	// initialize MFC and print and error on failure
	
	return nRetCode;
}


