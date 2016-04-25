// Key.cpp : Implementation of CKey
#include "stdafx.h"
#include "TestCom2.h"
#include "Key.h"
#include "HaspKey.h"
/////////////////////////////////////////////////////////////////////////////
// CKey


STDMETHODIMP CKey::hashCode(BSTR *result)
{
	// TODO: Add your implementation code here
	BSTR code = ::SysAllocString(L"D");
	int pass1 = 5277;
	int pass2 = 24547;
	char buffer[64];

	HaspKey *key = new 	HaspKey();
	key->login(pass1,pass2);	
	strcpy(buffer,"this is a good thing");
	key->write(buffer, 48);
	//key->read(buffer, 20);
	WCHAR wbuffer[64];
	::MultiByteToWideChar(0,0,buffer,48,wbuffer,64);


	*result = code;
	::SysFreeString(code);
	return S_OK;
}
/*

#include "HaspKey.h"

/////////////////////////////////////////////////////////////////////////////
// CHaspKey


STDMETHODIMP CHaspKey::hashCode(BSTR *result)
{
	// TODO: Add your implementation code here
	int pass1 = 5277;
	int pass2 = 24547;
	char buffer[64];

	HaspKey *key = new 	HaspKey();
	key->login(pass1,pass2);	
	strcpy(buffer,"this is a good thing");
	//key.write(buffer, 48);
	//key->read(buffer, 20);
	WCHAR wbuffer[64];
	::MultiByteToWideChar(0,0,buffer,48,wbuffer,64);


	BSTR code = ::SysAllocString(L"D");
	*result = code;
	delete key;
	//::SysFreeString(code);
	return S_OK;
}

*/