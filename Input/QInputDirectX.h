/** \file QInputDirectX.h
    \author Manuel Fernández Yáñez
    \date Enero 2003
    \brief Gestión de dispositivos de entrada bajo DirectX
**/

#if !defined(AFX_QINPUTDIRECTX_H__09280E2B_CD21_46A2_A93B_5F2D411B3536__INCLUDED_)
#define AFX_QINPUTDIRECTX_H__09280E2B_CD21_46A2_A93B_5F2D411B3536__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/** \author     Manuel Fernández Yáñez
    \date       Enero 2003
    \ingroup    entrada 
    \brief      Gestión de dispositivos de entrada mediante DirectX
    \version    1.0

	Actualizado a DirectX 9. Es necesario el SDK de Microsoft para compilar
	
**/

class QInputDirectX  
{
public:

	QInputDirectX(QEngine *pEngine); 
	virtual ~QInputDirectX();		 


	
	LPDIRECTINPUT8  m_lpDI;							/**< Dispositivo DirectInput. */					
	LPDIRECTINPUTDEVICE8  m_lpDIKeyboardDevice ;	/**< Dispositivo de teclado DirectInput. */	
	LPDIRECTINPUTDEVICE8  m_lpDIMouseDevice ;		/**< Dispositivo de ratón DirectInput. */
};

#endif // !defined(AFX_QINPUTDIRECTX_H__09280E2B_CD21_46A2_A93B_5F2D411B3536__INCLUDED_)
