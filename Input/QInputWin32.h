/** \file QInputWin32.h 
    \author Manuel Fern�ndez Y��ez
    \date Enero-Julio 2003
    \brief Gesti�n de dispositivos de entrada bajo win32. 
**/

#if !defined(AFX_QINPUTWIN32_H__D1C551FB_DA9A_4C83_B2E2_73420D1224FD__INCLUDED_)
#define AFX_QINPUTWIN32_H__D1C551FB_DA9A_4C83_B2E2_73420D1224FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



/** \author     Manuel Fern�ndez Y��ez
    \date       Enero 2003
    \ingroup    entrada
    \brief      Gesti�n de los distintos m�todos de entrada con funciones del API Win32.
    \version    1.0

    Se coordina la accion de lectura datos del teclado y el rat�n solamente.
	No se proporcionan m�todos para trabajar con Force-Feedback.
	
**/

class QInputWin32  
{
public:
	QInputWin32();				/**< Crear el objeto. */
	virtual ~QInputWin32();		/**< Destruir el objeto. */

};

#endif // !defined(AFX_QINPUTWIN32_H__D1C551FB_DA9A_4C83_B2E2_73420D1224FD__INCLUDED_)
