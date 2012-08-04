// QOpenGLRenderer.h: interface for the QOpenGLRenderer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QOPENGLRENDERER_H__C2C4845E_1AF5_4EA4_ACF3_70CA57ED7339__INCLUDED_)
#define AFX_QOPENGLRENDERER_H__C2C4845E_1AF5_4EA4_ACF3_70CA57ED7339__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QRenderer.h"


class QOpenGLRenderer  : public QRenderer
{
public:
	void PostRender();
	void PreRender();
	void Init();
	QOpenGLRenderer();
	virtual ~QOpenGLRenderer();



	

};

#endif // !defined(AFX_QOPENGLRENDERER_H__C2C4845E_1AF5_4EA4_ACF3_70CA57ED7339__INCLUDED_)
