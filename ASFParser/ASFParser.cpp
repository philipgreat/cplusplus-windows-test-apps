// ASFParser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	unsigned int	part1;//4
	unsigned short	part2;//2
	unsigned short	part3;//2
	unsigned char	part4[2];//2
	unsigned char	part5[6];//6

}GUID;


typedef struct 
{
	GUID			guid;//4
	unsigned int	low;//4
	unsigned int	high;//4

}ASF_OBJECT_HEADER;



typedef struct 
{
	ASF_OBJECT_HEADER header;//4
	unsigned int	low;//4
	unsigned int	high;//4
	GUID			fileId;
	unsigned int	lowTotalPackageCount;//4
	unsigned int	highTotalPackageCount;//4
	unsigned int    reserved;
}ASF_DATA_OBJECT;
/*
Field name	Field type	Size (bits)
	Error Correction Flags	BYTE	8
	Error Correction Data Length		4 (LSB)
	Opaque Data Present		1
	Error Correction Length Type		2
	Error Correction Present		1
Error Correction Data	BYTE	varies


*/
typedef struct 
{
	unsigned char dataLength:4;
	unsigned char opaqueDataPresent:1;
	unsigned char correctionLengthType:2;
	unsigned char correctionPresent:1;
}ASF_ERROR_OBJECT;



int printGUID(const char* header)
{

	GUID *p=(GUID *)header;
	printf("%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
		p->part1,
		p->part2,
		p->part3,
		p->part4[0],
		p->part4[1],
		p->part5[0],
		p->part5[1],
		p->part5[2],
		p->part5[3],
		p->part5[4],
		p->part5[5]);
	
	return 0;

}

int ReportSample(const char* header)
{

	unsigned int *length=(unsigned int*) (header + 16);
	printGUID(header);
	printf(" len=%08u",*length);
	return *length+16+8;
}
#include "BufferReader.h"
#include "BufferWriter.h"
int moreDetailInfo();
int main(int argc, char* argv[])
{


	
	
	return moreDetailInfo();

}
int moreDetailInfo()
{

	
	char *data=new char[1024];
	//memset(p,0,16);
	FILE *f=fopen("f:\\testout.asf","r+b");
	//ReportSample(data);
	printf("sizeof  ASF_ERROR_OBJECT %d \n ",sizeof(ASF_ERROR_OBJECT));
	
	unsigned int rev=0;
	unsigned int total=0;
	int i=0;
	ASF_OBJECT_HEADER *p;
	while( 1 )
	{
		rev=fread(data,16+8,1,f);
		// ASF_OBJECT_HEADER *p;

		if(rev>0){
			p=(ASF_OBJECT_HEADER *)data;
			ReportSample(data);		
			total += 24;
		}else{
			break;
		}
		
		//printf("\n");

		unsigned int offset=p->low - 24;

		if(p->guid.part1 ==0x75B22630){
			//header
			offset = 4 + 1 + 1;		
			//printf("\t");
		}

		if(p->guid.part1 ==0x75B22636){
			//data object

		}
		
		if(p->guid.part1 ==0x5FBF03B5){
			offset =  16 + 2 + 4;
			printf("\t");
		}

		//rev=fread(data,offset ,1,f);
		int seekret=fseek(f,offset,SEEK_CUR);
		
		printf(" want to %04X ",offset);
		
		if(seekret==0){
			total += offset ;
			printf("\nsize of object %X  / %08u\n",offset,total);
		}else{
			break;
		}
		i++;

    }
	
	printf("\n");
	
	fclose(f);
	delete data;
	return 0;

}
int testBaseInfo()
{



	char *data=new char[1024];
	//memset(p,0,16);
	

	FILE *f=fopen("f:\\testout.asf","r+b");


	//ReportSample(data);

	//printf("Hello World!\n");
	
	unsigned int rev=0;
	unsigned int total=0;
	int i=0;
	ASF_OBJECT_HEADER *p;
	while(1)
	{
		rev=fread(data,16+8,1,f);
		// ASF_OBJECT_HEADER *p;

		if(rev>0){
			p=(ASF_OBJECT_HEADER *)data;
			ReportSample(data);	
			total += 24;
		}else{
			break;
		}
		
		//printf("\n");

		unsigned int offset=p->low - 24;
		//rev=fread(data,offset ,1,f);
		int seekret=fseek(f,offset,SEEK_CUR);
		
		printf(" want to %04X ",offset);
		
		if(seekret==0){
			total += offset ;
			printf("\nsize of object %X  / %08u\n",offset,total);
		}else{
			break;
		}

		i++;

    }
	
	printf("\n");
	
	fclose(f);

	delete data;

	return 0;

}


/*******************************************************************************\
75B22630-668E-11CF-A6D9-00AA0062CE6C len=00003074 want to 0006
size of object 6  / 00000030
D2D0A440-E307-11D2-97F0-00A0C95EA850 len=00000162 want to 008A
size of object 8A  / 00000192
86D15240-311D-11D0-A3A4-00A0C90348F6 len=00000242 want to 00DA
size of object DA  / 00000434
8CABDCA1-A947-11CF-8EE4-00C00C205365 len=00000104 want to 0050
size of object 50  / 00000538
5FBF03B5-A92E-11CF-8EE3-00C00C205365 len=00002251 want to 08B3
size of object 8B3  / 00002789
B7DC0791-A9B7-11CF-8EE6-00C00C205365 len=00000114 want to 005A
size of object 5A  / 00002903
B7DC0791-A9B7-11CF-8EE6-00C00C205365 len=00000133 want to 006D
size of object 6D  / 00003036
7BF875CE-468D-11D1-8D82-006097C9A2B2 len=00000038 want to 000E
size of object E  / 00003074
75B22636-668E-11CF-A6D9-00AA0062CE6C len=04176050 want to 3FB89A
size of object 3FB89A  / 04179124
33000890-E5B1-11CF-89F4-00A0C90349CB len=00000326 want to 012E
size of object 12E  / 04179450



ASF_File_Properties_Object		8CABDCA1-A947-11CF-8EE4-00C00C205365
ASF_Stream_Properties_Object	B7DC0791-A9B7-11CF-8EE6-00C00C205365
ASF_Header_Extension_Object		5FBF03B5-A92E-11CF-8EE3-00C00C205365
ASF_Codec_List_Object			86D15240-311D-11D0-A3A4-00A0C90348F6
ASF_Script_Command_Object		1EFB1A30-0B62-11D0-A39B-00A0C90348F6
ASF_Marker_Object				F487CD01-A951-11CF-8EE6-00C00C205365
ASF_Bitrate_Mutual_Exclusion_Object	D6E229DC-35DA-11D1-9034-00A0C90349BE
ASF_Error_Correction_Object		75B22635-668E-11CF-A6D9-00AA0062CE6C
ASF_Content_Description_Object	75B22633-668E-11CF-A6D9-00AA0062CE6C
ASF_Extended_Content_Description_Object	D2D0A440-E307-11D2-97F0-00A0C95EA850
ASF_Content_Branding_Object		2211B3FA-BD23-11D2-B4B7-00A0C955FC6E
ASF_Stream_Bitrate_Properties_Object	7BF875CE-468D-11D1-8D82-006097C9A2B2
ASF_Content_Encryption_Object	2211B3FB-BD23-11D2-B4B7-00A0C955FC6E
ASF_Extended_Content_Encryption_Object	298AE614-2622-4C17-B935-DAE07EE9289C
ASF_Digital_Signature_Object	2211B3FC-BD23-11D2-B4B7-00A0C955FC6E
ASF_Padding_Object				1806D474-CADF-4509-A4BA-9AABCB96AAE8
\*******************************************************************************/