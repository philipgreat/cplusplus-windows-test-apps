// RegisterIME.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Windows.h"
#include "Imm.h"

int main(int argc, char* argv[])
{
	PVOID lpMsgBuf;	
	HKL ime=ImmInstallIME(
		"c:\\winnt\\system32\\ylam1.IME",
		"E2C ‰»Î∑®");
	DWORD err = GetLastError();
    FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		err,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf,
		0,
		NULL
		); 
	printf("ime = %u, 0x%0X, %s\n",ime,err,lpMsgBuf);
	CloseHandle(ime);
	return 0;
}

/*

  Windows NT/2000/XP: Included in Windows NT 4.0 and later.
  Windows 95/98/Me: Included in Windows 95 and later.
  Header: Declared in Imm.h; include Windows.h.
  Library: Use Imm32.lib.
*/