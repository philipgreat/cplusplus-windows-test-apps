// VoiceToTextExporter.cpp: implementation of the CVoiceToTextExporter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VoiceToTextExporter.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
CVoiceToTextExporter::CVoiceToTextExporter()
{
	fileName=new char[1024];
	::GetCurrentDirectoryA(1024,fileName);
	strcat(fileName,"\\export.txt");
	
}

CVoiceToTextExporter::~CVoiceToTextExporter()
{
	delete fileName;
}

void CVoiceToTextExporter::onSuccess(int errorCode, char message[])
{
	WriteFile(this->fileName,message);
}

void CVoiceToTextExporter::onFail(int errorCode, char message[])
{
	WriteFile(this->fileName,"");
}

void CVoiceToTextExporter::onFatal(int errorCode, char message[])
{
	WriteFile(this->fileName,"");
}

bool CVoiceToTextExporter::WriteFile(char *fileName, char *text)
{	
	FILE *f;
	f=fopen(fileName,"a");
	if(f!=NULL)
	{
		fprintf(f,"%s\n",text);
	}
	fclose(f);
	return true;

}
