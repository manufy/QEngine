// QWindowWin32OpenGL.h: interface for the QWindowWin32OpenGL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QWINDOWWIN32OPENGL_H__543BB30B_A9E9_442F_9BEB_C3D63F7B8208__INCLUDED_)
#define AFX_QWINDOWWIN32OPENGL_H__543BB30B_A9E9_442F_9BEB_C3D63F7B8208__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QWindowWin32.h"

LRESULT CALLBACK DefaultWinProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

class QWindowWin32OpenGL  : public QWindowWin32
{
public:
	bool SetPixelMode(HDC hdc);
	bool ChangeDisplayMode(int pixel_width, int pixel_height, bool switch_back);
	bool CreateContext(HWND m_hWnd);
	void InitGL();
	void SizeOpenGLScreen(int width, int height);
	QWindowWin32OpenGL(HINSTANCE hInstance, int Width, int Height, int nCmdShow, QLog *pLog);


	virtual ~QWindowWin32OpenGL();
	
};

#endif // !defined(AFX_QWINDOWWIN32OPENGL_H__543BB30B_A9E9_442F_9BEB_C3D63F7B8208__INCLUDED_)
