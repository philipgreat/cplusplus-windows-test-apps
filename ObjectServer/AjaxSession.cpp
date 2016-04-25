// AjaxSession.cpp: implementation of the CAjaxSession class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AjaxSession.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// SocketSession.cpp: implementation of the CAjaxSession class.
//
//////////////////////////////////////////////////////////////////////
#ifndef  _WIN32_WCE
#pragma comment(lib,"ws2_32")
#include <Winsock2.h>
#else
#pragma comment(lib,"ws2")
#include <Winsock.h>
#endif
#include <stdlib.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

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
	int len = strlen(src)+1;
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
			if((*p=='\0'||*p=='\t'||*p==' ')&&!hasQuote){

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

CAjaxSession::CAjaxSession(int sock)
:clientPort(0),isActive(FALSE)
{
	this->socket=sock;			
	this->nameBuffer=new char[1024];
	this->clientAddr=new char[16];
	commandLine = new char*[100];

}
CAjaxSession::~CAjaxSession()
{
	printf("desconsture\r\n",this->clientAddr);
	delete this->clientAddr;
	delete this->nameBuffer;
	delete commandLine;

}

void CAjaxSession::Echo(char msg)
{
	send(socket,&msg,1,0);
}

int CAjaxSession::SendText(const char *msg)
{
	//first sendto add 2 handles

	return send(socket,msg,strlen(msg),0);
}

#include "ServerContext.h"
int CAjaxSession::OnStart()
{
	this->isActive = TRUE;
	return 0;

}

int CAjaxSession::OnEnd()
{
	closesocket(this->socket);
	this->isActive = FALSE;
	return 0;

}
#include "URLParameters.h"
int CAjaxSession::Run()
{
	int len = 0;
	char header[512];
	char *p=header;
	char *strtoparse = 0;

	//HTTP/1.0 GET 
	this->SendText("HTTP/1.0 200 OK\r\n\
Pragma: No-Cache\r\n\
Cache-Control: No-Cache\r\n\
Expires: 0\r\n\
Content-Type: application/x-javascript\r\n\r\n");
	//this->SendText("HTTP/1.0 200 OK\r\nContent-Type: text/plain\r\n\r\n");
	this->Printf("var text='';\r\n");
	if((len = this->Recv(header,512))>0){
		CURLParameters  param;
		header[len] = 0;
		//printf("%s",header);
		while(*p!='?'&&p-header<=len){
			p++;
		}
		p++;
		strtoparse = p;		
		while(*p!=' '&&p-header<=len){
			*p++;		
		}

		*p = 0;
		param.Parse(strtoparse);
		char *cmd = param.GetValue("q");
		if(cmd!=NULL){
			int count = ParseCommand(cmd,this->commandLine,100);
			ExecuteCommand(count,this->commandLine);
			
		}
		//param.Report();
		//printf("%s\n",header);

		
	}
	
	this->Printf("\r\nshowResult('list',text);\r\n");

	return 0;

}

#define IS_SAME_STRING(a,b) strncmp((a),(b),strlen(b)+1)==0
#define ARG_IS(b) strncmp((argv[0]),(b),strlen(b)+1)==0

int CAjaxSession::ExecuteCommand(int argc,char **argv)
{
	int ret=1;


	if(ARG_IS("time")){
		this->ReportTime();
	}
	if(ARG_IS("exit")){
		ret=0;
	}
	if(ARG_IS("reboot")){
		exit(0x11);
	}
	if(ARG_IS("list")){
		CServerContext  *pSC = (CServerContext  *)this->GetContext();
		pSC->Report(this->socket);
	}

	if(ARG_IS("mem")){
		this->ReportMemory();
		//this->printf
	}
	if(ARG_IS("kill")){
		if(argc<2){
			this->Printf("text='use like this: kill <exename>';");	
		}else{
			this->KillProcess(argv[1]);
		}
		//this->printf
	}
	if(ARG_IS("ps")){
		this->ReportProcess();
		//this->printf
	}
	if(ARG_IS("sendmsg")){
		CServerContext  *pSC = (CServerContext  *)this->GetContext();
		pSC->BroadcastMessage(argv[1]);
		pSC->BroadcastMessage("\r\n>");
		//pSC->Report(this->socket);
	}

	return ret;
}

int CAjaxSession::ReportTime()
{
	char buffer[1024];

	DWORD tid=::GetCurrentThreadId();
	SYSTEMTIME systime;
	::GetLocalTime(&systime);
	sprintf(buffer,"var text='Run : id=%010u  @ %.2d:%.2d:%.2d.%.3d';\r\n",
			tid,
			systime.wHour,
			systime.wMinute,
			systime.wSecond,
			systime.wMilliseconds
			);
	this->SendText(buffer);
	return 0;
}

CCommonContext * CAjaxSession::GetContext()
{
	return this->m_pContext;
}


void CAjaxSession::SetConnectInfo(char *ip, int port)
{
	memcpy(this->clientAddr,ip,strlen(ip)+1);
	this->clientPort=port;
}

char* CAjaxSession::ToString()
{
	
	sprintf(this->nameBuffer,
		"%s:%d",
		this->clientAddr,
		this->clientPort);

	return this->nameBuffer;
}


BOOL CAjaxSession::IsActive()
{
	return this->isActive;
}


int CAjaxSession::Recv(char *buffer, int length)
{
	return recv(this->socket,buffer,length,0);
}

int CAjaxSession::Printf(const char *format, ... )
{
	char BUF[1024]; 
	va_list argptr; 
	va_start(argptr,format); 
	vsprintf(BUF,format,argptr); 
	va_end(argptr); 
	return send(socket,BUF,strlen(BUF),0); 

}

#include <windows.h>

#ifdef _WIN32_WCE
#include <Tlhelp32.h>
#pragma comment(lib,"Toolhelp.lib")
#endif

int CAjaxSession::ReportMemory()
{
	this->Printf("text='");

#ifdef _WIN32_WCE
	PROCESSENTRY32 info;
	HANDLE hProcess=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	//printf("handle = %u\n",hProcess);
	info.dwSize = sizeof(PROCESSENTRY32);
	int report=Process32First(hProcess,&info);
	MEMORYSTATUS status;
	GlobalMemoryStatus(&status);
		this->Printf(
			"mem avail: %u mem load: %u%% avail virtual: %u \\r\\n\\\r\ntotal phy: %u total virtual: %u ",
		status.dwAvailPhys/1024,
		status.dwMemoryLoad,
		status.dwAvailVirtual/1024,
		status.dwTotalPhys/1024,
		status.dwTotalVirtual/1024);
	CloseHandle(hProcess);

#endif
	this->Printf("';");

	return 0;
}

BOOL CAjaxSession::ReportProcess()
{
	this->Printf("text='");

#ifdef _WIN32_WCE
	PROCESSENTRY32 info;
	HANDLE hProcess=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	//printf("handle = %u\n",hProcess);
	info.dwSize = sizeof(PROCESSENTRY32);
	int report=Process32First(hProcess,&info);

	this->Printf("%20s%12s%16s\\r\\n\\\r\n",
		"file",
		"threads",
		"membase"
		);
	this->Printf("=================================================\\r\\n\\\r\n");
				

	while(report){
		char charMessage[256];
		//char returnURL[1024];
		wcstombs(charMessage, info.szExeFile, sizeof(charMessage));

		this->Printf("%20s\t\t%08u\t\t0X%8X\\r\\n\\\r\n",
			charMessage,
			info.cntThreads,
			info.th32MemoryBase);
		report=Process32Next(hProcess, &info); 
	}
#endif
	this->Printf("';");
	return TRUE;
}

BOOL CAjaxSession::KillProcess(const char *fileName)
{

	this->Printf("text='");

#ifdef _WIN32_WCE
	PROCESSENTRY32 info;
	HANDLE hProcess=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	//printf("handle = %u\n",hProcess);
	info.dwSize = sizeof(PROCESSENTRY32);
	int report=Process32First(hProcess,&info);

	while(report){
		char charMessage[256];
		//char returnURL[1024];
		wcstombs(charMessage, info.szExeFile, sizeof(charMessage));
		if(strncmp(fileName,charMessage,strlen(fileName))==0)
		{
			HANDLE hP2K = OpenProcess(PROCESS_TERMINATE,0,info.th32ProcessID);
			if(TerminateProcess(hP2K,0x99)){
				this->Printf("kill %s ok",charMessage);
			}else{
				this->Printf("kill %s failed",charMessage);
			}
			CloseHandle(hP2K);

		}
		report=Process32Next(hProcess, &info); 
	}
	CloseHandle(hProcess);
#endif
	this->Printf("';");
	return TRUE;
}
