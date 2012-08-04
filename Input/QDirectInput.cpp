// QDirectInput.cpp: implementation of the QDirectInput class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QDirectInput.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QDirectInput::QDirectInput()
{
// Direct X Teclado

/*	if FAILED(DirectInput8Create(m_hInstance, DIRECTINPUT_VERSION, 
        IID_IDirectInput8, (void**)&m_lpDI, NULL)) 
	{ 
		m_pLog->AddLine("   Init:   CInputManager: DirectInput No pudo se inicializado\n");
	} 
	else
	{ 
		m_pLog->AddLine("   Init:   CInputManager: DirectInput Inicializado\n");
	} 
	
  
	if FAILED(m_lpDI->CreateDevice(GUID_SysKeyboard, &m_lpDIKeyboardDevice, NULL)) 
	{ 
		m_pLog->AddLine("   Init:   CInputManager: DirectInput Teclado no pudo ser inicializado\n");
	}
	else
	{
		m_pLog->AddLine("   Init:   CInputManager: DirectInput Teclado Inicializado\n");
	}


	if FAILED(m_lpDIKeyboardDevice->SetDataFormat(&c_dfDIKeyboard)) 
	{ 
		m_pLog->AddLine("   Init:   CInputManager: DirectInput Formato de datos para Teclado no pudo ser inicializado\n");
	}
	else
	{
		m_pLog->AddLine("   Init:   CInputManager: DirectInput Formato de datos para Teclado Inicializado\n");
	} 


	if FAILED(m_lpDIKeyboardDevice->SetCooperativeLevel(m_hWnd,
			  DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)) 
	{ 
		m_pLog->AddLine("   Init:   CInputManager: DirectInput Nivel Cooperativo para Teclado no pudo ser inicializado\n");
	} 
	else
	{
		m_pLog->AddLine("   Init:   CInputManager: DirectInput Nivel Cooperativo para Teclado Inicializado\n");
	} 

	// DirectInput Raton


 
	if (FAILED(m_lpDI->CreateDevice(GUID_SysMouse, &m_lpDIMouseDevice, NULL))) 
	{
		m_pLog->AddLine("   Init:   CInputManager: DirectInput Ratón no pudo ser inicializado\n");	
	}
	else
	{
		m_pLog->AddLine("   Init:   CInputManager: DirectInput Ratón Inicializado\n");	
	}

	if (FAILED(m_lpDIMouseDevice->SetDataFormat(&c_dfDIMouse))) 
	{
		m_pLog->AddLine("   Init:   CInputManager: DirectInput Formado de datos para Ratón no pudo ser inicializado\n");	
	}
	else
	{
		m_pLog->AddLine("   Init:   CInputManager: DirectInput Formato de datos para Ratón Inicializado\n");	
	}




*/


}

QDirectInput::~QDirectInput()
{

}
