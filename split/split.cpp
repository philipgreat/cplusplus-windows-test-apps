// split.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#define FILE_SAVE_FLAG	"@savefile: "
#define FILE_APPD_FLAG	"@appendfile: "

bool isFileSaveFlag(const char *line)
{
	return memcmp(line,FILE_SAVE_FLAG,strlen(FILE_SAVE_FLAG))==0;
	
}
bool isFileAppFlag(const char *line)
{
	return memcmp(line,FILE_SAVE_FLAG,strlen(FILE_APPD_FLAG))==0;	
}


#include <time.h>
int split(int argc, char* argv[]){
	FILE *pf=NULL;
	FILE *pto=NULL;
	char  filepath[256]={0};
	char *content=(char*)malloc(1024);
	memset(content,0,1024);
	int loc=0;
	int filecount=0;
	int totalsize=0;
	if(argc<3){
		printf("at least 3 parameters\n");
		return 0;
		
	}
	
	pf=fopen(*(argv+1),"r");
	if(pf==NULL){
		printf("Error Read File!\n");
		exit(0);
		
	}
	while(!feof(pf)){
		//fscanf(pf,"%s",);
		//fscanf(pf,"%s\n",content);
		fgets(content,1024-1,pf);
		loc++;
		
		//printf("Line: %s",content);
		if(!(memcmp(content,FILE_SAVE_FLAG,strlen(FILE_SAVE_FLAG)))){
			//printf("Line: %s",content);
			int len=strlen(content);
			filecount++;
			if(pto!=NULL){
				fclose(pto);
			}
			
			*(content+len-1)='\0';
			strcpy(filepath,*(argv+2));
			strcat(filepath,"\\");
			strcat(filepath,content+strlen(FILE_SAVE_FLAG));
			
			pto=fopen(filepath,"w");
			
			if(pto==NULL){
				printf("Error open File %s!\n",filepath);
				exit(0);
				
			}
			
			printf("Save file:  %s\n",
				//*(content+len-1),
				content+strlen(FILE_SAVE_FLAG));
			
			
		}else if((!(memcmp(content,FILE_APPD_FLAG,strlen(FILE_APPD_FLAG))))){
			//here proccess append case
			
			int len=strlen(content);
			//filecount++;
			if(pto!=NULL){
				fclose(pto);
			}
			
			*(content+len-1)='\0';
			strcpy(filepath,*(argv+2));
			strcat(filepath,"\\");
			strcat(filepath,content+strlen(FILE_APPD_FLAG));
			
			pto=fopen(filepath,"a");
			
			if(pto==NULL){
				printf("Error open File %s!\n",filepath);
				exit(0);
				
			}
			
			printf("Appd file:  %s\n",
				//*(content+len-1),
				content+strlen(FILE_APPD_FLAG));
			
		}else{
			
			if(NULL!=content&&pto!=NULL){
				fprintf(pto,"%s",content);
				totalsize+=strlen(content);
			}
			
			
		}
		memset(content,0,1024);
	}
	
	printf("\n==========================================================\n");
	printf("File count\t:\t%8d files\n",filecount);
	printf("Line of code\t:\t%8d lines\n",loc);
	printf("Total size\t:\t%8d bytes\n",totalsize);
	printf("==========================================================\n");
	
	
	
	
	
	
	
	
	return 0;
	
}
int main(int argc, char* argv[])
{
	
	
	
	return split(argc,argv);
	
}

