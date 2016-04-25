// CPPLib.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "CPPLib.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}


// This is an example of an exported variable


// This is the constructor of a class that has been exported.
// see CPPLib.h for the class definition
CPPLIB_API CCPPLib::CCPPLib()
{ 
	return; 
}


int CCPPLib::Add(int a, int b)
{
	return a+b;
}


#if 0
CPPLIB_API int nCPPLib=0;

// This is an example of an exported function.
CPPLIB_API int fnCPPLib(void)
{
	return 42;
}
#endif