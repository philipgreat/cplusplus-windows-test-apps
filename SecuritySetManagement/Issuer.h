// Issuer.h : Declaration of the CIssuer

#ifndef __ISSUER_H_
#define __ISSUER_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CIssuer
class ATL_NO_VTABLE CIssuer : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIssuer, &CLSID_Issuer>,
	public IDispatchImpl<IIssuer, &IID_IIssuer, &LIBID_SECURITYSETMANAGEMENTLib>
{
public:
	CIssuer()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ISSUER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CIssuer)
	COM_INTERFACE_ENTRY(IIssuer)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IIssuer
public:
	STDMETHOD(issue)(BSTR url, BSTR username, BSTR password, /*[out,retval]*/ BSTR *result);
};

#endif //__ISSUER_H_
