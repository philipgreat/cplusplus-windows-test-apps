// URLDecode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <ctype.h>

char toNumber(char ch);
int decodeURL(char *str);
int encodeURL(const char *str,char **url);
char makechar(char char1, char char2);
const char *hextab="0123456789ABCDEF";

int main(int argc, char* argv[])
{
	char *str=new char[100];
	strcpy(str,"abc%BA%C3%B5%C4");
	decodeURL(str);
	printf("%s\n",str);
	encodeURL("abcºÃµÄ",&str);

	printf("%s\n",str);
	return 0;
}
int encodeURL(const char *str,char **url)
//please
 make sure that the *url's is three times of str!!!!!!!!!!
{

	char *p=(char *)str;
	char *out=(*url);
	int count=0;
	while(*(p)){
		if(!isalnum(*p)){
			*(out+(count++))='%';
			*(out+(count++))=*(hextab+(((*p)&0xf0)>>4));
			*(out+(count++))=*(hextab+((*p)&0x0f));
		}else{
			*(out+(count++))=*p;
		}

		p++;
	}
	*(out+count)=0;
	return count;

}

int decodeURL(char *url)
{
	int count=0;
	char *p=url;
	while(*(p)){		
		if(*p=='%'){
			*(url+count)=makechar(*(++p),*(++p));
			count++;
		}else{
			*(url+count)=*(p);
			count++;			
		}
		p++;		
	}
	*(url+count)=0;
	return count;
}


char makechar(char char1, char char2)
{
	return  toNumber(char1)+(toNumber(char2)<<4);
}
char toNumber(char ch)
{
	if(ch>='0'&&ch<='9')
	{
		return ch-'0';
	}
	if(ch>='a'&&ch<='z')
	{
		return ch-'a'+10;
	}
	if(ch>='A'&&ch<='Z')
	{
		return ch-'A'+10;
	}
	return 0;

}