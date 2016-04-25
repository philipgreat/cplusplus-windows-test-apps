// BufferWriter.cpp: implementation of the CBufferWriter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BufferWriter.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include <string.h>
#include <stdlib.h>

CBufferWriter::CBufferWriter(char *buffer,unsigned int len)
{
	currentPosition=0;
	memset(buffer,0,len);
	this->length=len;
	this->buffer=(char *)buffer;

}

CBufferWriter::~CBufferWriter()
{

}

bool CBufferWriter::WriteInt(int val)
{
	int *ret=0;
	ret=(int*)(this->buffer+currentPosition);
	*ret=val;
	currentPosition+=sizeof(int);
	return true;	
}
#include <string.h>
bool CBufferWriter::WriteString(char *str)
{
	unsigned int len=strlen(str)+1;

	if(currentPosition + len > this->length)
	{
		return false;
	}

	memcpy(this->buffer+currentPosition,str,len);
	currentPosition+=len;
	return true;
}

bool CBufferWriter::WriteDouble(double val)
{

	double *ret=0;

	if(currentPosition+sizeof(double) > this->length)
	{
		return false;
	}

	ret=(double*)(this->buffer+currentPosition);
	*ret=val;
	currentPosition+=sizeof(double);
	return true;
}

unsigned int CBufferWriter::GetCurrentPostion()
{
	return this->currentPosition;
}
