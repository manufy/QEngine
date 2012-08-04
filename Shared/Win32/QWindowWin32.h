// QWindowWin32.h: interface for the QWindowWin32 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QWindowWin32_H__54DE6CB6_6726_40E8_A6A1_882A6D53DE0B__INCLUDED_)
#define AFX_QWindowWin32_H__54DE6CB6_6726_40E8_A6A1_882A6D53DE0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class QWindowWin32
{
public:
	void PostRender();
	void PreRender();
	QWindowWin32();
	virtual ~QWindowWin32();

	// OpenGL

	HGLRC		m_hRc;
	HDC			m_hDc;


	// Win32

	HINSTANCE	m_hInstance;
	HINSTANCE	m_hPrevInstance;
	LPSTR		m_lpCmdLine;
	int			m_nCmdShow;
	HWND		m_hWnd;
	MSG			m_Msg;

	// DirectX

	LPDIRECT3D9             m_pD3D;		// Dispositivo Direct3D
	LPDIRECT3DDEVICE9       m_pD3DDevice;

	// Aplicacion

	QLog		*m_pLog;
	RECT		m_Rect;
	bool		m_bFullScreen;
};

#endif // !defined(AFX_QWindowWin32_H__54DE6CB6_6726_40E8_A6A1_882A6D53DE0B__INCLUDED_)
