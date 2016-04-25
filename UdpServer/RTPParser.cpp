// RTPParser.cpp: implementation of the CRTPParser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RTPParser.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
/*

5.2.2	Payload parsing information
If any error correction data is present, payload parsing information follows it. Payload parsing information has the following structure.

Field name	Field type	Size (bits)
	Length Type Flags	BYTE	8
	Multiple Payloads Present		1 (LSB)
	Sequence Type		2
	Padding Length Type		2
	Packet Length Type		2
	Error Correction Present		1
Property Flags	BYTE	8
	Replicated Data Length Type		2 (LSB)
	Offset Into Media Object Length Type		2
	Media Object Number Length Type		2
	Stream Number Length Type		2
Packet Length	BYTE, WORD or DWORD	0, 8, 16, 32
Sequence	BYTE, WORD or DWORD	0, 8, 16, 32
Padding Length	BYTE, WORD or DWORD	0, 8, 16, 32
Send Time	DWORD	32
Duration	WORD	16
*/



CRTPParser::CRTPParser(unsigned char *start,unsigned int length)
{
	//read parsing info
	this->header = start;
	this->bufferlength = length;
	this->currentPosition = this->header;
}

CRTPParser::~CRTPParser()
{
	
}
//all values need to be checked if reached the end of the buffer
unsigned int CRTPParser::readLEByte()
{
	unsigned int  ret = 0;
	unsigned char *value = 0;

	value=this->currentPosition;
	ret=*value;
	this->currentPosition++;
	return  ret;
}

unsigned int CRTPParser::readLEWord()
{
	unsigned int  ret = 0;
	unsigned short *value = NULL;
	value=(unsigned short *)this->currentPosition;
	ret=(unsigned int)*value;
	this->currentPosition+=2;
	return  ret;
}

unsigned int CRTPParser::readLEDword()
{
	unsigned int  ret = 0;
	ret=*((unsigned int *)this->currentPosition);
	this->currentPosition+=4;
	return  ret;
}
