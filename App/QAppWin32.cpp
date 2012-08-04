// QAppWin32.cpp: implementation of the QAppWin32 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QAppWin32.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QAppWin32::QAppWin32(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)

{
	// Primero, inicializa el Logger
	
		m_pLog			 = new QLog("Log.txt"); // pasar como parametro
		m_pLog->AddLine("   Init:   QAppWin32: Constructor\n");

	// Luego, leeria la configuracion de la aplicacion

		m_Renderer		= RENDER_OPENGL;
		m_Input			= INPUT_WIN32;	
	
	// Crea la ventana de visualizacion (Win32 OpenGL ó DirectX)

		switch(m_Renderer)
		{
		case RENDER_OPENGL: 
							m_pWindow = new QWindowWin32OpenGL(hInstance, WIDTH,HEIGHT, nCmdShow, m_pLog);							
							break;
		case RENDER_DIRECTX:
							m_pWindow = new QWindowWin32DirectX(hInstance, WIDTH,HEIGHT, nCmdShow, m_pLog);
							break;
		}



	// Inicializa Timers

		m_pTimerManager	 = new QTimerManager();
		m_AppTimerID	 =  m_pTimerManager->AddTimer(1,1); // Timer continuo (1 seg.) y Respawn (1)
//
	// Inicializa Sonido

		//m_pSoundManager	 = new QSoundManager(m_pLog, m_pWindow->m_hWnd);
		//m_pSoundManager->Play();

	// Inicializa Gestor de dispositivos de entrada, Motor 3D y Lógica del Juego

		m_pEngine		 = new QEngine(m_pWindow,m_Renderer, m_Input, m_pTimerManager, m_pLog,WIDTH, HEIGHT); 
		m_pInputManager = m_pEngine->m_pInputManager;	
	// Pre-Inicializa el juego propiamente dicho

		//CFont *Fuente	 = new CFont();	// Crea una fuente de sistema, desde aqui porque se ve el DC
		m_pCamera = new QCamera();
		m_pCamera->PositionCamera(0, 0, 0,  0 ,0,1,   0, 1, 0);
		
		m_pEngine->m_pFontManager->Create2D("Arial",12);

	//	Fuente->Create2D(m_pWindow->m_hGLDc,"Arial",12);	// FontID 0 Letra pequeña
		//m_pEngine3D->m_pFontManager->AddFont(Fuente);
	
	// Inicializa el juego
///////////////////// MEWTER EN MAIN


//		m_pAppCore		 = new CDemoAsteroids(m_pTimerManager, m_pLog, m_pInputManager,m_pEngine3D); 
//		m_pAppCore		 = new CDemoAsteroids(m_pTimerManager,m_pLog, m_pInputManager,m_pEngine3D);


}

QAppWin32::~QAppWin32()
{
	delete m_pEngine;
	delete m_pWindow;
	delete m_pCamera;
	delete m_pLog;
	delete m_pTimerManager;
	delete m_pInputManager;
}

void QAppWin32::Idle()
{
	SetWindowText(m_pWindow->m_hWnd,"Estado: Idle()");
}

void QAppWin32::Run()
{

	// Bucle infinito. La madre de todas las aplicaciones.
//	
	while(1)
	{
		if(PeekMessage(&m_pWindow->m_Msg,m_pWindow->m_hWnd,0,0,PM_REMOVE)) // Despachar mensajes, si los hay
		{
			if(m_pWindow->m_Msg.message == WM_QUIT)			 // QUIT
				break;
				
			TranslateMessage(&m_pWindow->m_Msg);
			DispatchMessage(&m_pWindow->m_Msg);
		};
		m_pInputManager->GetInput();	// Leer dispositivos de entrada

		// AVERIGUAR QUE PASA CON POSTQUITMESSAGE

		if (m_pInputManager->m_Keys[VK_ESCAPE] == true) 
		{			PostQuitMessage(0);
		break;}
		m_pTimerManager->Step();
		
		m_pEngine->Cycle(m_pTimerManager->m_TimeElapsed);
		m_pAppCore->Cycle(m_pTimerManager->m_TimeElapsed); // Actualizar timer global
		m_pCamera->SetViewByMouse();
		m_pCamera->SetViewFromKeys(m_pEngine->m_pInputManager->m_Keys);
	
	//	if (m_pTimerManager->m_pTimers[m_pEngine->m_FrameTimerID]->ElapsedInterval()) // Si el Timer ID del FrameTimer es cierto , han pasado mas de 1 /FRAMERATE segundos

		{
		
			SetWindowText(m_pWindow->m_hWnd,"Estado: Render()");
			m_pEngine->PreRender();
			m_pCamera->Look();
			m_pEngine->Render();
			m_pAppCore->Render();		
			m_pEngine->PostRender();
		}
	//	else
		{
	//		Idle();
		}
		
	} 
}
