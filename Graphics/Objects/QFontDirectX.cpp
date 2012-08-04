// QFontDirectX.cpp: implementation of the QFontDirectX class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QFontDirectX.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QFontDirectX::QFontDirectX(QEngine *pEngine) : QFont (pEngine)
{

}

QFontDirectX::~QFontDirectX()
{

}

void QFontDirectX::Create2D(char *Name, int Size)
{
//	_tcscpy( m_strFontName, Name );

	// Inicializa Dispositivo Direct3D
//	LOGFONT LogFont = {14,0,0,0,FW_NORMAL,false,false,false,DEFAULT_CHARSET,OUT_TT_PRECIS,CLIP_DEFAULT_PRECIS,PROOF_QUALITY,DEFAULT_PITCH,"Arial"};
//
//	if(FAILED(D3DXCreateFontIndirect(m_pEngine->m_pWindow->m_pDirect3DDevice,&LogFont,&m_Font)))				//create font
//	{
//		 MessageBox(m_pEngine->m_pWindow->m_hWnd,"D3DXCreateFontIndirect() failed!","WinMain()",MB_OK);
//			 int g_bRunning = false;
//	 }
}

void QFontDirectX::Draw2D(int x, int y, char *Text)
{	
//	RECT FontPosition = {0,0,WIDTH,HEIGHT};								//text position


  //m_Font->Begin();		
  //FontPosition.top = y;	
  //F/ontPosition.left = x;
  //m_Font->DrawText(Text,-1,&FontPosition,DT_TOP | DT_SINGLELINE,0xffffffff);	//draw text

 // FontPosition.top = 100;									//position
  //m_Font->DrawText("Text Sample Using D3DXFont",-1,&FontPosition,DT_CENTER,0xffff0000);		//draw text
  //m_Font->End();

}
