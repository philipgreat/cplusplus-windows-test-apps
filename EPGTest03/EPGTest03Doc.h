// EPGTest03Doc.h : interface of the CEPGTest03Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EPGTEST03DOC_H__B32D6CD4_FE3F_4E90_81E4_72F777D697CA__INCLUDED_)
#define AFX_EPGTEST03DOC_H__B32D6CD4_FE3F_4E90_81E4_72F777D697CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Activity.h"

class CEPGTest03Doc : public CDocument
{
private:
	void getSampleDoc();
	list<CActivity*> activityList;
	CActivity *currentActivity;

protected: // create from serialization only
	CEPGTest03Doc();
	DECLARE_DYNCREATE(CEPGTest03Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEPGTest03Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CActivity*	evalAction(string actionExpression);
	bool		addActivity(CActivity &activity);
	void		setCurrentAcvitity(CActivity *pAct);
	CActivity*	procEvent(string event);
	CActivity*	findActivity(string activityId);
	CActivity*	gotoActivity(string name);
	CActivity*	getCurrentActivity();
	virtual ~CEPGTest03Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEPGTest03Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EPGTEST03DOC_H__B32D6CD4_FE3F_4E90_81E4_72F777D697CA__INCLUDED_)
