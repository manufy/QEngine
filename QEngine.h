/** \file QEngine.h
    \author Manuel Fernández Yáñez
    \date Octubre 2002 - Diciembre 2003.
    \brief Objeto principal QEngine.
**/

/*! \class QEngine QEngine.h "inc/QEngine.h"
 *  \brief Clase QEngine que contiene un mundo 3D.
 *
 *  Exporta todas las funciones visibles al programador de demos, videojuegos o aplicaciones;
 */

/** \author     Manuel Fernández Yáñez
    \date       Octubre 2002 - Diciembre 2003.
    \ingroup    general
    \brief      Objeto principal, núcleo de las aplicaciones 3D. Ofrece funcionalidad para visualizar y tratar con gráficos, sonido y dispositivos de entrada.
    \version    1.0

    Se usa desde aplicaciones externas al proyecto QEngine.
	
**/
#if !defined(AFX_QENGINE_H__9BC5DD34_7837_43D2_8CAF_ADC00E6C7B8A__INCLUDED_)
#define AFX_QENGINE_H__9BC5DD34_7837_43D2_8CAF_ADC00E6C7B8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Includes válidos para cualquier aplicación

#define WIDTH 800
#define HEIGHT 600

enum eQActorType { ACTOR_CREATE, ACTOR_DYNAMIC, ACTOR_STATIC, ACTOR_IA, ACTOR_PLAYER, ACTOR_TERMINATE };

enum eQRenderer { RENDER_OPENGL, RENDER_DIRECTX };
enum eQInput { INPUT_DIRECTX, INPUT_WIN32 };

#define FRAME_RATE 30
#define MAX_TEXTURES 1024
#define MAX_FONTS 1024
#define MAX_MESHES_PER_MODEL 20000

#define MAX_VERTEX 100000
#define MAX_TRIANGLES 100000
#define MAX_PRIMITIVES_PER_MESH 20000
#define MAX_KEYFRAMES_PER_MODEL 20000

#include "QIncludes.h"
#include "QEngineDemo.h"

class QEngine  
{

public:
	void Stats();
	void BeginRender(HDC hDC, HGLRC hglRC); // ,LPDIRECT3DDEVICE8 pD3DDevice);
	void EndRender(HDC hDC); //,LPDIRECT3DDEVICE8 pD3DDevice);
	void PostRender();
	void PreRender();
	void Render();
	
	void Cycle(float DeltaTime);

	void SetRenderer(int Renderer);

	
	QEngine(QWindowWin32 *pWindow,int Renderer, int Input, QTimerManager *pTimerManager,  QLog *pLog, int Width, int Height);
	QEngine::QEngine(int Renderer);
	virtual ~QEngine();

	QLog			 *m_pLog;				// Log
	QTimerManager	 *m_pTimerManager;		// Gestor de Timers
	int				 m_TimerID;				// Timer del Render
	QRenderer		 *m_pRenderer;			// OpenGL ó DirectX
	int				  m_Renderer;			// Idem en int
	QInputManager	 *m_pInputManager;
	QFontManager	 *m_pFontManager;
	QWindowWin32	 *m_pWindow;
	QTextureManager	 *m_pTextureManager;
	
	QVertexManager	    *m_pVertexManager;
	QTriangleManager	*m_pTriangleManager;

	QEngineDemo			*m_pTest;

	unsigned int		m_FramesRendered;
	unsigned int		m_FrameTimerID;
	unsigned int		m_FrameCounterTimerID;
	char				m_strFrameRate[80];
	char				m_strTimer[80];
	int LoadConfiguration(char *strFileName);
};

#endif // !defined(AFX_QENGINE_H__9BC5DD34_7837_43D2_8CAF_ADC00E6C7B8A__INCLUDED_)
