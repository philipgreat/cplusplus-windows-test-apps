// ObjectServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include "CommonTask.h"
#include "SocketSession.h"
#include "TCPServer.h"

//msg "live is here" here is

static enum PARSE_STATE{
	INIT = 0, CMD_START, CMD_END, ARG_START, ARG_IN, ARG_END, ARG_NEXT
};
//static 
static int ParseCommand(char *src,char **cmdLine, int max)
{
	int state = INIT;
	char *p=src;
	int argc = 0;
	BOOL hasQuote = FALSE;
	BOOL needForward = TRUE;
	BOOL needQuit = FALSE;
	int len = strlen(src);
	//*cmdLine=p;
	while((p-src)<=len){
		needForward = TRUE;

		switch(state){

		case INIT:
			if(isalnum(*p)||*p=='/'||*p=='\"'){				
				state = ARG_START;
				needForward = FALSE;
			}
			break;

		case ARG_START:
			if(*p=='\"'){
				hasQuote=TRUE;
				*(cmdLine+argc)=(p+1);
				state = ARG_IN;
			}else{
				*(cmdLine+argc)=(p);
				state = ARG_IN;
			}
			break;
		case ARG_IN:
			if(hasQuote&&*p=='\"'){
				*(p) = 0;
				state = ARG_END;
			}
			if((*p=='\t'||*p==' ')&&!hasQuote){

				*(p) = 0;
				needForward = FALSE;
				state = ARG_END;				
			}

			break;
		case ARG_END:
			++argc;
			//printf("state = %d end %d \n",state, argc);
			state = ARG_NEXT;
			break;
		case ARG_NEXT:
			if(isalnum(*p)||*p=='/'||*p=='\"'){				
				state = ARG_START;
				needForward = FALSE;			
			}			
			break;
		}
		//printf("%02d argc=%02d %s\n",state, argc, p);

		if(needForward) p++;
		if(needQuit) break;
	}
	return argc;

}

#define PARSESTRING   "love \"i s\" \"b lue\""
int testParseCommand()
{

	char **cmdLine;
	cmdLine = new char*[100];
	char *p=new char[200];
	memcpy(p,PARSESTRING,strlen(PARSESTRING)+1);
	int count=::ParseCommand(p,cmdLine,2);

	for(int i=0;i<count;i++){
		printf("index = %d arg = %s\n",i, *(cmdLine+i));		
	}

	delete []cmdLine;
	delete []p;
	return 0;

}

int main(int argc, char* argv[])
{

	CTCPServer server(9090);
	server.Run();
	return 0;
}


#if 0
int firstmain(int argc, char* argv[])
{

	CTimeReportTask *pTask=new CTimeReportTask();


	HANDLE handleList[10];
	DWORD count=1;
	for(DWORD i=0;i<count;i++){
		CTimeReportTask *pTask=new CTimeReportTask();
		HANDLE handle=CTCPServer::RunTask(pTask);
		handleList[i]=handle;
	}
	while(1){
		char str[1024];
		printf("suddy@pentagen.mil >");
		scanf("%s\n",str);
		printf("Executing %s\n",str);
		if(strncmp("exit",str,strlen("exit")+1)==0){
			break;
		}

	}
	::WaitForMultipleObjects(count,handleList,TRUE,INFINITE);
	delete pTask;

	return 0;
}

#endif