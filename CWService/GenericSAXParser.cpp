// GenericSAXParser.cpp: implementation of the CGenericSAXParser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GenericSAXParser.h"
#include <atlbase.h>

//����DOMģ��ʵ��
#pragma comment(lib, "comsupp.lib");
#pragma comment(lib, "MsXml2.Lib");
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGenericSAXParser::CGenericSAXParser():handle(NULL)
{
	//��ʼ��Com���
	HRESULT hr = CoInitialize(NULL);
}

CGenericSAXParser::~CGenericSAXParser()
{
	CoUninitialize();
}

BOOL CGenericSAXParser::SetHandle(CAbstractHandle *handle)
{
	if(NULL!=handle)
	{
		this->handle=handle;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

static enum XML_PARSE_STATE{
	XML_INIT=0,XML_DOCUMENT_STARTED,XML_DOCUMENT_ENDED,XML_ELEMENT_NEXT,
		XML_ELEMENT_STARTED, XML_ELEMENT_IN, XML_ELEMENT_ENDED, 
		XML_TAG_STARTED, XML_TAG_IN, XML_TAG_ENDED, 
		XML_PROP_NAME_STARTED, XML_NAME_IN, XML_PROP_NAME_ENDED, XML_PROP_EQUAL,
		XML_PROP_VALUE_STARTED,	XML_PROP_VALUE_IN, XML_PROP_VALUE_ENDED,
		XML_DOCUMENT_ERROR

};
/*********************************************************************************\
	!�öδ��뾭�����ϸ��״̬���������벻Ҫ����޸ĸöδ��룬 �޸��κ�һ�п���Ӱ��
	������(	2005-09-28 ), �öδ��������Ч�ʺܸ�, ֻ��Ҫһ��ѭ���ͽ�������XML
	Ŀǰ��ʱ��֧��
		<?xml encoding= version= ?>
	�����ĵ����ϸ���Ҫ���Ǻܸ�(����XML�ɲ�һ���Ǻ���) 
\*********************************************************************************/
/*
int CGenericSAXParser::Parse(const char *xmlText)
{
	char *p = NULL;
	char *header = NULL;
	int len = strlen(xmlText)+1 ;
	char  currentQuote = '\'';

	int currentState = XML_INIT;
	char *currentElement = NULL;
	char *currentName = NULL;
	char *currentValue = NULL;

	p= header = new char[len];

	memcpy(p,xmlText,len);
	if(handle==NULL) return -1;

	//ASSERT(handle!=NULL);
	while(p - header < len ){
		switch(currentState){
			case XML_INIT: 
				currentState = XML_ELEMENT_NEXT;				
				//break;
			case XML_ELEMENT_NEXT: 
				if(*p=='<') {
					currentState = XML_ELEMENT_STARTED;	
					handle->StartDocument();
				}
				break;

			case XML_ELEMENT_STARTED: 
				if(*p=='/'){
					handle->EndElement();
					currentState = XML_ELEMENT_ENDED;
				}else	if(!isalpha(*p)){
					currentState = XML_DOCUMENT_ERROR;
				}else{
					currentState = XML_TAG_STARTED;
					currentElement = p;
				}
				break;

			case XML_TAG_STARTED:
				if(isspace(*p)||'\t' == *p){
					currentState = XML_TAG_ENDED;
					*p = 0 ;
					handle->StartElement(currentElement);
				}
				if(*p=='>'){
					*p = 0 ;
					handle->StartElement(currentElement);
					currentState = XML_ELEMENT_NEXT;
					//��ʱ����
					//Ӧ�ûص�StartElement
				}
				break;
			case XML_TAG_ENDED:
				if(isalpha(*p)){
					currentState = XML_PROP_NAME_STARTED;
					currentName = p;
				}
				break;
			case XML_PROP_NAME_STARTED:
				if(isspace(*p)||'\t' == *p){
					currentState = XML_PROP_NAME_ENDED;
					*p = 0;//end of the name;
				}else if('=' == *p){
					*p = 0;
					currentState= XML_PROP_EQUAL;
				}
				break;
			case XML_PROP_NAME_ENDED:
				if(*p == '='){
					currentState = XML_PROP_EQUAL;					
				}
				break;
			case XML_PROP_EQUAL:
				if(*p == '\'' || *p == '\"'){
					currentQuote = *p ;
					currentState = XML_PROP_VALUE_STARTED;
					currentValue = p + 1;
					//*p = 0;//end of the name;
				}
				break;

			case XML_PROP_VALUE_STARTED:
				if(currentQuote == *p){
					currentState = XML_PROP_VALUE_ENDED;
					//currentName = p;
					*p = 0;
					handle ->OnProperty (currentElement,currentName,currentValue);
				}
				break;
			case XML_PROP_VALUE_ENDED:
				if(isalpha(*p)){
					currentState = XML_PROP_NAME_STARTED;
					currentName = p;
					//there someproblem here
				}
				if(*p=='/'){
					handle->EndElement();
					currentState = XML_ELEMENT_ENDED;
				}
				if(*p=='>'){
					*p = 0 ;
					handle->StartElement(currentElement);
					currentState = XML_ELEMENT_NEXT;
				}
				break;
			case XML_ELEMENT_ENDED:
				if(*p=='<'){
					currentState = XML_ELEMENT_STARTED;
					//currentName = p;
				}
				break;
			default:
				break;

		}
		if(currentState == XML_DOCUMENT_ERROR){
			//printf("document error\n");
			handle ->OnError (currentElement,currentName,currentValue);
			//break;
		}
		p++;
	
	}
	if(currentState!= XML_INIT) handle->EndDocument();

//clearup:
	//delete p;
	delete header;
	return 0;
}
*/


/*
��дʹ��DOMģ��������xml�ַ���
*/
BOOL CGenericSAXParser::Parse(const char *xmlText)
{
	HRESULT hr;
	IXMLDOMDocument *pDoc = NULL;
	BOOL ReturnResult = false;
	hr = CoCreateInstance(CLSID_DOMDocument,NULL,CLSCTX_INPROC_SERVER,
		IID_IXMLDOMDocument,(void **)&pDoc);
	if(FAILED(hr))
	{
		return ReturnResult;
	}
	hr = pDoc->put_async(VARIANT_FALSE);
	//ת��һ���ַ�������
	CComBSTR XMLStr = xmlText;
	VARIANT_BOOL VB;
	hr = pDoc->loadXML(XMLStr,&VB);
	//VB�Ƿ�ɹ�
	if(FAILED(hr)&&!VB)
	{
		return ReturnResult;
	}
	
	IXMLDOMNode *root = NULL;
	pDoc->get_documentElement((IXMLDOMElement **)&root);
	if(root==NULL)
	{
		return ReturnResult;
	}
	//�������еĽ��
	BOOL B = ForeachNode(root);
	if(B==FALSE)
	{
		return ReturnResult;
	}
	root->Release();
	pDoc->Release();
	return TRUE;
}

BOOL CGenericSAXParser::ForeachNode(IXMLDOMNode *pNode)
{
	
	HRESULT hr;
	//��ȡ�������ƺͽ���ֵ
	char *pNodeName,*pNodeValue;
	char *pArrtibuteName,*pAttributeValue;
	BSTR bStrValue;

	//����������Ͳ���NODE_ELEMENT,�򷵻ء�
	DOMNodeType nodeType;
	hr = pNode->get_nodeType(&nodeType);
	if(FAILED(hr))
	{
		return false;
	}
	//���������Ͳ���NODE_ELEMENT,�򷵻�
	if(nodeType!=NODE_ELEMENT)
	{
		return false;
	}
	//��ȡ�������
	hr = pNode->get_nodeName(&bStrValue);
	if(SUCCEEDED(hr))
	{
		pNodeName = _com_util::ConvertBSTRToString(bStrValue);
		::SysFreeString(bStrValue);
	}
	else
	{
		return false;
	}
	//��ȡ����ֵ
	hr = pNode->get_text(&bStrValue);
	if(SUCCEEDED(hr))
	{
		pNodeValue = _com_util::ConvertBSTRToString(bStrValue);
		::SysFreeString(bStrValue);
		//��ÿ������ֵ���д���
		VARIANT_BOOL vb;
		hr =  pNode->hasChildNodes(&vb);
		if(SUCCEEDED(hr)&&vb)
		{
			this->handle->OnProperty(pNodeName,pNodeName,pNodeValue);
		}
	}
	else
	{
		return false;
	}
	//����������������
	IXMLDOMNamedNodeMap *pAttributeList = NULL; 
	hr = pNode->get_attributes(&pAttributeList);
	if(FAILED(hr))
	{
		return false;
	}
	long attributeLength; 
	hr = pAttributeList->get_length(&attributeLength);
	if(FAILED(hr))
	{
		return false;
	}
	for(int i =0;i<attributeLength;i++)
	{
		IXMLDOMNode *pAttribute = NULL;
		hr = pAttributeList->get_item(i,(IXMLDOMNode **)&pAttribute);;
		if(SUCCEEDED(hr))
		{
			//��ȡ���Ե����ƺ����Ե�ֵ
			hr = pAttribute->get_nodeName(&bStrValue);
			if(SUCCEEDED(hr))
			{
				pArrtibuteName = _com_util::ConvertBSTRToString(bStrValue);
				::SysFreeString(bStrValue);
			}
			hr = pAttribute->get_text(&bStrValue);
			if(SUCCEEDED(hr))
			{
				pAttributeValue = _com_util::ConvertBSTRToString(bStrValue);
				::SysFreeString(bStrValue);
				this->handle->OnProperty(pNodeName,pArrtibuteName,pAttributeValue);
				delete[] pArrtibuteName;
				delete[] pAttributeValue;
			}
		}
		pAttribute->Release();
	}
	//�ͷŽ��
	pAttributeList->Release();


	//�������������ӽ��	
	IXMLDOMNodeList *pNodeList = NULL;
	hr =  pNode->get_childNodes(&(pNodeList));
	if(FAILED(hr))
	{
		return FALSE;
	}
	long nodeLength;
	hr = pNodeList->get_length(&nodeLength);
	if(FAILED(hr))
	{
		return false;
	}
	for(int i=0;i<nodeLength;i++)
	{
		IXMLDOMNode *pChildNode = NULL;
		hr = pNodeList->get_item(i,&pChildNode);
		if(SUCCEEDED(hr))
		{
			ForeachNode(pChildNode);
			pChildNode->Release();
		}
	}
	pNodeList->Release();
	delete[] pNodeName;
	delete[] pNodeValue;
	return TRUE;
}
