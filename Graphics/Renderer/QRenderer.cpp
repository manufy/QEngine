// QRenderer.cpp: implementation of the QRenderer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QRenderer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QRenderer::QRenderer(QWindowWin32 *pWindowWin32)
{
 m_pWindowWin32 = pWindowWin32;
}

QRenderer::~QRenderer()
{

}

void QRenderer::PreRender()
{

}

void QRenderer::PostRender()
{

}

void QRenderer::Init()
{

}
