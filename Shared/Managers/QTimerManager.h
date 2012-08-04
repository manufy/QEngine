/** \file QTimerManager.h
    \author Manuel Fernández Yáñez
    \date Febrero 2003.
    \brief Objeto gestor de te temporizadores.
**/



#if !defined(AFX_QTIMERMANAGER_H__5F7DDB21_8960_44AA_A217_E7A91FEA88A0__INCLUDED_)
#define AFX_QTIMERMANAGER_H__5F7DDB21_8960_44AA_A217_E7A91FEA88A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "..\TDA\QHoleManager.h"


#define MAX_TIMERS 1024

/** \author     Manuel Fernández Yáñez
    \date       Febrero 2003
    \ingroup    general
    \brief      Objeto gestor de te temporizadores.
    \version    1.0

    Se usa para gestionar los distintos objetos QTimer que surgen durante el tiempo de vida de una aplicación. El timer 0 siempre sera el contador general, base para el cálculo de FPS.
	
**/


/** \class QTimerManager QTimerManager.h "inc/QTimerManager.h"
 *  \brief Objeto gestor de te temporizadores.
 *
 * Contiene la definicion de un timer, con el objeto de enlazarlos a distintos objetos y eventos a traves del gestor general de temporiszadores. 
 **/

class QTimer;

class QTimerManager : public QHoleManager 
{
public:
	void Step();
	int AddTimer(float Time, bool Respawn);
	QTimerManager();
	virtual ~QTimerManager();
// Variables publicas

	float		m_Seconds;					// Añacir clase CTimeStamp
	float		m_TimeElapsed;				// Tiempo transcurrido (Segundos). Reinicializado constantemente.
	QTimer		**m_pTimers;				// Array de punteros a los Timers hijos. Mejorar haciendo linked lists.(trivial)

private:
	void GetCurrentTime();
	__int64		m_LastTime;				    // Ultimo valor del temporizador coordinador (Contador)
	__int64		m_CurrentTime;				// Valor actual del temporizador coordinador (Contador)
	bool		m_bTimerTypePerformance;	// Tipo de temporizador timeGetTime o queryperf...
	double		m_TimeFactor;				// Factor de escalado de tiempo

};

#endif // !defined(AFX_QTIMERMANAGER_H__5F7DDB21_8960_44AA_A217_E7A91FEA88A0__INCLUDED_)
