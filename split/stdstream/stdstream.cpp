// stdstream.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <string>
#include <algorithm>
#include <stdio.h>

#include <FSTREAM.H>


//本程序存在缓冲区溢出问题,不得用于CGI程序
int savefile(const char *filename){

	//std::ifstream is;
	char ch[256]={0};
	char chr='\0';
	ifstream fin (filename,filebuf::text);
	int i=0;

	while(fin.read(&chr,1)){
		if(i<=255&&chr!='\n'&&chr!='\r'){
			ch[i++]=chr;


		}else{

			cout<<"START>"<<ch<<endl;
			i=0;	
	
		}
		
	}

	cout<<"START>"<<ch<<endl;

	return 1;

}

int main(int argc, char* argv[])
{
	
	savefile("e:\\midl.txt");

	return 0;
}

