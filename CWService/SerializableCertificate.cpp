// SerializableCertificate.cpp: implementation of the CSerializableCertificate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SerializableCertificate.h"

//���ڽ�֤��洢
#include "DirectoryHelper.h"
#ifdef _WIN32_WCE
#define LOCAL_STORE_PATH     L"\\hard disk\\license"
#else
#ifdef _UNICODE
#define LOCAL_STORE_PATH     L"d:\\license"
#else
#define LOCAL_STORE_PATH     "d:\\license"
#endif
#endif

//֤��洢���ַ���
#define CERTIFICATE_STORE_FORMAT "%s\\license__%010u__%010u.license"
//purify shows that there is a UMR (uninitialized memory reader here);
//please ignore it, beacause, union could never initialed in some field
//if the type is duration, this could never occured
//suddy comment!

#define A2W(W,A)     MultiByteToWideChar(936,0,(A),strlen((A))+1,(W),strlen((A))+1)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSerializableCertificate::CSerializableCertificate()
{
	memset(&this->policyArgument1,0x00,sizeof(this->policyArgument1));
	memset(&this->policyArgument2,0x00,sizeof(this->policyArgument2));
	//���ǰ��ŵ�����vptr(���ĵ�ַ����4���ֽ�)���൱��thisָ��Ĵ�С;
	//�������ڴ��е�����ÿ���ֽڶ���Ϊ��(0);
	memset((BYTE*)this+sizeof(this),0x00,sizeof(CSerializableCertificate)-sizeof(this));
	this->updateTime  = GetTickCount();
}
CSerializableCertificate::~CSerializableCertificate()
{

}

//�洢֤��,�����ڻ���
BOOL CSerializableCertificate::Store()
{
	WCHAR fileName[ MAX_PATH ];
	BOOL ret = FALSE;
	//��ȡ�洢�ļ�������
	wsprintf(fileName, TEXT(CERTIFICATE_STORE_FORMAT),
		LOCAL_STORE_PATH,
		this->ContentTypeID,
		this->ControlWordId);
	//IsAvaliable�����ж�֤���Ƿ���Ч���������ֲ�ͬҵ����ԣ��жϵķ�ʽҲ��һ����
	//ͬʱ֤�黹û�е�ʱ��
	if(!this->IsAvaliable()&&this->policyArgument2.timeArg.expired())
	{
		//���֤���Ѿ�ʧЧ����֤��ɾ��
		this->Discard();
	}
	else
	{	
		//��֤��洢��ֱ�Ӵ洢�ɶ������ļ�
		ret = CDirectoryHelper::WriteBinaryFile(fileName,		
			(BYTE *)this + sizeof(this),
			sizeof(CSerializableCertificate) - sizeof(this));
	}
	return ret;
}


//���ļ��ж�ȡ֤��
BOOL CSerializableCertificate::FromLocalFile(const WCHAR *fileName)
{
	DWORD len = sizeof(CSerializableCertificate) - sizeof(this);
	BOOL ret = FALSE;
	//ֱ�ӽ��ļ��е����ݴ洢�������С�
	ret = CDirectoryHelper::ReadBinaryFile(fileName,(BYTE *)this + sizeof(this) ,&len);	
	//���»�ȡ�µ���ʼʱ�䡣
	this->updateTime = GetTickCount();
	return ret;
}

//����֤�����Ϣ�㱨
void CSerializableCertificate::Report()
{
	printf("************** CSerializableCertificate details ***************\n");
	printf("%20s: %s\n","CertificateID", this->CertificateID);
	printf("%20s: %s\n","version", this->version);
	printf("%20s: %u\n","MajorTypeId", this->MajorTypeId);
	printf("%20s: %u\n","SubTypeID", this->SubTypeID);
	printf("%20s: %u\n","content id", this->ContentId);
	printf("%20s: %u\n","content type", this->ContentTypeID);
	printf("%20s: %s\n","user id", this->UserID);
	printf("%20s: %u\n","control word id", this->ControlWordId);
	printf("%20s: %u\n","control word", this->ControlWord);
	printf("%20s: %u\n","used second", this->usedSecond);
	printf("%20s: %u\n","used count", this->usedCount);
	
	switch(this->MajorTypeId){
	case VOLATILE:
		printf("%20s","unknwon\n");
		break;
	case BYTIMEDURATION:
		printf("%20s: %04d-%02d-%02d %02d:%02d:%02d to %04d-%02d-%02d %02d:%02d:%02d\n",
			"duration",
			this->policyArgument1.timeArg.year,this->policyArgument1.timeArg.month,this->policyArgument1.timeArg.day,
			this->policyArgument1.timeArg.hour,this->policyArgument1.timeArg.minute,this->policyArgument1.timeArg.second,
			this->policyArgument2.timeArg.year,this->policyArgument2.timeArg.month,this->policyArgument2.timeArg.day,
			this->policyArgument2.timeArg.hour,this->policyArgument2.timeArg.minute,this->policyArgument2.timeArg.second
			);
		break;
	case BYCOUNT:
		printf("%20s: %u\n","play count",this->policyArgument1.count);
		break;
	case BYDATETIME:
		printf("%20s: %u %c\n","play time",this->policyArgument1.count,this->policyArgument2.unit);
		break;
	}
	printf("%20s: %s\n","available", this->IsAvaliable()?"true":"false");
	printf("****************************************************************\n");
}

BOOL CSerializableCertificate::FromSaxHandle(CCertificateParserHelper *handle)
{
	//��handler�л�ȡ�������ݣ�Ȼ���ٽ��д�����ͨ����
	this->SetCertificateID(handle->GetCertificateID());
	this->SetContentId(handle->GetContentId());
	this->SetContentTypeID(handle->GetContentTypeID());
	this->SetControlWord(handle->GetControlWord());
	this->SetControlWordId(handle->GetControlWordId());
	this->SetCpID(handle->GetCpID());
	this->SetCreateTime(handle->GetCreateTime());
	this->SetMajorTypeId(handle->GetMajorTypeId());
	this->SetUserID(handle->GetUserID());
	this->SetSubTypeID(handle->GetSubTypeID());
	this->SetStartTime(handle->GetStartTime());
	this->SetExpiration(handle->GetExpiration());
	this->CreateTime[19]='\0';
	this->StartTime[19]='\0';
	this->Expiration[19]='\0';
	//��������
	//����ǰ���ʱ�䳤�շ�
	if(this->MajorTypeId==BYDATETIME)
	{
		//���õ�λ
		this->SetUnit(handle->GetUnit());
		//����Amount
		this->SetAmount(handle->GetAmount());
		switch(this->Unit[0]) 
		{
			//���������շ�
			case 'D':
				this->policyArgument1.count = 86400*Amount;
				break;
			case 'H':
				this->policyArgument1.count = 3600*Amount;
				break;
			case 'M':
				this->policyArgument1.count = 60*Amount;
				break;
			case 'S':
				this->policyArgument1.count = Amount;
				break;
			default:
				break;
		}
		this->Amount = this->policyArgument1.count;
		this->SetUnit("s");
	}
	else if(this->MajorTypeId==BYTIMEDURATION)
	{
		struct ISOTIME time;
		time.init(this->StartTime);
		this->policyArgument1.timeArg = time;
		time.init(this->Expiration);
		this->policyArgument2.timeArg = time;
	}
	else if(this->MajorTypeId==BYCOUNT)
	{
		//����Amount
		this->SetAmount(handle->GetAmount());
		this->policyArgument1.count = this->Amount;
	}
	else
	{
		return false;
	}
	return TRUE;
}

BOOL CSerializableCertificate::IsNeedStore()
{
	BOOL ret = FALSE;
	//���ȸ���״̬,�ڸ���״̬�Ĺ����У�����Ѿ��ù���ʱ������޸�	
	switch(this->MajorTypeId){
	case VOLATILE:		
		break;
	case BYTIMEDURATION:
		//����ʱ��û��
		ret =!this->policyArgument2.timeArg.expired();
		break;
	case BYCOUNT:
		ret = (this->usedCount < this->policyArgument1.count);
		break;
	case BYDATETIME:	
		ret = (this->usedSecond < this->policyArgument1.count);
		break;
	}
	return ret;
}

//��ȡ�����ֵĺ���,���������ķ���
DWORD CSerializableCertificate::GetControlWord()
{
	DWORD cw =  0;
	switch(this->MajorTypeId){
	//ֱ��Ƶ����TSTV(ʱ��Ƶ����Ŀ)
	case VOLATILE:
		cw = 0;
		break;
	//���ռ���տ���֤��
	case BYTIMEDURATION:
		if(!this->IsAvaliable()&&this->policyArgument2.timeArg.expired())
		{
			//֤���Ѿ�����, ����û�е��ڵ�����ų�����
			this->Discard();
			cw = 0;
		}
		else if(this->IsAvaliable())
		{
			cw = this->ControlWord;
		}
		else{
			cw = 0;
		}
		break;
	case BYCOUNT:
		if(!this->IsAvaliable()){
			printf("try to discard certificate!\n");
			this->Discard();
			cw = 0;
		}
		else
		{
			cw = this->ControlWord;		
		}

		break;
	case BYDATETIME:
		if(!this->IsAvaliable()){
			printf("try to discard certificate!\n");
			this->Discard();
			cw = 0;
		}
		else
		{
			cw = this->ControlWord;		
		}
		break;
	}
	return cw;

}

//�ж�֤���Ƿ���Ч
BOOL CSerializableCertificate::IsAvaliable()
{
	BOOL ret = FALSE;
	//���ȸ���״̬,�ڸ���״̬�Ĺ����У�����Ѿ��ù���ʱ������޸�	
	this->UpdateState();
	switch(this->MajorTypeId){
	case VOLATILE:		
		break;
	case BYTIMEDURATION:
		//��һ��ʱ�䷶Χ���ھ������ʱ�䵽�˲������ʱ��û�й��� :)
		ret =(!this->policyArgument2.timeArg.expired()
			&&this->policyArgument1.timeArg.arrive());
		break;
	case BYCOUNT:
		ret = (this->usedCount < this->policyArgument1.count);
		break;
	case BYDATETIME:	
		ret = (this->usedSecond < this->policyArgument1.count);
		break;
	}
	return ret;
}

void CSerializableCertificate::AddPlayCount()
{
	this->usedCount++;
}

//�Ƿ񱣴���Ӳ���С�
BOOL CSerializableCertificate::IsCertExistsOnDisk(DWORD contentType,
											 DWORD controlWordId)
{
	WCHAR fileName[ MAX_PATH ];

	wsprintf(fileName, TEXT(CERTIFICATE_STORE_FORMAT),
		LOCAL_STORE_PATH,
		contentType,
		controlWordId);

	BOOL isExists=CDirectoryHelper::Exists(fileName);
	return isExists;
}

//��ȡĳ��ContentType��ControlWordID��֤��
BOOL CSerializableCertificate::FromLocalFile(DWORD acontentType, DWORD acontrolWordId)
{
	WCHAR fileName[ MAX_PATH ];
	wsprintf(fileName, TEXT(CERTIFICATE_STORE_FORMAT),
		LOCAL_STORE_PATH,
		acontentType,
		acontrolWordId);
	//wprintf(L"\nFromLocalFile: %s\n",fileName);
	return this->FromLocalFile(fileName);
}

//ɾ��֤��
BOOL CSerializableCertificate::Discard()
{
	WCHAR fileName[ MAX_PATH ];

	wsprintf(fileName, TEXT(CERTIFICATE_STORE_FORMAT),
		LOCAL_STORE_PATH,
		this->ContentTypeID,
		this->ControlWordId);
	BOOL isOK = CDirectoryHelper::DeleteFile(fileName);
	return isOK;
}

char * CSerializableCertificate::GenerateJavaScriptObject(char *ret, DWORD len, int index)
{
	//todo secure this function!
	switch(this->MajorTypeId){
	case VOLATILE:
		memcpy(ret,"\t//unkown\r\n",strlen("//unkown\r\n")+1);
		break;
	case BYTIMEDURATION:
		//vodCertificateList[2] = new DurationCertInfo('3', '2005-08-15 18:30', '2005-09-05');
		sprintf(ret,"\tvodCertificateList[%u] = new DurationCertInfo(%u, '%04d-%02d-%02d %02d:%02d:%02d', '%04d-%02d-%02d %02d:%02d:%02d');//%u\r\n",
			index,
			this->ContentId,
			this->policyArgument1.timeArg.year,this->policyArgument1.timeArg.month,this->policyArgument1.timeArg.day,
			this->policyArgument1.timeArg.hour,this->policyArgument1.timeArg.minute,this->policyArgument1.timeArg.second,
			this->policyArgument2.timeArg.year,this->policyArgument2.timeArg.month,this->policyArgument2.timeArg.day,
			this->policyArgument2.timeArg.hour,this->policyArgument2.timeArg.minute,this->policyArgument2.timeArg.second,
			this->ControlWordId
			);
		break;
	case BYCOUNT:
		//vodCertificateList[0] = new CountCertInfo('1','3','1');
		sprintf(ret,"\tvodCertificateList[%u] = new CountCertInfo(%u, %u, %u);//%u\r\n",
			index,
			this->ContentId,
			this->policyArgument1.count,
			this->usedCount,
			this->ControlWordId
			);
		break;
	case BYDATETIME:
		sprintf(ret,"\tvodCertificateList[%u] = new TimeCertInfo(%u, %u, %u);//%u\r\n",
			index,
			this->ContentId,
			this->policyArgument1.count,
			this->usedSecond,
			this->ControlWordId);
		break;
	}
	return ret;
}

void CSerializableCertificate::UpdateState()
{
	//Ӧ���Ǳ�֤�������ڴ��ʱ��
	//�����ֵ����һ��ʱ�䷶Χ��, ����ܾ�û�е��øú���
	//��֤����֤�鲻�, Ӧ�ô��ڴ�������
	DWORD now = GetTickCount();
	DWORD span = (DWORD)((double)(now - this->updateTime)/(double)(1000));
	
	if(span>=10){
		//���ʱ�䵽��10s�򱣴�һ��
		this->usedSecond += span;
		this->updateTime = now;	
		printf("!this file need to be stored perform store\n");
		this->Report();
		this->Store();
	}
}


BOOL CSerializableCertificate::IsNeedDiscard()
{
	BOOL ret = FALSE;
	this->UpdateState();
	switch(this->MajorTypeId){
	case VOLATILE:
		ret = TRUE;
		break;
	case BYTIMEDURATION:
		ret = this->policyArgument2.timeArg.expired();
		break;
	case BYCOUNT:
		//this->policyArgument1.count stores count
		ret = (this->usedCount >= this->policyArgument1.count);
		break;
	case BYDATETIME:		
		ret = (this->usedSecond >= this->policyArgument1.count);
		break;
	}
	return ret;
}

BOOL CSerializableCertificate::Teardown()
{
	this->AddPlayCount();
	this->Store();
	return TRUE;
}

void ISOTIME::init(const char *timestring)
{
		char *p = (char*) timestring;
		year = 0;
		if(strlen(timestring)!=19){
			return;
		}		
		//2004-08-09T12:00:00
		//01234567890123456789
		year = atoi(p);
		month = atoi(p+5);
		day = atoi(p+8);
		hour = atoi(p+11);
		minute = atoi(p+14);
		second = atoi(p+17);
}
#define LESS_THAN_TEST(X,Y) if((X)<(Y)){return TRUE;}else if((X)>(Y)){return FALSE;}
#define GREATE_THAN_TEST(X,Y) if((X)>(Y)){return TRUE;}else if((X)<(Y)){return FALSE;}

#if 0
void ISOTIME::init(const char *timestring)
{
	year = 0;
	int len = strlen(timestring)+1;
	char *header = NULL;
	char *p = NULL;
	p = header = new char[len];
	memcpy(p,timestring,len);
	if(strlen(timestring)!=19){
		return;
	}
	while(*p){
		if(*p=='-'||*p=='T'||*p==':'){
			*p=0;
		}
		p++;
	}
	
	p=header;
	//2004-08-09T12:00:00
	//01234567890123456789
	year = atoi(p);
	month = atoi(p+5);
	day = atoi(p+8);
	hour = atoi(p+11);
	minut = atoi(p+14);
	second = atoi(p+17);
	delete header;
}

#endif


BOOL ISOTIME::before(ISOTIME &isotime)
{
	BOOL isBefore = FALSE;
	LESS_THAN_TEST(year,isotime.year);
	LESS_THAN_TEST(month,isotime.month);
	LESS_THAN_TEST(day,isotime.day);
	LESS_THAN_TEST(hour,isotime.hour);
	LESS_THAN_TEST(minute,isotime.minute);
	LESS_THAN_TEST(second,isotime.second);

	return isBefore;//equal
	//���ʱ����isotime֮ǰ isotime>this
	
}

BOOL ISOTIME::expired()
{
	//�����������ǲ��ǹ���, ���ھ������ڵ�ʱ���Ѿ���'���ʱ��'֮��
	SYSTEMTIME systemtime;
	GetLocalTime(&systemtime);
	BOOL isAfter = FALSE;
	LESS_THAN_TEST(year,systemtime.wYear);
	LESS_THAN_TEST(month,systemtime.wMonth);
	LESS_THAN_TEST(day,systemtime.wDay);
	LESS_THAN_TEST(hour,systemtime.wHour);
	LESS_THAN_TEST(minute,systemtime.wMinute);
	LESS_THAN_TEST(second,systemtime.wSecond);

	return isAfter;
}
BOOL ISOTIME::arrive()
{
	//�����������ǲ��ǵ���, '����' �������ڵ�ʱ���Ѿ���'���ʱ��'֮ǰ
	SYSTEMTIME systemtime;
	GetLocalTime(&systemtime);
	BOOL isArrive = FALSE;
	GREATE_THAN_TEST(systemtime.wYear,year);
	GREATE_THAN_TEST(systemtime.wMonth,month);
	GREATE_THAN_TEST(systemtime.wDay,day);
	GREATE_THAN_TEST(systemtime.wHour,hour);
	GREATE_THAN_TEST(systemtime.wMinute,minute);
	GREATE_THAN_TEST(systemtime.wSecond,second);
	return isArrive;
}


int ISOTIME::diff(ISOTIME &isotime)
{
	
	return absolute()-isotime.absolute();
}

static DWORD getDaysInMonth(DWORD year,DWORD month){
	
	DWORD days = 30;
	if(1==month||3==month||5==month||7==month||8==month||10==month||12==month){
		days = 31;
	}
	if((year%4 == 0&&year%100 !=0)&&month==2){
		days= 29;
	}else{
		days= 28;
	}
	return days;

}
static DWORD getDaysInYear(DWORD year){
	
	DWORD days = 365;
	if((year%4 == 0&&year%100 !=0)){
		days= 366;
	}else{
		days= 365;
	}
	return days;

}
DWORD ISOTIME::absolute()
{
	//based 1900 - 1 -1
	//start from 1900 -1-1 to now

	DWORD days = 0;
	DWORD seconds = 0;
	DWORD totalsec = 0;

	for(int i=1900;i< year;i++){
		days += getDaysInYear(i);
	}	
	for(int j=1;j< month;j++){
		//the current month will not in 
		days +=getDaysInMonth(year,i);
	}
	days += (day-1);
	//this day is not complet!	
	//printf("days = %u\n", days);
	seconds = second + (minute * 60) + (hour*3600);	
	totalsec = days*86400 + seconds;
	
	return totalsec;
}
//operator- (ISOTIME &isotime)
int ISOTIME::operator- (ISOTIME &isotime)
{
	return absolute()-isotime.absolute();
}


//static Handle file

#ifdef _WIN32_WCE
#define LOCAL_JAVASCIPT_PATH     L"\\hard disk\\license\\local.js"
#define LOCAL_JAVASCIPT_WILDCARD    L"\\hard disk\\license\\*.license"
#else
#define LOCAL_JAVASCIPT_PATH     L"d:\\license\\local.js"
#define LOCAL_JAVASCIPT_WILDCARD    L"d:\\license\\*.license"
#endif

static HANDLE javascriptFilehandle = NULL;
static int counter = 0;

void CJavaScriptGenerator::OnStart()
{

	javascriptFilehandle = CreateFile(LOCAL_JAVASCIPT_PATH, 
		GENERIC_WRITE, FILE_SHARE_READ, NULL, 
		OPEN_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, NULL);
	SetEndOfFile(javascriptFilehandle);
	counter = 0;
	//open a file to write 
}

void CJavaScriptGenerator::OnEnd()
{
	CloseHandle(javascriptFilehandle);
}
//vodCertificateList[0] = new CountCertInfo('1','3','1');
//vodCertificateList[1] = new TimeCertInfo('2','30','20' );
//vodCertificateList[2] = new DurationCertInfo('3', '2005-08-15 18:30', '2005-09-05');

BOOL CJavaScriptGenerator::OnFileName(const WCHAR *fileName)
{
	CSerializableCertificate *p =new CSerializableCertificate();
	WCHAR fullFileName[ MAX_PATH ];
	
	wsprintf(fullFileName, TEXT("%s\\%s"),
		LOCAL_STORE_PATH,
		fileName
		);
	//sprintf(line,"%s = %s\r\n",p->GetName(),p->GetValue());
	//wprintf(L"get file %s\n",fullFileName);
	p->FromLocalFile(fullFileName);
	char line[1024];
	if(p->IsNeedDiscard()){
		wprintf(L"check for need %s\n",fullFileName);
		p->Discard();
	}else{
		DWORD len=strlen(line);
		DWORD readLen=0;
		WriteFile(javascriptFilehandle,line,len,&readLen,NULL);
		p->GenerateJavaScriptObject(line,1024,counter);
	}

	counter++;
	delete p;
	return TRUE;
}
//, public CFileListHandle

BOOL CJavaScriptGenerator::UpdateJavaScript()
{
	CFileListHandle *handle = new CJavaScriptGenerator();
	CDirectoryHelper::ListFileName(LOCAL_JAVASCIPT_WILDCARD,handle);
	delete handle;
	return TRUE;
}























