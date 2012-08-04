// QMFCViewOpenGL.cpp: implementation of the QMFCViewOpenGL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QMFCViewOpenGL.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(QMFCViewOpenGL, QMFCView)

BEGIN_MESSAGE_MAP(QMFCViewOpenGL, QMFCView)
	//{{AFX_MSG_MAP(QMFCView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

QMFCViewOpenGL::QMFCViewOpenGL()
{

}

QMFCViewOpenGL::~QMFCViewOpenGL()
{
	wglMakeCurrent(NULL,NULL);
    wglDeleteContext(m_hglrc);
}
BOOL QMFCViewOpenGL::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = ::AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC, 
						::LoadCursor(NULL, IDC_ARROW), NULL, NULL); 
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN; 
	return CView::PreCreateWindow(cs);
}

int QMFCViewOpenGL::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (QMFCView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
    // Inicializa OpenGL
	m_hgldc = ::GetDC(m_hWnd); // Obtiene DC
	if(!SetPixelMode(m_hgldc)) // Selecciona el modo de visualizacion (bpp)
		{
			::MessageBox(::GetFocus(),"SetPixelformat Failed!","Error",MB_OK);  // Error
			return -1;
		}
	m_hglrc = wglCreateContext(m_hgldc);        // Crea contexto de visualización
	wglMakeCurrent(m_hgldc,m_hglrc);            // Hace el contexto activo
	InitGL();                                   // Inicializa pipeline OpenGL

 // 	m_pCamera = new QCamera;			                              // Crea la cámara de vista
	return 0;
}


void QMFCViewOpenGL::OnSize(UINT nType, int cx, int cy) 
{
	QMFCView::OnSize(nType, cx, cy);                                  // Llama al evento de la clase padre
	wglMakeCurrent( m_hgldc, m_hglrc );                             // Hace activo el contexto de visualización creado para la vista
	glViewport(0,0,cx,cy);											// Reinicializa el ViewPort
	glMatrixMode(GL_PROJECTION);								    // Selecciona la matriz de proyección 
	glLoadIdentity();												// La inicializa
	gluPerspective(45.0f,(GLfloat)cx/(GLfloat)cy,0.1f,100.0f);		// Calcula el ratio de aspecto
	glMatrixMode(GL_MODELVIEW);										// Selecciona la matriz de vista
	glLoadIdentity();                                               // La inicializa
}
