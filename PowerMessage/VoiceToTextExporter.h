// VoiceToTextExporter.h: interface for the CVoiceToTextExporter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VOICETOTEXTEXPORTER_H__81B28F54_DB1E_450C_9DE7_D25A67168D29__INCLUDED_)
#define AFX_VOICETOTEXTEXPORTER_H__81B28F54_DB1E_450C_9DE7_D25A67168D29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CVoiceToTextExporter  
{
private:
	char *fileName;

public:
	bool WriteFile(char *fileName,char *text);
	void onFatal(int errorCode, char message[]);
	void onFail(int errorCode, char message[]);
	void onSuccess(int errorCode, char message[]);
	CVoiceToTextExporter();
	virtual ~CVoiceToTextExporter();

};

#endif // !defined(AFX_VOICETOTEXTEXPORTER_H__81B28F54_DB1E_450C_9DE7_D25A67168D29__INCLUDED_)
