
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CPPLIB_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CPPLIB_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef CPPLIB_EXPORTS
#define CPPLIB_API __declspec(dllexport)
#else
#define CPPLIB_API __declspec(dllimport)
#endif

// This class is exported from the CPPLib.dll
class CPPLIB_API CCPPLib {
public:
	int Add(int a, int b);
	CCPPLib(void);
	// TODO: add your methods here.
};
#if 0

extern CPPLIB_API int nCPPLib;
CPPLIB_API int fnCPPLib(void);

#endif