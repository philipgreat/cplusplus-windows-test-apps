// BufferReader.cpp: implementation of the CBufferReader class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BufferReader.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBufferReader::CBufferReader(const char *buffer,unsigned int len)
{
	currentPosition=0;
	this->buffer=(char *)buffer;
	this->length=len;


}

CBufferReader::~CBufferReader()
{

}

int CBufferReader::ReadInt()
{
	int *ret=0;
	ret=(int*)(this->buffer+currentPosition);
	currentPosition+=sizeof(int);
	return *ret;
}

double CBufferReader::ReadDouble()
{
	double *ret=0;


	ret=(double*)(this->buffer+currentPosition);
	currentPosition+=sizeof(double);
	return *ret;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* CBufferReader::ReadString()
{
	char *ret=NULL;


	ret=(char*)(this->buffer+currentPosition);
	currentPosition += strlen(ret) + 1;
	return ret;

}

unsigned int CBufferReader::GetCurrentPostion()
{	
	return this->currentPosition;
}
