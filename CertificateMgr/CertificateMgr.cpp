// CertificateMgr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CertificateManagerTestCase.h"
#define ASSERTOK(x)  if(memcmp(retval=(x),"ok",3)!=0) \
    {printf("Assert failed in ");printf(TEXT(#x)); printf("\tmsg = %s\n",retval);  }
#define ASSERTTRUE(x)  if(!(x)) \
    {printf("Assert failed in ");printf(TEXT(#x)); printf("\tmsg = FALSE\n");  }
#define ASSERTEQUAL(func,value)  if(!(func)) \
    {printf("Assert failed in ");printf(TEXT(#func)); printf("\tmsg = %s\n",retval);  }
#include <winsock.h>
void testCertMgr()
{
	char *retval;
	CCertificateManagerTestCase testCase;
	testCase.setup();
	ASSERTOK(testCase.testAddTask(103));
	ASSERTOK(testCase.testAddTask(103));
	ASSERTOK(testCase.testAddTask(104));
	ASSERTOK(testCase.testAddTask(105));
	ASSERTOK(testCase.testAddTask(106));
	//testCase.testDownloadCertificate();
	ASSERTOK(testCase.testProcess());
	ASSERTOK(testCase.testGetCWById(103));

	ASSERTOK(testCase.testProcess());
	ASSERTOK(testCase.testProcess());
	ASSERTOK(testCase.testProcess());
	ASSERTOK(testCase.testProcess());

	testCase.teardown();

}


static void SetupNetEnv()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	BOOL stateWrite=FALSE;
	/*=======================================================================*/

	wVersionRequested = MAKEWORD( 2, 2 );
	err = WSAStartup( wVersionRequested, &wsaData );

}
static void UnInstallNetEnv()
{
	::WSACleanup();
}



int main(int argc, char* argv[])
{
	//printf("Hello World!\n");
	SetupNetEnv();
	testCertMgr();
	return 0;
}

