// QRendererOpenGL.cpp: implementation of the QRendererOpenGL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QRendererOpenGL.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QRendererOpenGL::QRendererOpenGL(QWindowWin32 *pWindowWin32) : QRenderer(pWindowWin32)
{
	int c = 3;
	c++;
	c--;
	int b=c-3;
}

QRendererOpenGL::~QRendererOpenGL()
{

}

void QRendererOpenGL::Init()
{
// Inicializa Multitextura .. comprobar si se admite
	glActiveTextureARB		 = NULL;
	glClientActiveTextureARB = NULL;
	glActiveTextureARB		 = (PFNGLACTIVETEXTUREARBPROC)	 wglGetProcAddress("glActiveTextureARB");
    glClientActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)   wglGetProcAddress("glClientActiveTextureARB");


}

void QRendererOpenGL::PostRender()
{
	SwapBuffers(m_pWindowWin32->m_hDc);
}

void QRendererOpenGL::PreRender()
{
	wglMakeCurrent( m_pWindowWin32->m_hDc, m_pWindowWin32->m_hRc );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Borrar pantalla
	glLoadIdentity();

}
