/** \file QRendererDirectX.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Renderizador DirectX
**/ 
#if !defined(AFX_QRENDERERDIRECTX_H__145BFD3F_F5A7_404B_A0B6_4F1A73F15215__INCLUDED_)
#define AFX_QRENDERERDIRECTX_H__145BFD3F_F5A7_404B_A0B6_4F1A73F15215__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QRenderer.h"

class QRendererDirectX  : public QRenderer
{
public:
	void Init();
	void PostRender();
	void PreRender();
	QRendererDirectX(QWindowWin32 *pWindowWin32);
	virtual ~QRendererDirectX();

};

#endif // !defined(AFX_QRENDERERDIRECTX_H__145BFD3F_F5A7_404B_A0B6_4F1A73F15215__INCLUDED_)
