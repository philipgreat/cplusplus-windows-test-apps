#include "commonsocket.h"

#define  WINSOCKET_INIT		WSADATA wsd;\
	if(WSAStartup(MAKEWORD(2,0),&wsd)!=0)\
	{\
		 printf("Socket inted error!");\
	}
#define  WINSOCKET_UNINIT	WSACleanup();