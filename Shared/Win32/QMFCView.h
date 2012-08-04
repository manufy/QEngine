/** \file QMFCView.h 
    \author Manuel Fernández Yáñez
    \date Enero 2003
    \brief Implementa la clase QMFCView:public CView (MFC)
**/


#if !defined(AFX_QMFCVIEW_H__272C695C_E625_4F2F_8FD7_D1986EBE6ABB__INCLUDED_)
#define AFX_QMFCVIEW_H__272C695C_E625_4F2F_8FD7_D1986EBE6ABB__INCLUDED_

#include "..\..\GRAPHICS\OBJECTS\QCamera.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QEngine;
class QMFCDoc;
class QMFCApp;

/** \author     Manuel Fernández Yáñez
    \date       Enero 2003
    \ingroup    win32
    \todo       Implementar clases separadas segun API de renderizado y cambio de CView dinámico en los CSplitterWndEx
    \bug        En OpenGL: Resize MDI no funciona automáticamente
    \brief      Vista en 3D basada en las MFC
    \version    1.0

    Se hace asi (encapsular OpenGL y DirectX) en vez de usar la herencia por cuestion de velocidad y de poder
    cambiar de modo de renderizado sin reinicializar la vista. El dispositivo de renderizado DirectX es inicializado en OnInitialUpdate
    mientras que el dispositivo OpenGL lo es en PreCreateWindow.
**/

class QMFCView : public CView
{
protected:

    /**
    * Constructor protegido, usado para creación dinámica
    * Crea una vista
    */

	QMFCView();           
	DECLARE_DYNCREATE(QMFCView)

	// Atributos

public:
	HDC m_hgldc;       /**< Contexto de Dispositivo GDI */
	HGLRC m_hglrc;     /**< Contexto de Renderizado */

//	LPDIRECT3D8             m_pDirect3D;		/**< Objeto Direct3D. Se pueden tener varios activos. */
//	LPDIRECT3DDEVICE8       m_pDirect3DDevice; /**< Dispositivo de renderizado Direct3D */



	// Operaciones
	
public:
   
	QMFCApp* GetApp();            /** Devuelve un puntero a la QMFCApp (aplicación) activa. */
	QMFCDoc* GetDocument(); 	  /** Devuelve un puntero al QMFCDoc (documento) activo. */
	CMDIChildWnd* GetMDIFrame();  /** Devuelve un puntero a la CMDIChildWnd (Ventana MDI hija) activa. */

	QCamera *m_pCamera;           /**< Cámara enlazada con la vista */
	QEngine *m_pEngine;           /**< QEngine padre */
	bool InitGL();                /** Inicializa OpenGL. */
	bool SetPixelMode(HDC hdc);   /** Selecciona modo de visualización para OpenGL.  \param hdc Handle al contexto de dispositivo. */ 






	// Funciones sobrecargadas
	// Funciones virtuales sobrecargadas generadas por el ClassWizard automáticamente
	//{{AFX_VIRTUAL(QMFCView)
	protected:
	virtual void OnDraw(CDC* pDC);                    /** Dibuja la vista. \param pDC Handle al contexto de dispositivo. */
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);   /** Pre-inicializa la vista OpenGL.  \param cs Estructura de clase de ventana.  */
	virtual void OnInitialUpdate();                   /** Pre-inicializa la vista DirectX.  */
	//}}AFX_VIRTUAL

	// Implementación
protected:

    /**
    * Destructor de la vista.
    * Destruye la vista y libera objetos usados por la misma.
    */
    
	virtual ~QMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


	// Funciones generadas para el mapeo de mensajes
protected:
	//{{AFX_MSG(QMFCView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);    /** Creación e inicialización de la vista.  */
	afx_msg void OnSize(UINT nType, int cx, int cy);        /** Recalcular coordenadas de vista cuando cambian las dimensiones de la misma. */
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QMFCVIEW_H__272C695C_E625_4F2F_8FD7_D1986EBE6ABB__INCLUDED_)
