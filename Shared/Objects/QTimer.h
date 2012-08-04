/** \file QTimer.h
    \author Manuel Fernández Yáñez
    \date Febrero 2003.
    \brief Objeto temporizador.
**/

#if !defined(AFX_QTIMER_H__790C52C1_94D1_424E_A7C7_B91F78EC3BE8__INCLUDED_)
#define AFX_QTIMER_H__790C52C1_94D1_424E_A7C7_B91F78EC3BE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

/** \author     Manuel Fernández Yáñez
    \date       Febrero 2003
    \ingroup    general
    \brief      Clase que contiene los datos y funciones necesarios para implementar un temporizador de alta resolución.
    \version    1.0

    Se usa principalmente por el objeto QTimerManager.
	
**/


class QTimerManager;

/** \class QTimer QTimer.h "inc/QTimer.h"
 *  \brief Objeto temporizador.
 *
 * Contiene la definicion de un timer, con el objeto de enlazarlos a distintos objetos y eventos a traves del gestor general de temporiszadores. 
 **/

class QTimer  
{
public:
	bool ElapsedInterval();
	QTimer(bool bTimerTypePerformance, float MaxTime, bool Respawn, QTimerManager *pTimerManager);
	virtual ~QTimer();

float		m_TimeElapsed;			/**< Poner en clase friend, ojo */

private:

	QTimerManager	*m_pTimerManager;
	bool		m_bTimerTypePerformance;	/**< Tipo de temporizador */
	float		m_MaxTime;					/**< Valor máximo del temporizador */
	bool		m_Respawn;					/**< si temporizador infinito (destruido desde el exterior, ej. temporizador principal) */
	
};

#endif // !defined(AFX_QTIMER_H__790C52C1_94D1_424E_A7C7_B91F78EC3BE8__INCLUDED_)
