// HaspKey.h : Declaration of the CHaspKey

#ifndef __HASPKEY_H_
#define __HASPKEY_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHaspKey
class ATL_NO_VTABLE CHaspKey : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHaspKey, &CLSID_HaspKey>,
	public IDispatchImpl<IHaspKey, &IID_IHaspKey, &LIBID_SECURITYSETLib>
{
public:
	CHaspKey()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HASPKEY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CHaspKey)
	COM_INTERFACE_ENTRY(IHaspKey)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IHaspKey
public:
	STDMETHOD(applyToken)(BSTR url,BSTR cookie,/*[out, retval]*/ BSTR* result);
	STDMETHOD(login)(/*[in]*/BSTR url,/*[in]*/BSTR username, /*[in]*/BSTR password,/*[out,retval]*/BSTR *result);

	//STDMETHOD(hashCode)(/*[out,retval]*/BSTR *result);
};

#endif //__HASPKEY_H_
