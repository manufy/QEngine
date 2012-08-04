// QEngine.cpp: implementation of the QEngine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QEngine.h"
#include ".\qengine.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


QEngine::QEngine(QWindowWin32 *pWindow, int Renderer, int Input, QTimerManager *pTimerManager,  QLog *pLog, int Width, int Height)
{
	m_pTest = new QEngineDemo;
	m_pLog = pLog;
	m_pWindow = pWindow;
	m_pTimerManager = pTimerManager;
	m_pInputManager = new QInputManager(this);
	m_pFontManager  = new QFontManager(this, MAX_FONTS);
	m_pTextureManager	= new QTextureManager(this,MAX_TEXTURES);

	SetRenderer(Renderer); // ojojjojo
	//m_pInputManager->SelectMode(Renderer)
	m_FrameTimerID		    = m_pTimerManager->AddTimer((float)1.0 / FRAME_RATE ,1); // Normalmente 50 Hz, con Respawn (infinito)
	m_FrameCounterTimerID   = m_pTimerManager->AddTimer(1.0 ,1);			  // 1 Segundo, con Respawn (infinito)
	
	m_FramesRendered		= 0;
	sprintf(m_strFrameRate, "Cuadros por Segundo: Calculando ...");


	m_pVertexManager = new QVertexManager(MAX_VERTEX);
	m_pTriangleManager = new QTriangleManager(m_pVertexManager, MAX_TRIANGLES);


}

QEngine::QEngine(int Renderer)
{
	m_pTest = new QEngineDemo;
	m_pLog = new QLog("Log.txt");
	m_pTimerManager = new QTimerManager;
	m_pInputManager = new QInputManager(this);
	m_pFontManager  = new QFontManager(this, MAX_FONTS);
	m_pTextureManager	= new QTextureManager(this,MAX_TEXTURES);
	
	
	SetRenderer(Renderer); // ojojjojo
	m_FrameTimerID		    = m_pTimerManager->AddTimer((float)1.0 / FRAME_RATE ,1); // Normalmente 50 Hz, con Respawn (infinito)
	m_FrameCounterTimerID   = m_pTimerManager->AddTimer(1.0 ,1);			  // 1 Segundo, con Respawn (infinito)
	
	m_FramesRendered		= 0;
	sprintf(m_strFrameRate, "Cuadros por Segundo: Calculando ...");

	m_pVertexManager = new QVertexManager(MAX_VERTEX);
	m_pTriangleManager = new QTriangleManager(m_pVertexManager, MAX_TRIANGLES);
}



QEngine::~QEngine()
{

	

	delete m_pTest;
	delete m_pRenderer;
	delete m_pTextureManager;
	delete m_pFontManager;
	delete m_pVertexManager;
	delete m_pTriangleManager;

}

void QEngine::SetRenderer(int Renderer)
{
	// Borrar anterior, si habia

	switch(Renderer)
	{
		case RENDER_OPENGL:  m_pRenderer = new QRendererOpenGL(m_pWindow);
			

							 break;
		case RENDER_DIRECTX: m_pRenderer = new QRendererDirectX(m_pWindow);
							 break;	
	}
	m_Renderer = Renderer;

}



void QEngine::Cycle(float DeltaTime)
{
	
}

void QEngine::Render()
{


	// This function was added to give a better feeling of moving around.
	// A black background just doesn't give it to ya :)  We just draw 100
	// green lines vertical and horizontal along the X and Z axis.

	glDisable(GL_TEXTURE_2D);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_DEPTH_TEST);
//glLoadIdentity(); 
	
	//m_pTest->Suelo();
	//m_pTest->Axes();

	// Turn the lines GREEN
//	glColor3ub(0, 255, 0);

	// Draw a 1x1 grid along the X and Z axis'







	m_FramesRendered++;
	if (m_pTimerManager->m_pTimers[m_FrameCounterTimerID]->ElapsedInterval()) // Si el Timer ID del FrameTimer es cierto , han pasado mas de 1 /FRAMERATE segundos
		{ 
			sprintf(m_strFrameRate, "Cuadros por Segundo: %d",m_FramesRendered);
			m_FramesRendered = 0;
		}
	
	Stats();
}

void QEngine::PreRender()
{
	// Borra pantalla

 	m_pRenderer->PreRender();

}

void QEngine::PostRender()
{
	m_pRenderer->PostRender();
}

void QEngine::BeginRender(HDC hDC,HGLRC hglRC) //,LPDIRECT3DDEVICE8 pD3DDevice)
{
	switch(m_Renderer)
	{
		case RENDER_OPENGL:  wglMakeCurrent( hDC, hglRC );
							glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Borrar pantalla
							glLoadIdentity();

							 break;
		case RENDER_DIRECTX: m_pWindow->m_pD3DDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,255), 1.0f, 0 );
							m_pWindow->m_pD3DDevice->BeginScene();
							


							 break;
	}	
	

}



void QEngine::EndRender(HDC hDC) // ,LPDIRECT3DDEVICE8 pD3DDevice)
{
	switch(m_Renderer)
	{
		case RENDER_OPENGL:  SwapBuffers(hDC);
						
							 break;
		case RENDER_DIRECTX: 
							m_pWindow->m_pD3DDevice->EndScene();
							m_pWindow->m_pD3DDevice->Present( NULL, NULL, NULL, NULL );
							break;
	}	
	

}


void QEngine::Stats()
{
	glDisable(GL_TEXTURE_2D); // PA QUE SALGA TEXTO BLANCO
	glColor3f(1,1,1);
	//sprintf(m_strFrameRate, "Cuadros por Segundo: %d",m_FramesRendered);
	m_pFontManager->Draw2D(0,0,HEIGHT-65,m_strFrameRate);
	sprintf(m_strTimer, "Timer: %f",m_pTimerManager->m_pTimers[m_FrameTimerID]->m_TimeElapsed);
	m_pFontManager->Draw2D(0,0,HEIGHT-85,m_strTimer);

/*	switch (m_eEngineMode)
	{
		case ENGINE3D_SHOOTER:  m_pFontManager->Draw2D(0,0,HEIGHT-50,"ENGINE3D_SHOOTER");
								break;
		case ENGINE3D_3RDPERSON:m_pFontManager->Draw2D(0,0,HEIGHT-50,"ENGINE3D_3RDPERSON");
								break;
		case ENGINE3D_STRATEGY: m_pFontManager->Draw2D(0,0,HEIGHT-50,"ENGINE3D_STRATEGY");
								break;
	}
	switch (m_Renderer)
	{
		case RENDER_API_OPENGL:	 m_pFontManager->Draw2D(0,0,HEIGHT-80,"Renderer: OpenGL");
								break;
		case RENDER_API_DIRECTX: m_pFontManager->Draw2D(0,0,HEIGHT-80,"Renderer: DirectX");
								break;  */
}

int QEngine::LoadConfiguration(char *strFileName)
{	
	char Buffer[255];
	FILE *pFile;
	pFile = fopen(strFileName,"r");
	while (!feof(pFile))
	{ 
		Buffer[0] = 0;			 // Marca Buffer vacio
		fgets(Buffer,254,pFile); // Leer Linea
		
		

		// Procesar linea leida

		switch (Buffer[0])
		{
			case 0:   break;	// Linea vacia
			case '#': break;	// Linea de comentario
//			case 'I': LoadInstance(pFile);	
//					  break;
		//	case 'A': LoadActor(pFile);
		//			  break;
//			case 'P': LoadParticleSystem(pFile);
			default: break;
					 
		}

	}
	fclose(pFile);
	return 0;
}
