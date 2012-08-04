// QWindowWin32OpenGL.cpp: implementation of the QWindowWin32OpenGL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QWindowWin32OpenGL.h"
#define CLASS_NAME "QEngineClassName"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QWindowWin32OpenGL::QWindowWin32OpenGL(HINSTANCE hInstance, int Width, int Height, int nCmdShow, QLog *pLog)
{

	m_pLog = pLog;	
	m_hWnd = NULL;
	WNDCLASSEX wndclassex = {0};
	

	if(MessageBox(NULL, "¿ Ver en pantalla completa ? (Recommendado)", "Opciones de visualización", MB_YESNO | MB_ICONQUESTION) == IDNO)
		m_bFullScreen = false;

	wndclassex.cbSize = sizeof(WNDCLASSEX);
	wndclassex.style = CS_HREDRAW | CS_VREDRAW;
	wndclassex.lpfnWndProc = DefaultWinProc;
	wndclassex.hInstance = hInstance;	
	wndclassex.lpszClassName = CLASS_NAME;
	wndclassex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	RegisterClassEx(&wndclassex); // Registra clase de ventana


	DWORD win_style = WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
// cambiar ancho y alto con respecto a resolucion escogida  a fullscreen
 if (m_bFullScreen) ChangeDisplayMode(Width, Height, false); // Try and change to full screen


	m_hWnd = CreateWindowEx(WS_EX_TOPMOST,
						  CLASS_NAME,
						  "OpenGL API",
						  (m_bFullScreen)?(win_style | WS_POPUP):(win_style | WS_SYSMENU),
						  (m_bFullScreen)?0:CW_USEDEFAULT,
						  (m_bFullScreen)?0:CW_USEDEFAULT,
						  Width,
						  Height,
						  NULL,
						  NULL,
						  hInstance,
						  NULL);

		GetClientRect(m_hWnd, &m_Rect);					// Assign the windows rectangle to a global RECT


		// Comprueba errores al registrar la clase
		if(!m_hWnd)
		{
			ChangeDisplayMode(0,0,true); // Restaurar modo grafico
			UnregisterClass(CLASS_NAME,hInstance);
			//return EXIT_FAILURE;
		}

		srand(GetTickCount()); // Seed random timer

		// If anything we try to initialize fails, we better quit


		// Mostrar la ventana
	
		
		CreateContext(m_hWnd);
		InitGL();
		
		ShowCursor(false);
		ShowWindow(m_hWnd, nCmdShow);
		UpdateWindow(m_hWnd);


}

QWindowWin32OpenGL::~QWindowWin32OpenGL()
{
if (m_hRc)		// Memory leak									
	{
		wglMakeCurrent(NULL, NULL);						// Liberar memoria OpenGL
		wglDeleteContext(m_hRc);						// Borrar contexto de dispositivo OpenGL
	}
	
	if (m_hDc) 
		ReleaseDC(m_hWnd, m_hDc);						// Liberar HDC
		
	if(m_bFullScreen)									// Si estabamos en pantalla completa
	{
		ChangeDisplaySettings(NULL,0);					// Restaurar desktop
		ShowCursor(true);								// Mostrar cursor del raton
	}

	UnregisterClass(CLASS_NAME,m_hInstance);			// Liberar la clase de ventana
}

void QWindowWin32OpenGL::SizeOpenGLScreen(int width, int height)
{

}

void QWindowWin32OpenGL::InitGL()
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0,0,0,1);						// Black Background
	glClearDepth(1.0);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
//	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

//	glEnable(GL_LIGHT0);								// Turn on a light
								// Turn on a light
//	glEnable(GL_LIGHTING);								// Turn on lighting
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	glEnable(GL_BLEND);

	// Once lighting is turned on, we need to enable this to use color.
	glEnable(GL_COLOR_MATERIAL);

	glMatrixMode(GL_PROJECTION); // Set projection matrix
	glLoadIdentity();

	// fov == Field of view in degrees
	// (GLdouble)vp_wid/(GLdouble)height == Aspect Ratio
	// 0.1f == Front clipping plane
	// 150.0f == Back clipping plane E
	gluPerspective(45,(GLdouble)WIDTH/(GLdouble)HEIGHT,0.1f,50000);

	glMatrixMode(GL_MODELVIEW); // Set the model view matrix
	glLoadIdentity(); 

	glViewport(0,0,WIDTH,HEIGHT);

}

bool QWindowWin32OpenGL::CreateContext(HWND m_hWnd)
{
	m_hDc = ::GetDC(m_hWnd);

    if(!SetPixelMode(m_hDc))
    {
	::MessageBox(::GetFocus(),"SetPixelformat Failed!","Error",MB_OK);
	return false;
    }

    m_hRc = wglCreateContext(m_hDc);


	 // ESTA LINEA DAba MEMORI LEAKES
    wglMakeCurrent(m_hDc,m_hRc);
	return true;
}

bool QWindowWin32OpenGL::ChangeDisplayMode(int pixel_width, int pixel_height, bool switch_back)
{
// If we're switching back to "our normal resolution"
	if(switch_back)
	{
		// By passing in NULL we're saying "Go back to screen resolution logged in the registry"
		// 0 says "do this dynamically (like now)"
		// **Note this should not fail, that's why we don't check (could if you wanted to)
		ChangeDisplaySettings(NULL,0);
			return true;
	}

	DEVMODE dev_mode = {0};
	LONG result;

	// This call is going to get us the current display settings -- By parameter:
	// NULL -- This specifies which display device (NULL means current display device)
	// ENUM_CURRENT_SETTINGS -- Retrieve the current settings for the display device
	// dev_mode -- Address of DEVMODE structure to fill with the display settings
	if(!EnumDisplaySettings(NULL,ENUM_CURRENT_SETTINGS,&dev_mode))
		return false;

	// We have a DEVMODE filled with all the current settings
	// so lets change the ones we want to
	dev_mode.dmPelsWidth = pixel_width;
	dev_mode.dmPelsHeight = pixel_height;
	
	// Now we'll try to change to the new settings
	// CDS_FULLSCREEN -- flag says this change is "temporary" (there are other flags you can pass in)
	result = ChangeDisplaySettings(&dev_mode,CDS_FULLSCREEN);

	// ChangeDisplaySettings() returns DISP_CHANGE_SUCCESSFUL when it's successful
	if(result == DISP_CHANGE_SUCCESSFUL)
		return true;
	else
		return false; // No changing to full screen :(
}

bool QWindowWin32OpenGL::SetPixelMode(HDC hdc)
{
 PIXELFORMATDESCRIPTOR *ppfd; 
    int pixelformat; 
 


  /*  PIXELFORMATDESCRIPTOR pfd = { 
    sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd 
    1,                     // version number 
    PFD_DRAW_TO_WINDOW |   // support window 
    PFD_SUPPORT_OPENGL |   // support OpenGL 
//    PFD_GENERIC_FORMAT |
    PFD_DOUBLEBUFFER,      // double buffered 
    PFD_TYPE_RGBA,         // RGBA type 
    24,                    // 24-bit color depth 
    0, 0, 0, 0, 0, 0,      // color bits ignored 
    2,                     // no alpha buffer 
    0,                     // shift bit ignored 
    0,                     // no accumulation buffer 
    0, 0, 0, 0,            // accum bits ignored 
    0,                     // 32-bit z-buffer	 
    0,                     // no stencil buffer 
    0,                     // no auxiliary buffer 
    PFD_MAIN_PLANE,        // main layer 
    0,                     // reserved 
    0, 0, 0                // layer masks ignored 
    }; 


*/

	PIXELFORMATDESCRIPTOR pfd = {0};

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);			// Set the size of the structure
    pfd.nVersion = 1;									// Always set this to 1
														// Pass in the appropriate OpenGL flags
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
    pfd.dwLayerMask = PFD_MAIN_PLANE;					// We want the standard mask (this is ignored anyway)
    pfd.iPixelType = PFD_TYPE_RGBA;						// We want RGB and Alpha pixel type
    pfd.cColorBits = 32;						// Here we use our #define for the color bits
    pfd.cDepthBits = 32;						// Depthbits is ignored for RGBA, but we do it anyway
    pfd.cAccumBits = 0;									// No special bitplanes needed
    pfd.cStencilBits = 0;





   
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
 
	return true;
}
