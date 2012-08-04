/** \file QAppWin32.h
    \author Manuel Fernández Yáñez
    \date Enero 2003
    \brief Núcleo de una aplicación básica en modo demo para Win32.
**/
#if !defined(AFX_QAPPWIN32_H__12D3D7D2_2E91_4E8F_9E55_C078E27D99DA__INCLUDED_)
#define AFX_QAPPWIN32_H__12D3D7D2_2E91_4E8F_9E55_C078E27D99DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QWin32App;
class QEngine;
class QInputManager;
class QLog;
class QFontManager;

#include "..\Shared\Managers\QTimerManager.h"
#include "..\Shared\Objects\QLog.h"
#include "..\Shared\Win32\QWindowWin32.h"
#include "QAppCore.h"
#include "..\QEngine.h"

class QAppWin32  
{
public:


	virtual void Run();
	void Idle();
	QAppWin32(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow);
	virtual ~QAppWin32();


	QAppCore		*m_pAppCore;			// Clase encapsulando el juego de los asteroides
	QEngine			*m_pEngine;			// Motor grafico 3D
	QInputManager	*m_pInputManager;		// Manejador de dispositivos de entrada
	QTimerManager	*m_pTimerManager;		// Gestor de temporizadores
//	QSoundManager	*m_pSoundManager;		// Sonido 
	QLog			*m_pLog;				// Logger

	eQRenderer		 m_Renderer;			// Renderizador: OpenGL / DirectX
	eQInput			 m_Input;				// API para Input Win32 / DirectX
	int				 m_AppTimerID;			// Timer de la aplicacion

	QWindowWin32	 *m_pWindow;
	QCamera		     *m_pCamera;

};

#endif // !defined(AFX_QAPPWIN32_H__12D3D7D2_2E91_4E8F_9E55_C078E27D99DA__INCLUDED_)
