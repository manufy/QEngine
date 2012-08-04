/** \file QMFCView.cpp
    \author Manuel Fernández Yáñez
    \date Enero 2003
    \brief Implementa QMFCView:public CView (MFC)
**/

#include "stdafx.h"
#include "QMFCView.h"
#include "..\..\QEngine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(QMFCView, CView)

QMFCView::QMFCView()
{
}

QMFCView::~QMFCView()
{	
//	wglMakeCurrent(NULL,NULL);
//    wglDeleteContext(m_hglrc);
}


BEGIN_MESSAGE_MAP(QMFCView, CView)
	//{{AFX_MSG_MAP(QMFCView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void QMFCView::OnDraw(CDC* pDC)
{
	
}

#ifdef _DEBUG // _DEBUG
void QMFCView::AssertValid() const
{
	CView::AssertValid();
}

void QMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// QMFCView message handlers

int QMFCView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
	return -1;
	
	// Recupera la configuración del Engine de la aplicación

//	QMFCDoc* pDoc = GetDocument();                     // Obtiene referencia al documento padre
//	switch (pDoc->m_pEngine->m_Renderer)
//	{
	 /*	case RENDER_OPENGL:                            // Inicializa OpenGL
						    m_hgldc = ::GetDC(m_hWnd); // Obtiene DC
							if(!SetPixelMode(m_hgldc)) // Selecciona el modo de visualizacion (bpp)
							{
								::MessageBox(::GetFocus(),"SetPixelformat Failed!","Error",MB_OK);  // Error
								return -1;
							}
							m_hglrc = wglCreateContext(m_hgldc);        // Crea contexto de visualización
							wglMakeCurrent(m_hgldc,m_hglrc);            // Hace el contexto activo
							InitGL();                                   // Inicializa pipeline OpenGL
							break; 

	*/  //case RENDER_DIRECTX:	break;
//	}
  	m_pCamera = new QCamera;			                              // Crea la cámara de vista
	return 0;
}

void QMFCView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);                                  // Llama al evento de la clase padre
	

	QMFCDoc* pDoc = GetDocument();	                               // Obtiene puntero al documento activo
	switch (pDoc->m_pEngine->m_Renderer)                
	{

		case RENDER_OPENGL:                                                                 // Para OpenGL
							wglMakeCurrent( m_hgldc, m_hglrc );                             // Hace activo el contexto de visualización creado para la vista


							glViewport(0,0,cx,cy);											// Reinicializa el ViewPort
																					
							glMatrixMode(GL_PROJECTION);								    // Selecciona la matriz de proyección 
							glLoadIdentity();												// La inicializa
	
							gluPerspective(45.0f,(GLfloat)cx/(GLfloat)cy,0.1f,100.0f);		// Calcula el ratio de aspecto

							glMatrixMode(GL_MODELVIEW);										// Selecciona la matriz de vista
							glLoadIdentity();                                               // La inicializa
							break;
		case RENDER_DIRECTX: 


							break;
	}
}
void QMFCView::OnInitialUpdate()
{
	if((m_pEngine->m_Renderer) == RENDER_DIRECTX)
	{
//if( NULL == (m_pDirect3D = Direct3DCreate8( D3D_SDK_VERSION ) ))
//								::MessageBox(::GetFocus(),"SetPixelformat Failed!","Error",MB_OK);
								

//					D3DDISPLAYMODE d3ddm;
//					m_pDirect3D->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &d3ddm );

			
			// Set up the structure used to create the D3DDevice
  //  D3DPRESENT_PARAMETERS d3dpp;
    //ZeroMemory( &d3dpp, sizeof(d3dpp) );
    //d3dpp.Windowed = TRUE;
   // d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
  //  d3dpp.BackBufferFormat = d3ddm.Format;
  //  d3dpp.EnableAutoDepthStencil = TRUE;
  //  d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

			
//	if( FAILED(m_pDirect3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd,
 //              D3DCREATE_SOFTWARE_VERTEXPROCESSING,
 //              &d3dpp, &m_pDirect3DDevice))) 
//	   ::MessageBox(::GetFocus(),"SetPixelfoormat Failed!","Error",MB_OK);
			









	}

	
	
	
	
	CView::OnInitialUpdate();
}
int QMFCView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class

	//	QMFCDoc* pDoc = GetDocument();
//	switch (m_pEngine->m_Renderer)
//	{
//	case RENDER_OPENGL:	
		/*			cs.lpszClass = ::AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC, 
						::LoadCursor(NULL, IDC_ARROW), NULL, NULL); 
						cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN; 
		*/	//			break;
//	}

//	cs.style |= WS_OVERLAPPED;

	return CView::PreCreateWindow(cs);
}

bool QMFCView::SetPixelMode(HDC hdc)
{
	PIXELFORMATDESCRIPTOR *ppfd; 
    int pixelformat; 
 
    PIXELFORMATDESCRIPTOR pfd = { 
    sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd 
    1,                     // version number 
    PFD_DRAW_TO_WINDOW |   // support window 
    PFD_SUPPORT_OPENGL |   // support OpenGL 
    PFD_GENERIC_FORMAT |
    PFD_DOUBLEBUFFER,      // double buffered 
    PFD_TYPE_RGBA,         // RGBA type 
    32,                    // 24-bit color depth 
    0, 0, 0, 0, 0, 0,      // color bits ignored 
    8,                     // no alpha buffer 
    0,                     // shift bit ignored 
    8,                     // no accumulation buffer 
    0, 0, 0, 0,            // accum bits ignored 
    64,                    // 32-bit z-buffer	 
    8,                     // no stencil buffer 
    8,                     // no auxiliary buffer 
    PFD_MAIN_PLANE,        // main layer 
    0,                     // reserved 
    0, 0, 0                // layer masks ignored 
    }; 

   
    ppfd = &pfd;

 
    if ( (pixelformat = ChoosePixelFormat(hdc, ppfd)) == 0 ) 
    { 
        ::MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK); 
        return FALSE; 
    } 
 
    if (SetPixelFormat(hdc, pixelformat, ppfd) == FALSE) 
    { 
        ::MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK); 
        return FALSE; 
    } 
 
    return TRUE; 
}


bool QMFCView::InitGL()
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(1, 1, 1, 1);					// Black Background
	glClearDepth(1.0);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	return true;
	
	// Initialization Went OK
}

CMDIChildWnd* QMFCView::GetMDIFrame()
{
	CMDIChildWnd * pChild =
          ((CMDIFrameWnd*)(AfxGetApp()->m_pMainWnd))->MDIGetActive();
	return pChild;
}

QMFCDoc* QMFCView::GetDocument()
{
//	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(QMFCDoc))); seria CParticleEditorDoc
	return (QMFCDoc *)m_pDocument;
}

QMFCApp* QMFCView::GetApp()
{
	return (QMFCApp *) AfxGetApp();
}
