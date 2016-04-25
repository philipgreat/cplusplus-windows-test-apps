// HaspTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

#include "HaspKey.h"

int main(int argc, char* argv[])
{
	int pass1 = 5277;
	int pass2 = 24547;
	char buffer[48];

	HaspKey key;
	key.login(pass1,pass2);
	printf("ishasp = %d\n",key.isHasp());
	strcpy(buffer,"jOusnxascXI3Gi7xET0KFgnN");
	key.write(buffer, 48);
	key.read(buffer, 48);
	printf("%s\n",buffer);
	return 0;
}
