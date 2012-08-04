// QWindowWin32DirectX.cpp: implementation of the QWindowWin32DirectX class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QWindowWin32DirectX.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QWindowWin32DirectX::QWindowWin32DirectX(HINSTANCE hInstance, int Width, int Height, int nCmdShow, QLog *pLog)
{
	m_pLog = pLog;
// 1 - Registrar la clase de ventana

    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, DefaultWinProc, 0L, 0L, 
                      GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
                      "D3D Tutorial", NULL };
    RegisterClassEx( &wc );

    // 2 - Crear la ventana

    m_hWnd = CreateWindow( "D3D Tutorial", "DirectX API", 
                              WS_OVERLAPPEDWINDOW, 100,100, WIDTH, HEIGHT,
                              GetDesktopWindow(), NULL, wc.hInstance, NULL );

	// 3 - Crear dispositivo Direct3D


	if( NULL == (m_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
	{
		m_pLog->AddLine("   Init:   CDirectXWindow Dispositivo Direct3D principal no pudo ser creado\n");
	}
	else
	{
		m_pLog->AddLine("   Init:   CDirectXWindow Dispositivo Direct3D principal Creado\n");
	}
// 4 - Obtener el modo de visualizacion actual o setear uno propio

    D3DDISPLAYMODE d3ddm;
    if( FAILED( m_pD3D->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &d3ddm ) ) )
        m_pLog->AddLine("   Init:   CDirectXWindow No se pudo obtener la lista de modos de visualización\n");
	 else
		m_pLog->AddLine("   Init:   CDirectXWindow Lista de modos de visualización obtenida\n");
    // Set up the structure used to create the D3DDevice. Most parameters are
    // zeroed out. We set Windowed to TRUE, since we want to do D3D in a
    // window, and then set the SwapEffect to "discard", which is the most
    // efficient method of presenting the back buffer to the display.  And 
    // we request a back buffer format that matches the current desktop display 
    // format.

    D3DPRESENT_PARAMETERS d3dpp; 
    ZeroMemory( &d3dpp, sizeof(d3dpp) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = d3ddm.Format;

    // Create the Direct3D device. Here we are using the default adapter (most
    // systems only have one, unless they have multiple graphics hardware cards
    // installed) and requesting the HAL (which is saying we want the hardware
    // device rather than a software one). Software vertex processing is 
    // specified since we know it will work on all cards. On cards that support 
    // hardware vertex processing, though, we would see a big performance gain 
    // by specifying hardware vertex processing.


	// 5 - Crear dispositivo de renderizado

    if( FAILED( m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &m_pD3DDevice ) ) )
    {
         m_pLog->AddLine("   Init:   CDirectXWindow Dispositivo de renderizado Direct3D No se pudo crear\n");
    }
	else
	{
		 m_pLog->AddLine("   Init:   CDirectXWindow Dispositivo de renderizado Direct3D creado\n");
	}

    // 6 - Mostrar ventana
	ShowCursor(false);
	ShowWindow( m_hWnd, SW_SHOWDEFAULT );
    UpdateWindow( m_hWnd );

}

QWindowWin32DirectX::~QWindowWin32DirectX()
{
if( m_pD3D != NULL) 
        m_pD3D->Release();

    if( m_pD3DDevice != NULL)
       m_pD3DDevice->Release();
}
