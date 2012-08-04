// QRendererDirectX.cpp: implementation of the QRendererDirectX class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QRendererDirectX.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QRendererDirectX::QRendererDirectX(QWindowWin32 *pWindowWin32) : QRenderer(pWindowWin32)
{
// 1 - Registrar la clase de ventana

   WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, DefaultWinProc, 0L, 0L, 
                      GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
                     "D3D Tutorial", NULL };
   RegisterClassEx( &wc );

    // 2 - Crear la ventana

    m_pWindowWin32->m_hWnd = CreateWindow( "D3D Tutorial", "DirectX API", 
                             WS_OVERLAPPEDWINDOW, 100,100, 800, 600,
                              GetDesktopWindow(), NULL, wc.hInstance, NULL );

	// 3 - Crear dispositivo Direct3D

	if( NULL == ( pWindowWin32->m_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
	{
//		m_pLog->AddLine("   Init:   CDirectXWindow Dispositivo Direct3D principal no pudo ser creado\n");
	}
	else
	{
	//	m_pLog->AddLine("   Init:   CDirectXWindow Dispositivo Direct3D principal Creado\n");
	}

	// 4 - Obtener el modo de visualizacion actual o setear uno propio

    D3DDISPLAYMODE d3ddm;
   if( FAILED( pWindowWin32->m_pD3D->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &d3ddm ) ) );
      //  m_pLog->AddLine("   Init:   CDirectXWindow No se pudo obtener la lista de modos de visualización\n");
	// else
	//	m_pLog->AddLine("   Init:   CDirectXWindow Lista de modos de visualización obtenida\n");
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

    if( FAILED( pWindowWin32->m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, pWindowWin32->m_hWnd,
                                     D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                     &d3dpp, &pWindowWin32->m_pD3DDevice ) ) )
    {
     //    m_pLog->AddLine("   Init:   CDirectXWindow Dispositivo de renderizado Direct3D No se pudo crear\n");
    }
	else
	{
	//	 m_pLog->AddLine("   Init:   CDirectXWindow Dispositivo de renderizado Direct3D creado\n");
	}

    // 6 - Mostrar ventana
	ShowCursor(false);
	ShowWindow( pWindowWin32->m_hWnd, SW_SHOWDEFAULT );
    UpdateWindow( pWindowWin32->m_hWnd ); 
}

QRendererDirectX::~QRendererDirectX()
{

}

void QRendererDirectX::PreRender()
{
// Fondo AZUL
//
    m_pWindowWin32->m_pD3DDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,255), 1.0f, 0 );
    
    // Comienza la escena Direct3D

   m_pWindowWin32->m_pD3DDevice->BeginScene();
          
}

void QRendererDirectX::PostRender()
{// Finalizar escena Direct3D

    m_pWindowWin32->m_pD3DDevice->EndScene();
    
    // Volcar el backbuffer

    m_pWindowWin32->m_pD3DDevice->Present( NULL, NULL, NULL, NULL );

}

void QRendererDirectX::Init()
{

}
