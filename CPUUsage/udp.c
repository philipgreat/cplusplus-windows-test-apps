#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "udp_client.h"
int main(int argc, char**argv)
{
	udp_client_t *p=udp_client_new();
	if(argc<2){
		printf("use like this: cpumon <ip>\n");
		return 1;
	}
	p->connect(p,argv[1],16800);
	p->send(p,argv[2],strlen(argv[2]));
	p->close(p);
	udp_client_delete(p);
}
