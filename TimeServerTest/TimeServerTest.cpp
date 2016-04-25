// TimeServerTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NetworkUtil.h"
#include "ThisTest.h"

#include <stdlib.h>


int main(int argc, char* argv[])
{
	CNetworkUtil::InitNetwork();
	if(argc<3) {
	
		printf("usage : TimeSync <host> <port>\n");
		return 0;
	}
	char *host = argv[1];
	unsigned short port = atoi(argv[2]);
	BOOL ret = CNetworkUtil::SyncTime(host,port);
	if(ret){
		printf("Sync Time OK!\n");

	}else{
		printf("Sync Time failed!\n");

	}
	CNetworkUtil::UninitNetwork();

	return 0;
}
