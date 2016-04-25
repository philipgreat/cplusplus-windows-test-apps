// HelpTool.h : Declaration of the CHelpTool
#include "stdafx.h"
#ifndef __HELPTOOL_H_
#define __HELPTOOL_H_

#include "resource.h"       // main symbols
#include <atlwin.h>
/////////////////////////////////////////////////////////////////////////////
// CHelpTool


class ATL_NO_VTABLE CHelpTool : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHelpTool, &CLSID_HelpTool>,
	public IDispatchImpl<IHelpTool, &IID_IHelpTool, &LIBID_KNOWLEDGEBASELib>
{
private:
	WCHAR sendTo[256];
	WCHAR postURL[2048];
	HWND  parentWindow;
public:

	CHelpTool()
	{
		parentWindow = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HELPTOOL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CHelpTool)
	COM_INTERFACE_ENTRY(IHelpTool)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IHelpTool
public:
	STDMETHOD(setParent)(CWindow window);
	void LoadConfiguration();
	STDMETHOD(AddToHelpStore)(/*[in]*/ BSTR title,/*[in]*/ BSTR content, /*[in]*/ BSTR keywords);
};

#endif //__HELPTOOL_H_
