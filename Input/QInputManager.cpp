/** \file QInputManager.cpp
    \author Manuel Fernández Yáñez
    \date Enero 2003
    \brief Gestión de dispositivos de entrada. Implementación
**/

#include "stdafx.h"
#include "QInputManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QInputManager::QInputManager(QEngine *pEngine)
{
	ResetKeys();
}

QInputManager::~QInputManager()
{
/*	m_pLog->AddLine("   DeInit: CInputManager: Destructor\n");

*/	
}

void QInputManager::ResetKeys()
{
// Actualiza LastKeys y Resetea Keys

	for(int i=0;i<MAX_KEYS;i++) 
		{ 
			m_LastKeys[i] = m_Keys[i];
			m_Keys[i] = false; 
		}
}

void QInputManager::GetKeys()
{
	ResetKeys();



	// VK_ Cursores

	m_Keys[VK_UP] = (GetAsyncKeyState(VK_UP) & 0x8000) != 0;
	m_Keys[VK_DOWN] = (GetAsyncKeyState(VK_DOWN) & 0x8000) != 0;
	m_Keys[VK_LEFT] = (GetAsyncKeyState(VK_LEFT) & 0x8000) != 0;
	m_Keys[VK_RIGHT] = (GetAsyncKeyState(VK_RIGHT) & 0x8000) != 0;
	m_Keys[VK_F1] = (GetAsyncKeyState(VK_F1) & 0x8000) != 0; 

	m_Keys[VK_ESCAPE] = (GetAsyncKeyState(VK_ESCAPE) & 0x8000) != 0; 
	
	m_Keys[VK_F1] = (GetAsyncKeyState(VK_F1) & 0x8000) != 0; 
	m_Keys[VK_F2] = (GetAsyncKeyState(VK_F2) & 0x8000) != 0; 
		
	m_Keys[VK_RETURN] = (GetAsyncKeyState(VK_RETURN) & 0x8000) != 0; 
	m_Keys[VK_SPACE] = (GetAsyncKeyState(VK_SPACE) & 0x8000) != 0; 
	m_Keys[VK_TAB] = (GetAsyncKeyState(VK_TAB) & 0x8000) != 0; 

	// Lee de la A a la Z
	
	for (unsigned int i=0x41;i<0x5A;i++)
	{
		m_Keys[i] = ((GetAsyncKeyState(i) & 0x8000) != 0); 

	}; 
}

void QInputManager::GetMouse()
{

}

void QInputManager::GetJoystick()
{

}

void QInputManager::GetGlove()
{

}

void QInputManager::GetInput()
{
	GetMouse();
	GetKeys();
	GetJoystick();
	GetGlove();
}
