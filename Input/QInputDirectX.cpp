/** \file QInputDirectX.cpp
    \author Manuel Fernández Yáñez
    \date Enero 2003
    \brief Gestión de dispositivos de entrada bajo DirectX. Implementación
**/

#include "stdafx.h"
#include "QInputDirectX.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QInputDirectX::QInputDirectX(QEngine *pEngine)
{
// Direct X Teclado

	if FAILED(DirectInput8Create(pEngine->m_pWindow->m_hInstance, DIRECTINPUT_VERSION, 
        IID_IDirectInput8, (void**)&m_lpDI, NULL)) 
	{ 
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput No pudo se inicializado\n");
	} 
	else
	{ 
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput Inicializado\n");
	} 
	
  
	if FAILED(m_lpDI->CreateDevice(GUID_SysKeyboard, &m_lpDIKeyboardDevice, NULL)) 
	{ 
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput Teclado no pudo ser inicializado\n");
	}
	else
	{
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput Teclado Inicializado\n");
	}


	if FAILED(m_lpDIKeyboardDevice->SetDataFormat(&c_dfDIKeyboard)) 
	{ 
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput Formato de datos para Teclado no pudo ser inicializado\n");
	}
	else
	{
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput Formato de datos para Teclado Inicializado\n");
	} 


	if FAILED(m_lpDIKeyboardDevice->SetCooperativeLevel(pEngine->m_pWindow->m_hWnd,
			  DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)) 
	{ 
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput Nivel Cooperativo para Teclado no pudo ser inicializado\n");
	} 
	else
	{
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput Nivel Cooperativo para Teclado Inicializado\n");
	} 

	// DirectInput Raton


 
	if (FAILED(m_lpDI->CreateDevice(GUID_SysMouse, &m_lpDIMouseDevice, NULL))) 
	{
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput Ratón no pudo ser inicializado\n");	
	}
	else
	{
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput Ratón Inicializado\n");	
	}

	if (FAILED(m_lpDIMouseDevice->SetDataFormat(&c_dfDIMouse))) 
	{
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput Formado de datos para Ratón no pudo ser inicializado\n");	
	}
	else
	{
		pEngine->m_pLog->AddLine("   Init:   CInputManager: DirectInput Formato de datos para Ratón Inicializado\n");	
	}






}

QInputDirectX::~QInputDirectX()
{
   // if (m_lpDI) 
    //{ 
        //if (m_lpDIKeyboardDevice) 
      //  { 
        // Always unacquire device before calling Release(). 
   //         m_lpDIKeyboardDevice->Unacquire(); 
     //       m_lpDIKeyboardDevice->Release();
      //      m_lpDIKeyboardDevice = NULL; 
	//		m_pLog->AddLine("   DeInit: CInputManager: DirectInput Teclado Liberado\n");
      //  } 

		//if (m_lpDIMouseDevice) 
        //{ 
        // Always unacquire device before calling Release(). 
//            m_lpDIMouseDevice->Unacquire(); 
  //          m_lpDIMouseDevice->Release();
    //        m_lpDIMouseDevice = NULL; 
	//		m_pLog->AddLine("   DeInit: CInputManager: DirectInput Ratón Liberado\n");
      //  } 
        //m_lpDI->Release();
  //      m_lpDI = NULL; 
//		m_pLog->AddLine("   DeInit: CInputManager: DirectInput Terminado\n");
//    } 
}
