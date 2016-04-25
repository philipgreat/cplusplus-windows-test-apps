// Key.h : Declaration of the CKey

#ifndef __KEY_H_
#define __KEY_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKey
class ATL_NO_VTABLE CKey : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CKey, &CLSID_Key>,
	public IDispatchImpl<IKey, &IID_IKey, &LIBID_TESTCOM2Lib>
{
public:
	CKey()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_KEY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CKey)
	COM_INTERFACE_ENTRY(IKey)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IKey
public:
	STDMETHOD(hashCode)(/*[out,retval]*/BSTR * result);
};

#endif //__KEY_H_
