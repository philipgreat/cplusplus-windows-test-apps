#include "TeraPicoCommon.h"

#ifndef	COMMONSOCKET_HEADER
#define COMMONSOCKET_HEADER
#ifndef WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#else
#include <windows.h>
#include <process.h>
#include <winsock.h>
#include <io.h>
#endif


#endif