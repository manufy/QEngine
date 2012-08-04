// QMFCViewOpenGL.h: interface for the QMFCViewOpenGL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QMFCVIEWOPENGL_H__FE67C05B_C99E_4523_AF9D_BF940F6DC880__INCLUDED_)
#define AFX_QMFCVIEWOPENGL_H__FE67C05B_C99E_4523_AF9D_BF940F6DC880__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QMFCView.h"

class QMFCViewOpenGL  : public QMFCView
{
protected:

	QMFCViewOpenGL();
	DECLARE_DYNCREATE(QMFCViewOpenGL)

public:
	
	virtual ~QMFCViewOpenGL();

	// Funciones sobrecargadas
	// Funciones virtuales sobrecargadas generadas por el ClassWizard automáticamente
	//{{AFX_VIRTUAL(QMFCViewOpenGL)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);   /** Pre-inicializa la vista OpenGL.  \param cs Estructura de clase de ventana.  */
	//}}AFX_VIRTUAL


		HDC m_hgldc;       /**< Contexto de Dispositivo GDI */
		HGLRC m_hglrc;     /**< Contexto de Renderizado */
protected:

	
	//{{AFX_MSG(QMFCViewOpenGL)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);    /** Creación e inicialización de la vista.  */
	afx_msg void OnSize(UINT nType, int cx, int cy);        /** Recalcular coordenadas de vista cuando cambian las dimensiones de la misma. */
	DECLARE_MESSAGE_MAP()

};

#endif // !defined(AFX_QMFCVIEWOPENGL_H__FE67C05B_C99E_4523_AF9D_BF940F6DC880__INCLUDED_)
