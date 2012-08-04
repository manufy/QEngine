/** \file QInputManager.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Gestión de dispositivos de entrada
	
**/

#if !defined(AFX_QINPUTMANAGER_H__9EDE6249_78AF_413E_8F11_A5988C35F8F6__INCLUDED_)
#define AFX_QINPUTMANAGER_H__9EDE6249_78AF_413E_8F11_A5988C35F8F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_KEYS 101


/** \author     Manuel Fernández Yáñez
    \date       Enero 2003
    \ingroup    entrada
    \brief      Gestión de los distintos métodos de entrada, abstrayendo el hardware
    \version    1.0

    Se coordina la accion de lectura datos de los dispositivos de entrada (tecado, joystick, pad, guante). 
	Tambien se proporcionan métodos para trabajar con Force-Feedback
	
**/
class QEngine;

class QInputManager  
{
private:

	void GetGlove();			/**< Obtener estado del Guante. */
	void GetJoystick();			/**< Obtener estado del Joystick. */
	void GetMouse();			/**< Obtener estado del Ratón. */
	void GetKeys();				/**< Obtener estado del Teclado. */
	void ResetKeys();		    /**< Inicializar buffer de teclas leidas. */ 

public:
	void GetInput();			/**< Obtener estado de todos los dispositivos de entrada. */
	
	
	QInputManager(QEngine *pEngine);			/**< Crear un objeto para gestionar los dispositivos de entrada. */
	
	virtual ~QInputManager();   /**< Destruir el gestor de dispositivos de entrada. */

	bool m_Keys[MAX_KEYS];		/**<  Teclas pulsadas == true */
	bool m_LastKeys[MAX_KEYS];	/**<  Teclas pulsadas == true */

	QEngine *m_pEngine;			/**<  Puntero al QEngine que posee este QInputManager */
};

#endif // !defined(AFX_QINPUTMANAGER_H__9EDE6249_78AF_413E_8F11_A5988C35F8F6__INCLUDED_)
