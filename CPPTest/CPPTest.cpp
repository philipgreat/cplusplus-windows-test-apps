// CPPTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TypeIdTest.h"

enum SCREEN_STATE  { INIT=0, FIRST_W=1, FIRST_A=2, FOLLOW_A=3,FOLLOW_W=4,END_S,END_C};

static int getNextState(int currentState,int key)
{
	

	

	switch(currentState){
	
	case INIT:
		if(key=='W'){
			return FIRST_W;
		}
		
		if(key=='A'){
			return FIRST_A;
		}
		break;
	
	case FIRST_W:
		if(key=='W'){
			return FIRST_W;
		}
		
		if(key=='A'){
			return FIRST_A;
		}
		break;
	
	default:
		break;
	
	}


}

#include "PowerScreenShot.h"

#include <vector>
#include <string>
using namespace std;

#include <stdio.h>





#ifdef _WIN32
#define CHECK_NUMBER(a,b) if(true){int expect=(a);int got=(b); if(expect!=got){printf("[X]...%s(%3d), expect<%d> get<%d>: %s != %s\n",__FILE__,__LINE__,expect,got,#a,#b);}}
#define CHECK_STRING(a,b) if(true){char *expect=(a);char *got=(b);if(expect==NULL&&got==NULL){}else if(expect==NULL){printf("[X]...%s(%3d), expect<NULL> get<%s>: %s != %s\n",__FILE__,__LINE__,(got),#a,#b);}else if(got==NULL){printf("[X]...%s(%3d), expect<%s> get<NULL>: %s != %s\n","oratest.cpp",__LINE__,(expect),#a,#b);}else if(strcmp(expect,got)!=0){printf("[X]...%s(%3d), expect<%s> get<%s>: %s != %s\n","oratest.cpp",__LINE__,(expect),(got),#a,#b);}}
#define TEST_LABLE(a)  printf("%s:%4d:...<%s>...","oratest.cpp",__LINE__,a);printf("\n");
#else //for gcc
#define CHECK_NUMBER(a,b) if(true){int expect=(a);int got=(b); if(expect!=got){printf("[X]...%s(%3d), expect<%d> get<%d>: %s != %s\n",__FUNCTION__,__LINE__,expect,got,#a,#b);}}
#define CHECK_STRING(a,b) if(true){char *expect=(a);char *got=(b);if(expect==NULL&&got==NULL){}else if(expect==NULL){printf("[X]...%s(%3d), expect<NULL> get<%s>: %s != %s\n",__FUNCTION__,__LINE__,(got),#a,#b);}else if(got==NULL){printf("[X]...%s(%3d), expect<%s> get<NULL>: %s != %s\n",__FUNCTION__,__LINE__,(expect),#a,#b);}else if(strcmp(expect,got)!=0){printf("[X]...%s(%3d), expect<%s> get<%s>: %s != %s\n",__FUNCTION__,__LINE__,(expect),(got),#a,#b);}}
#define TEST_LABLE(a)  printf("%s:%4d:...<%s>...%s",__FILE__,__LINE__,a,__FUNCTION__);printf("\n");
#endif

int add(int a, int b)
{
	return a+b;

}

int main(int argc, char* argv[])
{
	
	CHECK_NUMBER(3,add(1,1));
	

	return 0;
}



