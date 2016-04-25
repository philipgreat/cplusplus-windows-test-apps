// Parameters.cpp: implementation of the CParameters class.
//
//////////////////////////////////////////////////////////////////////

#include "Parameters.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParameters::CParameters()
{
	
}

CParameters::~CParameters()
{
	//释放所有的参数
	//TODO
	this->Clear();
	//printf("delete paran\n");

}


BOOL CParameters::AddParameter(const char *name, const char *value)
{

	map<const char*, CParameter*, ltstr>::iterator loc;
	
	if(name!=NULL&&value!=NULL)
	{
		loc=parameters.find(name);

		char *key=new char[strlen(name)+1];
		//key will be free when the object destructed!
		
		memcpy(key,name,strlen(name)+1);

		//this key will be free when the 
		//object destruct
		if(loc==parameters.end()){
			//not found
			parameters[key]=new CParameter(name,value);
			//printf("'%s'\n",name);

		}else{
			//found
			char *key=(char*)loc->first;
			delete key;
			CParameter *p=loc->second;
			delete p;
			//加入新的参数
			parameters.erase(name);
			parameters[key]=new CParameter(name,value);
		}
		return TRUE;
	}else{
		return FALSE;
	}

	return FALSE;

}

enum PARSE_STATE{INIT=0,IN_NAME,BEFORE_VALUE,IN_VALUE,END_VALUE,END};
//该函数需要参考状态图

int  CParameters::ParseExpression(const char *str2parse,
								  char nameValueSeperator,
								  char itemSeperator)
{

	int state=INIT;
	char *header=NULL;
	int  parseStrLen=strlen(str2parse);
	char *p=header=new char[parseStrLen+1];
	//char *p=header=parseBuffer;
	//printf("--------start parse the expr\n");
	char *name=NULL;
	char *value=NULL;
	//this->Clear();

	memcpy(p,str2parse,parseStrLen);
	while(p-header<parseStrLen){
		switch(state){
		
		case INIT:
			//do nothing
			//if(*p>='a'&&*p<='z'){
			if(isalnum(*p)){
				name=p;
				state=IN_NAME;
			}
			break;
		case IN_NAME:
			//do nothing
			if(*p==nameValueSeperator){
				state=BEFORE_VALUE;
				*p='\0';
			}else if (!(isalnum(*p)||*p=='_'||*p=='.'||*p=='-')){
				//ignore blank any char
				//found blank ignore it
				*p='\0';
			}
			break;
		case BEFORE_VALUE:
			if(*p=='\r'||*p=='\n'||*p==itemSeperator){
				value="";
				state=END_VALUE;
				p--;
			}else if(*p==' '||*p=='\t' ){
				//忽略前面的空格等无效字符
			}else {
				value=p;
				state=IN_VALUE;
			}	
			break;
		case IN_VALUE:
			//seperator
			//if(*p=='\r'||*p=='\n'||*p==';'){
			if(*p=='\r'||*p=='\n'||*p==itemSeperator){
				*p='\0';
				p--;
				state=END_VALUE;
			}
			break;
		case END_VALUE:
			//printf("%s = %s\r\n",name,value);
			this->AddParameter(name,value);
			//父类可能重新处理,所以可能调用的是父类的方法
			state=INIT;	
			break;		
		default:
			break;

		}
		//end switch
		//printf("state = %d   %s\n",state,p);
		p++;
	
	}
	//printf("%d\r\n",p-header);

	delete[] header;

	return 0;
}

int CParameters::Parse(const char *data)
{
	//
	this->ParseExpression(data);
	return 1;
	
}

char * CParameters::GetValue(const char *name)
{
	CParameter *param=NULL;
#if 0 	
	//CParameter *param=this->parameters.find(name)->second;
	

	//printf("in getvalue %u, %s\n",param,name);
	if(NULL==param){
		//printf("get by key failed\n");
		//使用该方法修正WINDOWS CE STL 库的调试版的错误
		param=GetValueForDebugEdition(name);
	}
	//this does not work well in wince debug 
	//printf("/in getvalue \n");
	//param->Report();
	//printf("param ok return name %s\n", param->GetName());
	//printf("param ok return value %s\n", param->GetValue());
	//printf("pointer: %u %s\n",param,name);

	if(NULL!=param){
		return param->GetValue();	
	}else{
		return NULL;
	}
#endif
	map<const char*, CParameter*, ltstr>::iterator loc;
	loc = this->parameters.find(name);
	if(this->parameters.end() != loc){
		param=loc->second;
		return param->GetValue();
	}else{
		return NULL;
	}

}

void CParameters::Report()
{
	map<const char*, CParameter*, ltstr>::iterator loc;
	int len=parameters.size();
	printf("Size of the map: %u\n",len);
	
	for(loc=parameters.begin();loc!=parameters.end();loc++)
	{
		CParameter *p=loc->second;
		printf("\t%20s = %s\n",p->GetName(),p->GetValue());
	}
	//::WritePrivateProfileString(
}

#if 0
CParameter * CParameters::GetValueForDebugEdition(const char *key)
{
	map<const char*, CParameter*, ltstr>::iterator loc;
	//printf("GetValueForDebugEdition start\n");

	int len=parameters.size();
	//printf("Size of the map: %u\n",len);
	
	for(loc=parameters.begin();loc!=parameters.end();loc++)
	{
		//printf("Start!\n");
		CParameter *param=loc->second;
		//printf("Param Equals NULL pointer %u !\n",param);
		if(NULL==param){
			
			return param;		
		}
		char *pKey=param->GetName();
		//printf("\tFound pt= %u key=%s pKey=%s \n",param,key,pKey);
		if(strncmp(key,pKey,strlen(key+1))==0){
			//printf("\tFound pt= %u key=%s pKey=%s \n",param,key,pKey);
			return param;
		
		}
		//printf("\t%20s = %s\n",p->GetName(),p->GetValue());
	}
	return NULL; 
}
#endif

void CParameters::Clear()
{
	map<const char*, CParameter*, ltstr>::iterator loc;
	for(loc=parameters.begin();loc!=parameters.end();loc++)
	{
		//TODO: please check this in release version
		CParameter *p=loc->second;	
		char *key=(char*)loc->first;
		delete key;
		//key=NULL;
		//first is key, and second is the value
		delete p;
		p=NULL;
	}
	parameters.clear();
}
