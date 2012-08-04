// QMFCDoc.cpp : implementation file
//

#include "stdafx.h"
#include "QMFCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// QMFCDoc

IMPLEMENT_DYNCREATE(QMFCDoc, CDocument)

QMFCDoc::QMFCDoc()
{
	int a = GetApp()->m_Renderer;
	m_pEngine = new QEngine(a); // OpenGL, DirectX
	// Crea fuente del sistema QEngine

//	m_pEngine->m_pFontManager->Create2D("Arial",12);
}

BOOL QMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// Inicializa Engine con el Hardware / APIs definidos por la aplicación
	// Estos deben haber sido inicializados también por la aplicación




	return TRUE;
}

QMFCDoc::~QMFCDoc()
{
//	delete m_pEngine;
}


BEGIN_MESSAGE_MAP(QMFCDoc, CDocument)
	//{{AFX_MSG_MAP(QMFCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// QMFCDoc diagnostics

#ifdef _DEBUG
void QMFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void QMFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// QMFCDoc serialization

void QMFCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// QMFCDoc commands


QMFCApp* QMFCDoc::GetApp()
{
	return (QMFCApp *) AfxGetApp();
}
