// listProcess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <psapi.h>

#pragma comment(lib,"psapi")

#define MAX_COMMAND_LINE	1024

struct _INFO_BLOCK
{
    DWORD   dwFiller[16];
    WORD    wLength;
    WORD    wMaxLength;
    DWORD   dwCmdLineAddress;
} Block;

struct _PEB { DWORD dwFiller[4]; DWORD dwInfoBlockAddress; } PEB; 

static int KillProcess(int processId)
{
	HANDLE hProcess;
	// Get the actual priority class.
	hProcess = OpenProcess (PROCESS_ALL_ACCESS,
		FALSE,
		processId);
	if(hProcess){
		::TerminateProcess(hProcess,0);
		CloseHandle(hProcess);
		return 0;
	}else{
		return 1;
	}
}

#define PROCESS_DATA_BLOCK_ADDRESS      (LPVOID)0x00020498
// align pointer
#define ALIGNMENT(x) ( (x & 0xFFFFFFFC) ? (x & 0xFFFFFFFC) + sizeof(DWORD) : x )

BOOL GetCommandLine (HANDLE hProcess, LPWSTR lpszCmdLine)
{
	LPBYTE lpBuffer = NULL;
	LPBYTE lpPosition = NULL; 
	DWORD dwBytesRead;
	MEMORY_BASIC_INFORMATION mbi;
	SYSTEM_INFO sysinfo;
	
	GetSystemInfo (&sysinfo);
	lpBuffer = (LPBYTE)malloc (sysinfo.dwPageSize);
	if ( lpBuffer == NULL )
		return FALSE;
	if ( VirtualQueryEx (hProcess, PROCESS_DATA_BLOCK_ADDRESS, &mbi, sizeof(mbi) ) == 0)
		return FALSE;
	if (!ReadProcessMemory ( hProcess, mbi.BaseAddress, (LPVOID)lpBuffer, 
		sysinfo.dwPageSize, &dwBytesRead))
		return FALSE;
	lpPosition = lpBuffer + ((DWORD)PROCESS_DATA_BLOCK_ADDRESS - (DWORD)mbi.BaseAddress);
	lpPosition = lpPosition + (wcslen ((LPWSTR)lpPosition) + 1) * sizeof(WCHAR);
	lpPosition = (LPBYTE)ALIGNMENT((DWORD)lpPosition);
	lpPosition = lpPosition + (wcslen ((LPWSTR)lpPosition) + 1) * sizeof(WCHAR);
	if ( *lpPosition == '\0' ) lpPosition += sizeof(WCHAR);
	wcsncpy  ( lpszCmdLine, (LPWSTR)lpPosition, MAX_COMMAND_LINE );
	lpszCmdLine[MAX_COMMAND_LINE-1] = L'\0';
	if (lpBuffer != NULL) free(lpBuffer);
	return TRUE;
}



void PrintProcessCommandLine(DWORD processID)
{
	
	
	DWORD dwSize;
	HANDLE process =  OpenProcess( PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID );
	if(process==(void*)-1){
		printf("error open process %u\n",processID);
		return;
	}
	if(!ReadProcessMemory(process, (_PEB *) 0x7ffdf000, &PEB, sizeof(PEB), &dwSize))		
	{
		//printf("error ReadProcessMemory %u\n",processID);
		CloseHandle( process );
		return;	
		
	}
	
	if(!ReadProcessMemory(process, (void *) PEB.dwInfoBlockAddress, 
		&Block, sizeof(Block), &dwSize))
	{
		//printf("error ReadProcessMemory  dwInfoBlockAddress %u\n",processID);
		
		CloseHandle( process );
		return ;
	}
	
	TCHAR *pszCmdLine = new TCHAR[Block.wMaxLength];					
	ReadProcessMemory(process, (LPVOID) Block.dwCmdLineAddress, 
		pszCmdLine, Block.wMaxLength, &dwSize);
	wprintf(L"%6u %s\n",processID,pszCmdLine);
	CloseHandle( process );
	
}
BOOL EnableTokenPrivilege (LPTSTR privilege)
{
	HANDLE hToken;                        
	TOKEN_PRIVILEGES token_privileges;                  
	DWORD dwSize;                        
	ZeroMemory (&token_privileges, sizeof (token_privileges));
	token_privileges.PrivilegeCount = 1;
	if ( !OpenProcessToken (GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
		return FALSE;
	if (!LookupPrivilegeValue ( NULL, privilege, &token_privileges.Privileges[0].Luid))
	{ 
		CloseHandle (hToken);
		return FALSE;
	}
	
	token_privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	if (!AdjustTokenPrivileges ( hToken, FALSE, &token_privileges, 0, NULL, &dwSize))
	{ 
		CloseHandle (hToken);
		return FALSE;
	}
	CloseHandle (hToken);
	return TRUE;
}



void KillProcessByName( DWORD processID, const char *procName )
{
    char szProcessName[MAX_PATH] = "unknown";
    HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID );
	
	if (NULL == hProcess ){
		return;
	}
	
	
	HMODULE hMod;
	DWORD cbNeeded;
	
	if ( !EnumProcessModules( hProcess, &hMod, sizeof(hMod), &cbNeeded) )
	{
		CloseHandle( hProcess );   
		return;	
	}
    GetModuleBaseName( hProcess,hMod, szProcessName,sizeof(szProcessName));	
    
	if(!_strnicmp(procName,szProcessName,strlen(procName)+1)==0){
		CloseHandle( hProcess );
	}
	if(KillProcess(processID)!=0){
		
		CloseHandle( hProcess );
	}
	printf( "killed: pid = %6u name = %s\n",processID,szProcessName);
    CloseHandle( hProcess );
}

int main(int argc,char *argv[])
{
    // Get the list of process identifiers.
	
	printf("ps tool built at %s\n\n",__DATE__);
	if ( !EnableTokenPrivilege (SE_DEBUG_NAME) )
	{
		printf ( "Cannot get required privilege %lu\n", GetLastError () );
		return 0;
	}
	
    DWORD aProcesses[1024], cbNeeded, cProcesses;
	
    if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) )
        return 1;
	
    // Calculate how many process identifiers were returned.
	
    cProcesses = cbNeeded / sizeof(DWORD);
	
    // Print the name and process identifier for each process.
	WCHAR      CommandLine[MAX_COMMAND_LINE] = {0};
	
    for (int i = 0; i < cProcesses; i++ )
	{	
		DWORD pid=aProcesses[i] ;
		HANDLE process =  OpenProcess( PROCESS_QUERY_INFORMATION |
			PROCESS_VM_READ,
			FALSE,pid );
		if(process==(void*)-1){
			printf("error open process %6u\n",pid );
			continue;
		}
		if ( !GetCommandLine ( process, CommandLine ) )
		{
			wprintf (L"%6u EORR_CODE=%lu\n", pid,GetLastError ());
			CloseHandle(process);
			continue;
		}
		if(wcslen(CommandLine)<8){
			wprintf (L"%6u %s\n", pid,"<empty>");
			CloseHandle(process);
			continue;
		}
		wprintf (L"%6u %s\n", pid,CommandLine);
		CloseHandle(process);
		
		
		//PrintProcessCommandLine(aProcesses[i]);		
	}
	
	return 0;
	//PrintProcessNameAndID( aProcesses[i] );
}
