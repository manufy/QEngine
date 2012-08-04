/** \file QWindowWin32OpenGL.h
    \author Manuel Fernández Yáñez
    \date Enero 2003
    \brief Encapsula una ventana DirectX en entorno Windows
**/

#if !defined(AFX_QWINDOWWIN32DIRECTX_H__9A1A5BBE_518B_498B_96D5_763845BE3768__INCLUDED_)
#define AFX_QWINDOWWIN32DIRECTX_H__9A1A5BBE_518B_498B_96D5_763845BE3768__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QWindowWin32.h"

LRESULT CALLBACK DefaultWinProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);


class QWindowWin32DirectX  : public QWindowWin32
{
public:
	QWindowWin32DirectX(HINSTANCE hInstance, int Width, int Height, int nCmdShow, QLog *pLog);
	virtual ~QWindowWin32DirectX();
	

};

#endif // !defined(AFX_QWINDOWWIN32DIRECTX_H__9A1A5BBE_518B_498B_96D5_763845BE3768__INCLUDED_)
