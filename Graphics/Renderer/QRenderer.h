/** \file QRenderer.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Renderizador
	\todo Distintos tipos. Raytracing.
**/
#if !defined(AFX_QRENDERER_H__4ACBD23B_4C7B_4E18_9E4D_E30B815B462C__INCLUDED_)
#define AFX_QRENDERER_H__4ACBD23B_4C7B_4E18_9E4D_E30B815B462C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\Shared\Win32\QWindowWin32.h"

class QRenderer  
{
public:
	virtual void Init();
	virtual void PostRender();
	virtual void PreRender();
	QRenderer(QWindowWin32 *pWindowWin32);
	virtual ~QRenderer();


	// Variables publicas 

	// OpenGL - Handles de dispositivos para visualizacion

	// OpenGL

	QWindowWin32 *m_pWindowWin32;
};

#endif // !defined(AFX_QRENDERER_H__4ACBD23B_4C7B_4E18_9E4D_E30B815B462C__INCLUDED_)
