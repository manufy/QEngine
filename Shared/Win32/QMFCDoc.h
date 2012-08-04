#if !defined(AFX_QMFCDOC_H__181FE781_0D34_46D9_8751_30C32DD90983__INCLUDED_)
#define AFX_QMFCDOC_H__181FE781_0D34_46D9_8751_30C32DD90983__INCLUDED_

#include "..\..\QEngine.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\QEngine.h"
#include "QMFCApp.h"	// Added by ClassView

class QEngine;
// QMFCDoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// QMFCDoc document

class QMFCDoc : public CDocument
{
protected:
	QMFCDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(QMFCDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(QMFCDoc)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	QMFCApp* GetApp();

	QEngine *m_pEngine;
	virtual ~QMFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(QMFCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QMFCDOC_H__181FE781_0D34_46D9_8751_30C32DD90983__INCLUDED_)
