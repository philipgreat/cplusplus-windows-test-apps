// HaspKey.cpp: implementation of the HaspKey class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HaspKey.h"
#include "hasp.h"           /* definitions for the HASP interface        */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
static const int SeedCode        = 100;  /* the seed code - you can enter any integer */
HaspKey::HaspKey():portNumber(0)
{

}

HaspKey::~HaspKey()
{

}

bool HaspKey::isHasp()
{
	int p1, p2, p3, p4;
	p1 = p2 = p3 = p4 = 0;
	hasp(LOCALHASP_ISHASP, 0, portNumber, 0, 0, &p1, &p2, &p3, &p4);
	return (p3 == 0);
}

void HaspKey::login(int password1, int password2)
{
	this->password1 = password1;
	this->password2 = password2;
}

long HaspKey::getHaspId()
{
	int p1, p2, p3, p4;
	long id;
	p1 = p2 = p3 = p4 = 0;

	hasp(MEMOHASP_HASPID, SeedCode, portNumber, password1, password2, &p1, &p2, &p3, &p4);
	id = p2;
    id <<= 16;
    id |= (unsigned) p1;
	return id;
	
}
#define MEMO_BUFFER_SIZE 48     /* size in bytes */
int HaspKey::read(char *buffer, int length)
{
	int p1, p2, p3, p4;
	int ret = length;
	p1 = p2 = p3 = p4 = 0;
	p1 = 0;                        /* start address          */
	p2 = MEMO_BUFFER_SIZE >> 1;    /* buffer length in words */
	p3 = 0;
    p4 = (int)buffer;
	memset(buffer, 0, length);
	hasp(MEMOHASP_READBLOCK, SeedCode, portNumber, password1, password2, &p1, &p2, &p3, &p4);
	if(p3) ret = 0;
	return ret;
}

int HaspKey::write(const char *buffer, int length)
{
	int p1, p2, p3, p4;
	int ret = length;

	p1 = p2 = p3 = p4 = 0;
	p1 = 0;                        /* start address          */
	p2 = MEMO_BUFFER_SIZE >> 1;    /* buffer length in words */
	p3 = 0;
    p4 = (int)buffer;
	hasp(MEMOHASP_WRITEBLOCK, SeedCode, portNumber, password1, password2, &p1, &p2, &p3, &p4);
	if(p3) ret = 0;
	return ret;

}
