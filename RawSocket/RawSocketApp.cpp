// RawSocket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RawSocket.h"

static int parseToArray(const char *input, unsigned short *ports,int length,char sep=',')
{
	char msg[1024];	
	int i=0;
	int counter = 1;
	char *p=msg;
	strcpy(msg,input);	
	if(length>0) *ports=0;
	while(*(p)){
		if(*p==sep)
		{
			*(ports+counter)=i+1;
			printf("i=%d\n",i);
			counter++;			
		}
		p++;
		i++;
		printf("%s\n",p);
	}
	p=msg;

	for(int j=0;j<counter;j++)
	{
		//printf("%d,",*(ports+j));
		*(ports+j)=(unsigned short)atoi(msg+(*(ports+j)));		
	}
	return counter;
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

int main(int argc, char* argv[])
{

	if(argc<2){
		printf("please use the tool like this:\n");
		printf("\tsniffer <ipaddr> [pors] [ipaddr]\n");
		printf("\tports like this 80,8080,554\n");
		exit(0);
	}
	
	
	if ( !EnableTokenPrivilege (SE_DEBUG_NAME) )
	{
		printf ( "Cannot get required privilege %lu\n", GetLastError () );
		return 0;
	}



	//unsigned short ports[32];
	//parseToArray("12,23,8080",ports,32);

#if 1 

	CRawSocket *pRaw=NULL;


	pRaw=new CRawSocket();
	if(argc>=3){
		pRaw->SetFilteredPorts(argv[2]);
	}
	pRaw->SetOptions();
	pRaw->SetDestAddress(argv[1]);
	pRaw->SetMixtureMode();
	
	while(1){
		if(!pRaw->Monitor()) break;

	}
	
	delete pRaw;
#endif
	return 0;
}

