// CWService.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HttpUtil.h"
#include "CertificateManager.h"
#include "UDPServer.h"
#include "SerializableCertificate.h"
#include "DirectoryHelper.h"
#include "GenericSAXParser.h"
#include <iostream>
#include <fstream>
int TestDownloadCertificate();
int TestLocalCertificate();
int ClassTestISOTime();
int TestServerMode();
int TestUpdateJavaScript();
int TestCppVirtual();
int TestXMLPaser();
#include "FackHandle.h"

int main(int argc, char* argv[])
{

	CHttpUtil::InitNetwork();
	//BOOL bl=CDirectoryHelper::Exists(L"F:\\suddy\\banner.psd1");
	TestServerMode();
	//测试XML分析器
	//TestXMLPaser();
	//ClassTestISOTime();
	//TestUpdateJavaScript();
	//CFackHandle *p=new CFackHandle();
	//CDirectoryHelper::ListFileName(L"F:\\suddy\\*.*",p);
	return 0;
}

int TestCppVirtual()
{
	CJavaScriptGenerator::UpdateJavaScript();
	return 0;
}

int TestUpdateJavaScript()
{
	CJavaScriptGenerator::UpdateJavaScript();
	return 0;
}
int TestServerMode()
{
	CUDPServer server(1800);
	server.SetServiceHandler(new CCertificateManager());
	server.Run();
	return 0;
}

int TestDownloadCertificate()
{
	CCertificateManager manager;
	CERTIFICATE_REQUEST_TASK task;
	memset((void *)&task,0x01,sizeof(task));

	manager.DownloadCertificate("suddy","it",task);

	CBaseCertificate *p = manager.ParseToCertificate();
	p->Report();
	//p->Store();
	delete p;
	return 0;
}
int TestLocalCertificate()
{
	CSerializableCertificate *pc=new CSerializableCertificate();
	pc->FromLocalFile(L"F:\\PPLive\\license__0000000030__0000000065.license");
	pc->Report();
	pc->AddPlayCount();
	delete pc;
	return 0;
}
int ClassTestISOTime()
{

	ISOTIME t1;
	ISOTIME t2;
	t1.init("2005-10-25T14:12:12");
	t2.init("2005-01-01T18:12:11");
	printf("t1<t2: %s\n",t1.before(t2)?"true":"false");
	printf("expirted: %s\n",t1.expired()?"true":"false");

	printf("arrive: %s\n",t1.arrive()?"true":"false");

	t1.absolute();

	printf("expirted: %d \n",t1-t2);
	return 0;
}

int TestXMLPaser()
{
	char xmlTest[1000] ={0};
	ifstream is("E:\\工作目录\\2.开发区\\4.机顶盒应用\\testing\\TempLicenseClientTest\\Debug\\xml.txt");
	is.read(xmlTest,1000);
	is.close();
	CGenericSAXParser *parser=new CGenericSAXParser();
	CCertificateParserHelper *certificateParserHelper = new CCertificateParserHelper();
	parser->SetHandle(certificateParserHelper);
	parser->Parse(xmlTest);
	delete parser;
    delete certificateParserHelper;
	return 1;
}