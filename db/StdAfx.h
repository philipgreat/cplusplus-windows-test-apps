// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__28EBFF0B_E1DD_11D4_93AC_0000E8233645__INCLUDED_)
#define AFX_STDAFX_H__28EBFF0B_E1DD_11D4_93AC_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <afxcview.h>
#include "mainfrm.h"
#include "mysql.h"

#include "terapicoregkey.h"
#define	REG_KEY_PATH	("SOFTWARE\\TeraPico\\HelpSystem\\GUI")
#define	REG_KEY_KEY		("WindowTile")	
#define SETTITLE(X)	(CTeraPicoRegKey::SetValue(REG_KEY_PATH,REG_KEY_KEY,(X)))
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__28EBFF0B_E1DD_11D4_93AC_0000E8233645__INCLUDED_)
