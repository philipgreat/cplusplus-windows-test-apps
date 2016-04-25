// SocketSession.cpp: implementation of the CSocketSession class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SocketSession.h"
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
			if((*p=='\t'||*p==' '||*p=='\0')&&!hasQuote){

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
CSocketSession::CSocketSession(int sock)
:clientPort(0),isActive(FALSE)
{
	this->socket=sock;			
	this->nameBuffer=new char[1024];
	this->clientAddr=new char[16];
	this->commandLine = new char*[100];

}
CSocketSession::~CSocketSession()
{
	//printf("desconsture\r\n",this->clientAddr);
	delete this->clientAddr;
	delete this->nameBuffer;
	delete this->commandLine;

}

void CSocketSession::Echo(char msg)
{
	send(socket,&msg,1,0);
}

int CSocketSession::SendText(const char *msg)
{
	//first sendto add 2 handles

	return send(socket,msg,strlen(msg)+1,0);
}

#include "ServerContext.h"
int CSocketSession::OnStart()
{
	CServerContext  *pSC = (CServerContext  *)this->GetContext();
	pSC->BroadcastMessage("\r\nuser ");
	pSC->BroadcastMessage(this->ToString());
	pSC->BroadcastMessage(" logged in\r\n>");

	pSC->AddSession(this);
	pSC->Report(this->socket);
	//注册到上下文里面去
	isActive=TRUE;
	return 0;

}

int CSocketSession::OnEnd()
{
	CServerContext  *pSC = (CServerContext  *)this->GetContext();
	pSC->BroadcastMessage("\r\nuser ");
	pSC->BroadcastMessage(this->ToString());
	pSC->BroadcastMessage(" logged out\r\n>");
	//this->SendText("\r\nend\r\n");
	printf("%s:%u end\r\n",this->clientAddr, this->clientPort);
	shutdown(this->socket,1);
	CServerContext *p=static_cast<CServerContext *>(this->GetContext());
	p->Remove(this);
	closesocket(this->socket);
	
	return 0;

}

int CSocketSession::Run()
{
	int ret=0;
	this->SendText(">");
	char msg[1024];
	memset(msg,0,1024);
	int count=0;
	char key;
	int len=0;
	//need to set recv timeout
	
	while((len=recv(this->socket,&key,1,0))>0){
		if(key=='\r'){
			//execute
			int count = ::ParseCommand(msg,this->commandLine,20);
			int ret = ExecuteCommand(count, this->commandLine);
			if(ret==0){
				len=0; 
				break;			
			}
		}else if(key=='\n'){
			break;
		}else if(key==0x08){
			//back space
			if(count>0){
				msg[count--]=0;
				this->Echo('\b');
			}

		}else{
			if (count<1023){
				msg[count]=key;
				this->Echo(key);
			}
			count++;
		}
	}
	return len;

}

#define IS_SAME_STRING(a,b) strncmp((a),(b),strlen(b)+1)==0
#define ARG_IS(b) strncmp((argv[0]),(b),strlen(b)+1)==0

int CSocketSession::ExecuteCommand(int argc,char **argv)
{
	char buffer[1024];
	int ret=1;
	sprintf(buffer,"\r\nexecute cmd %s size=%.2d\r\n",argv[0],strlen(argv[0]));
	//use a com+ object to  execute cmd
	this->SendText(buffer);	

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
	if(ARG_IS("sendmsg")){
		CServerContext  *pSC = (CServerContext  *)this->GetContext();
		pSC->BroadcastMessage(argv[1]);
		pSC->BroadcastMessage("\r\n>");
		//pSC->Report(this->socket);
	}

	return ret;
}

int CSocketSession::ReportTime()
{
	char buffer[1024];

	DWORD tid=::GetCurrentThreadId();
	SYSTEMTIME systime;
	::GetLocalTime(&systime);
	sprintf(buffer,"Run : id=%.5d  @ %.2d:%.2d:%.2d.%.3d\r\n",
			tid,
			systime.wHour,
			systime.wMinute,
			systime.wSecond,
			systime.wMilliseconds
			);
	this->SendText(buffer);
	return 0;
}

CCommonContext * CSocketSession::GetContext()
{
	return this->m_pContext;
}


void CSocketSession::SetConnectInfo(char *ip, int port)
{
	memcpy(this->clientAddr,ip,strlen(ip)+1);
	this->clientPort=port;
}

char* CSocketSession::ToString()
{
	
	sprintf(this->nameBuffer,
		"%s:%d",
		this->clientAddr,
		this->clientPort);

	return this->nameBuffer;
}


BOOL CSocketSession::IsActive()
{
	return this->isActive;
}

