// MicrosoftAccess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <comdef.h>
#define INITGUID
#import "c:\Program Files\Common Files\System\ADO\msado15.dll"     no_namespace rename("EOF", "EndOfFile")




int main(int argc, char* argv[])
{


	
	if(FAILED(::CoInitialize(NULL)))
        return 1;
	
	HRESULT hr = S_OK;
	_ConnectionPtr con("ADODB.Connection");
    _RecordsetPtr rs("ADODB.Recordset");
	


	try{
		con->put_Provider(_T("Microsoft.Jet.OLEDB.4.0"));
		con->Open("DSN=MTSSamples", "", "", adAsyncConnect);
		

		rs->Open(
			"select * from student_data where id='19'", 
			_variant_t(con->ConnectionString),			
			adOpenStatic, 
			adLockReadOnly , 
			adCmdText);

		rs->MoveFirst ();
		
		_bstr_t(rs->GetCollect("name")).copy() ;


		//con->Execute (

	}catch (HRESULT hr){
		
		::MessageBox(NULL,"Error on Open","OK!",0);
	}



	::CoUninitialize();
	return 0;
}
