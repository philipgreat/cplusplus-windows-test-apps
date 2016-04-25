#if !defined(AFX_DEBUGUDP_H__1A97B561_BD6C_4C62_AB6D_2C7A890D1855__INCLUDED_)
#define AFX_DEBUGUDP_H__1A97B561_BD6C_4C62_AB6D_2C7A890D1855__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DebugUDP.h : header file
//

#define  INTERVAL	200

/////////////////////////////////////////////////////////////////////////////
// CDebugUDP command target

class CDebugUDP : public CSocket
{
// Attributes
public:

// Operations
public:
	CDebugUDP();
	long time1;
	CString c;
	CString d;

	virtual ~CDebugUDP();

// Overrides
public:

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDebugUDP)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CDebugUDP)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEBUGUDP_H__1A97B561_BD6C_4C62_AB6D_2C7A890D1855__INCLUDED_)
