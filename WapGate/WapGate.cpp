// WapGate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TeraPicoWapGateService.h"
#include "TeraPicoLogFile.h"
#define		__UNIX__	("SYSTEM UNIX")


using namespace terapico;
using namespace std;
static int a[]={2,1,5,7,8,6,3,4,5,9};

int bubblesort(){
	int i=0;
	int j=0;
	int tmp=0;
	int idx=sizeof(a)/sizeof(int);

	
	for(i=1;i<idx;i++){
		
		for(j=1;j<idx;j++){
			if(a[j]<a[j-1]){
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
			}
		}

		//printf("%d ",tmp);

		idx--;
		//a[idx]=tmp;
		

	}
	for(i=0;i<sizeof(a)/sizeof(int);i++){
		printf("%d\n",a[i]);
	}
	return 0;

}

int size(int a[100]){
	
	return sizeof(a);

}
int main(int argc, char* argv[])
{
	//winInitSockEnv();
	//ServerSocket *pss=new ServerSocket(1,0,"*",8080);

	WapGateService *pwgs=new WapGateService();
	
	//plf->Logging("sdf");

	//printf("%s",__UNIX__);
	int a[1000];
	printf("%f",size(a));
	
	

	return 0;
}
