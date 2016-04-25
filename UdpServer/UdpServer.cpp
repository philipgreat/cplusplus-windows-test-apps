// UdpServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* timeudpsrv.c
Iterative UDP server for TIME service (RFC868)
Example codes for COMP2650, modified from Comer'server_socket code.
To complie: >cl timeudpsrv.c ws2_32.lib

  TIME protocol: the time is specified in a 32-bit integer, representing the
  number of seconds since an epoch date Jan. 1, 1900.
  The TIME protocol works as follows:
  S: Listen on port 37.
  U: Send an empty datagram to port 37.
  S: Receive the empty datagram.
  S: Send a datagram containing the time as a 32 bit binary number.
  U: Receive the time datagram.
*/

#ifndef  _WIN32_WCE
#pragma comment(lib,"ws2_32")
#include <Winsock2.h>
#else
#pragma comment(lib,"ws2")
#include <Winsock.h>
#endif
#include <windows.h>
#include <winsock.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "UDPServer1.h"
#include "TestServiceObject.h"
int ReportTime(char *buffer);

#define MAXLINE 4096
#define S_PORT 1800

#define WINEPOCH 2208988800	/* WIndows epoch, in UCT secs */
#include "ServiceRequest.h"


int PreTest(int argc, char **argv);
int SimpleModel(int argc, char **argv);
int TransFile(int argc, char **argv);
int SavePacketInDifferentFile(int argc, char **argv);
int ParseRTPSamples(int argc, char **argv);

void errexit(const char *format, ...)
{
	va_list	args;	
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	WSACleanup();
	exit(1);
}




int main(int argc, char **argv)
{
	
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
		errexit("WSAStartup failed\n");
	//return PreTest(argc,argv);
	return ParseRTPSamples(argc,argv);
	
	//hexTest();
	return 0;
}

int SimpleModel(int argc, char **argv){
	
	WSADATA wsadata;
	
	printf("UDPSERVER Pid = %u Build at %s, %s\n",
		::GetCurrentProcessId(),
		__TIME__,
		__DATE__
		);
	
	
	if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
		errexit("WSAStartup failed\n");
	
	CUDPServer server(16800);
	server.SetServiceHandler(new CTestServiceObject());
	server.Run();
	
	WSACleanup();
	return 0;
	
	
}
#include "FileLogger.h"
#include "rtp.h"
#include "FileReader.h"

int PreTest(int argc, char **argv)
{
	char buffer[MAXLINE];
	CUDPServer server(4220);
	CFileLogger logger("d:\\001.txt");
	server.Bind();
	
	
	while(1)
	{
		int state=0;
		state=server.Recv((BYTE*)buffer,MAXLINE);
		//printf("server.Recv %d\n",state);
		if(state==CUDPServer::UDP_SOCKET_RECV_TIMEOUT){
			printf("recv timeout \n");		
		}else if(state==CUDPServer::UDP_SOCKET_RECV_FATAL){
			printf("recv fail \n");	
			Sleep(1000);
		}else{
			
			//CServiceRequest *req=(CServiceRequest*)buffer;			
			printf("recv len=%d\n",state);
			rtp_hdr_t *p=(rtp_hdr_t *)buffer;
			printf("ts %10u",ntohl(p->ts));
			printf(" pad %01u",p->p);
			printf(" pt %03u",p->pt);
			printf(" mb %01u",p->m);
			printf(" seq %05u",ntohs(p->seq));
			printf(" cc %02u",p->cc);
			printf(" ssrc %10u",p->ssrc);
			if(p->pt==112){
				printf(" cc %10u",ntohl(p->csrc[0]));			
			}
			printf("\n");			
			logger.WriteHex(buffer,state);
		}
		
	}
	server.Close();
	return 0;
	
}

int SavePacketInDifferentFile(int argc, char **argv)
{
	char buffer[MAXLINE];
	CUDPServer server(4220);
	
	server.Bind();
	char filename[1024];
	int counter=0;
	while(1)
	{
		int state=0;
		state=server.Recv((BYTE*)buffer,MAXLINE);
		//printf("server.Recv %d\n",state);
		if(state==CUDPServer::UDP_SOCKET_RECV_TIMEOUT){
			printf("recv timeout \n");		
		}else if(state==CUDPServer::UDP_SOCKET_RECV_FATAL){
			printf("recv fail \n");	
			Sleep(1000);
		}else{
			
			//CServiceRequest *req=(CServiceRequest*)buffer;			
			printf("recv len=%d\n",state);
			rtp_hdr_t *p=(rtp_hdr_t *)buffer;
			printf("ts %10u",ntohl(p->ts));
			printf(" pad %01u",p->p);
			printf(" pt %03u",p->pt);
			printf(" mb %01u",p->m);
			printf(" seq %05u",ntohs(p->seq));
			printf(" cc %02u",p->cc);
			printf(" ssrc %10u",p->ssrc);
			if(p->pt==112){
				printf(" cc %10u",ntohl(p->csrc[0]));			
			}
			printf("\n");
			sprintf(filename,"f:\\stream_samples\\A%08d.data",counter);
			CFileLogger logger(filename);
			//logger.WriteHex(buffer,state);
			logger.WriteFile(buffer,state);
			counter++;
			//ReportTime(buffer);
			//server.Send((BYTE*)buffer,strlen(buffer)+1);
			
		}
		
	}
	server.Close();
	return 0;
	
}
int ReportTime(char *buffer)
{
	
	DWORD tid=::GetCurrentThreadId();
	SYSTEMTIME systime;
	::GetLocalTime(&systime);
	sprintf(buffer,
		"Run : id=%.5d  @ %.2d:%.2d:%.2d.%.3d\r\n",
		tid,
		systime.wHour,
		systime.wMinute,
		systime.wSecond,
		systime.wMilliseconds
		);
	return 0;
	
}
int TransFile(int argc, char **argv)
{
	
	CFileLogger logger("d:\\002.txt");
	CFileReader reader("D:\\resin-2.1.16\\doc\\blank.wmv");
	
	char buffer[1024];
	for(int i=0;i<4*1024;i++)
	{
		reader.ReadFile(buffer,1024);
		logger.WriteHex(buffer,1024);
	}
	
	return 0;
}


typedef  struct {
	unsigned char errorCorrectionDataLength:4;
	unsigned char opaqueDataPresent:1;
	unsigned char errorCorrectionLengthType:2;
	unsigned char errorCorrectionPresent:1;

}ASFErrorCorrectionFlags;


typedef  struct {
	unsigned char isMultiPayload:1;
	unsigned char sequenceType:2;
	unsigned char paddingLengthType:2;
	unsigned char packetLengthType:2;
	unsigned char isErrorCorrectionPresent:1;
	unsigned char replicatedDataLengthType:2;
	unsigned char offsetIntoMediaObjectLengthType:2;
	unsigned char mediaObjectNumberLengthType:2;
	unsigned char streamNumberLengthType:2;
}ASFParseInfo;


typedef  struct {
	unsigned int packetLength;
	unsigned int sequenceNumber;
	unsigned int paddingLength;
	unsigned int sendTime;
	unsigned int duration;
	unsigned int payloadCount; //if multipayload flag is present
	unsigned int payloadLengthType;//if multipayload flag is present
}ASFPacketInfo;


#include "rtpparser.h"
/*

Packet Length	BYTE, WORD or DWORD	0, 8, 16, 32
Sequence	BYTE, WORD or DWORD	0, 8, 16, 32
Padding Length	BYTE, WORD or DWORD	0, 8, 16, 32
Send Time	DWORD	32
Duration	WORD	16
*/
static void printASFErrorCorrectionInfo(ASFErrorCorrectionFlags *p)
{
	printf("\nstart error correction================\n");
	printf("%32s: %u\n","errorCorrectionDataLength",p->errorCorrectionDataLength);
	printf("%32s: %u\n","opaqueDataPresent",p->opaqueDataPresent);
	printf("%32s: %u\n","errorCorrectionLengthType",p->errorCorrectionLengthType );
	printf("%32s: %u\n","errorCorrectionPresent",p->errorCorrectionPresent);
}
static void retrieveASFPacketInfo(ASFParseInfo *p, ASFPacketInfo *pInfo)
{
	unsigned char *pt=(unsigned char *)p;
	unsigned char  streamFlag = 0;
	CRTPParser parser(pt, 1024);
	
	switch(p->packetLengthType){
		case 0:
			pInfo->packetLength = 0; break;
		case 1:
			pInfo->packetLength = parser.readLEByte(); break;
		case 2:
			pInfo->packetLength = parser.readLEWord(); break;
		case 3:
			pInfo->packetLength = parser.readLEDword(); break;
		default: break;
	}

	switch(p->sequenceType){
		case 0:
			pInfo->sequenceNumber = 0 ; break;
		case 1:
			pInfo->sequenceNumber = parser.readLEByte(); break;
		case 2:
			pInfo->sequenceNumber = parser.readLEWord(); break;
		case 3:
			pInfo->sequenceNumber = parser.readLEDword(); break;
		default: break;
	}

	switch(p->paddingLengthType){
		case 0:
			pInfo->paddingLength = 0; break;
		case 1:
			pInfo->paddingLength = parser.readLEByte(); break;
		case 2:
			pInfo->paddingLength = parser.readLEWord(); break;
		case 3:
			pInfo->paddingLength = parser.readLEDword(); break;
		default: break;
	}
	
	pInfo->sendTime = parser.readLEDword();
	pInfo->duration = parser.readLEWord();
	
	streamFlag = parser.readLEByte();
	
	if(p->isMultiPayload){
		pInfo->payloadCount = streamFlag&0x3F;
		pInfo->payloadLengthType = (streamFlag&0xC0)>>6;
	}
}

static void printASFParseInfo(ASFParseInfo *p)
{
	
	unsigned char *pt=(unsigned char *)p;
	unsigned char  streamFlag = 0;
	CRTPParser parser(pt, 1024);

	printf("\nstart asf================\n");
	printf("%32s: %u\n","isMultiPayload",p->isMultiPayload);
	printf("%32s: %u\n","sequenceType",p->sequenceType);
	printf("%32s: %u\n","paddingLengthType",p->paddingLengthType );
	printf("%32s: %u\n","packetLengthType",p->packetLengthType);
	printf("%32s: %u\n","isErrorCorrectionPresent",p->isErrorCorrectionPresent);
	printf("%32s: %u\n","replicatedDataLengthType",p->replicatedDataLengthType);
	printf("%32s: %u\n","offsetIntoMediaObjectLengthType",p->offsetIntoMediaObjectLengthType );
	printf("%32s: %u\n","mediaObjectNumberLengthType",p->mediaObjectNumberLengthType );
	printf("%32s: %u\n","streamNumberLengthType",p->streamNumberLengthType);
	
	parser.readLEWord();

	switch(p->packetLengthType){
		case 0:
			printf("%32s\n","no packet info");break;
		case 1:
			printf("%32s: %02X\n","packetlength",parser.readLEByte());break;
		case 2:
			printf("%32s: %04X\n","packetlength",parser.readLEWord());break;
		case 3:
			printf("%32s: %08X\n","packetlength",parser.readLEDword());break;
		default: break;
	}

	switch(p->sequenceType){
		case 0:
			printf("%32s\n","no sequence info");break;
		case 1:
			printf("%32s: %02X\n","sequence ",parser.readLEByte());break;
		case 2:
			printf("%32s: %04X\n","sequence",parser.readLEWord());break;
		case 3:
			printf("%32s: %08X\n","sequence",parser.readLEDword());break;
		default: break;
	}

	switch(p->paddingLengthType){
		case 0:
			printf("%32s\n","no paddingLength info");break;
		case 1:
			printf("%32s: %02X\n","paddingLength",parser.readLEByte());break;
		case 2:
			printf("%32s: %04X\n","paddingLength",parser.readLEWord());break;
		case 3:
			printf("%32s: %08X\n","paddingLength",parser.readLEDword());break;
		default: break;
	}
	
	printf("%32s: %08X\n","send time",parser.readLEDword());
	printf("%32s: %04X\n","duration",parser.readLEWord());

	
	streamFlag = parser.readLEByte();

	if(!p->isMultiPayload){
		printf("%32s: %01X\n","stream number",streamFlag&0x3F);
		printf("%32s: %u\n","isKeyFrame",(streamFlag&0x60)>>6);
	}else{
		printf("%32s: %01X\n","number of payloads",streamFlag&0x3F);
		printf("%32s: %u\n","payload length type",(streamFlag&0xC0)>>6);
	}


}

static void printRTPParseInfo(rtp_hdr_t *p)
{
	
	printf("\nstart rtp================\n");
		printf("ts=%10u",ntohl(p->ts));
		printf(" pad=%01u",p->p);
		printf(" x=%01u",p->x);
		printf(" pt=%03u",p->pt);
		printf(" mb=%01u",p->m);
		printf(" seq=%05u",ntohs(p->seq));
		printf(" cc=%02u",p->cc);
		printf(" ssrc=%10u",p->ssrc);
	
}
int ParseRTPSamples(int argc, char **argv)
{
	
	char filename[1024];
	printf("size of parseinfo is %d\n",sizeof(ASFParseInfo));
	char buffer[1024*4];
	for(int i=0;i<500;i++)
	{
		sprintf(filename,"f:\\stream_samples\\A%08d.data",i);
		CFileReader reader(filename);
		reader.ReadFile(buffer,1024);
		rtp_hdr_t *p=(rtp_hdr_t *)buffer;
		printf("\ncurrent pacaket number is %u",i);
		printRTPParseInfo(p);
		if(p->pt==48){
			ASFErrorCorrectionFlags *perrorFlag = (ASFErrorCorrectionFlags *)(buffer+16);
			printASFErrorCorrectionInfo(perrorFlag);	
			ASFParseInfo *p=(ASFParseInfo *) (buffer+16+3);
			printASFParseInfo(p);
		}
	}
	printf("\n");
	
	return 0;
}