// QMFCApp.cpp: implementation of the QMFCApp class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QMFCApp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QMFCApp::QMFCApp()
{

}

QMFCApp::~QMFCApp()
{

}

QMFCApp* QMFCApp::GetApp()
{
	return (QMFCApp *) AfxGetApp();
}

void QMFCApp::LoadConfig()
{

	// Meter "Engine" en un #define 

	m_Renderer = GetProfileInt("Engine","Renderer",0); // OpenGL por defecto
	m_RendererFrames = GetProfileInt("Engine","RendererFrames",30); 
	m_RendererLimitFrames = GetProfileInt("Engine","RendererLimitFrames",0);
	
	m_Renderer = 1;
}

void QMFCApp::SaveConfig()
{
WriteProfileInt("Engine","Renderer",m_Renderer); // Guarda en el registro
	WriteProfileInt("Engine","RendererFrames",m_RendererFrames); // Guarda en el registro
	WriteProfileInt("Engine","RendererLimitFrames",m_RendererLimitFrames); // Guarda en el registro

}
