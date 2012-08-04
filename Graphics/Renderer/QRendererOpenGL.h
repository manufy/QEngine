/** \file QRendererOpenGL.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Renderizador OpenGL
**/ 
#if !defined(AFX_QRENDEREROPENGL_H__51A034C6_61F7_44A4_9F67_54A8C21396CC__INCLUDED_)
#define AFX_QRENDEREROPENGL_H__51A034C6_61F7_44A4_9F67_54A8C21396CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QRenderer.h"

typedef void (APIENTRY * PFNGLACTIVETEXTUREARBPROC) (GLenum target);
typedef void (APIENTRY * PFNGLCLIENTACTIVETEXTUREARBPROC) (GLenum texture);

#include "QIncludes.h"


class QRendererOpenGL : public QRenderer 
{
public:
	void PreRender();
	void PostRender();
	void Init();
	QRendererOpenGL(QWindowWin32 *pWindowWin32);
	virtual ~QRendererOpenGL();

///PFNGLGENBUFFERSARBPROC glGenBuffersARB;
//PFNGLBUFFERDATAARBPROC glBufferDataARB;

	PFNGLACTIVETEXTUREARBPROC		 glActiveTextureARB;
	PFNGLCLIENTACTIVETEXTUREARBPROC  glClientActiveTextureARB;
	bool IsExtewnsionSupported(char* szTargetExtension);


	bool ARBTextureSupported;
	bool VBOSupported; // 1=si 0=no
};

#endif // !defined(AFX_QRENDEREROPENGL_H__51A034C6_61F7_44A4_9F67_54A8C21396CC__INCLUDED_)
