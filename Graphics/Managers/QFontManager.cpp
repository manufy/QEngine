// QFontManager.cpp: implementation of the QFontManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QFontManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QFontManager::QFontManager(QEngine *pEngine, unsigned int MaxFonts)  : QHoleManager(MaxFonts)
{

	m_pEngine = pEngine;
	m_pFontList = new QFont*[MAX_FONTS];
	
}

QFontManager::~QFontManager()
{
	for (unsigned int i=0;i<m_NumElements;i++)
		delete m_pFontList[i];
	delete [] m_pFontList;
}

int QFontManager::Create2D(char *Name, int Size)
{
	QFont			*pFont;
	
	switch(m_pEngine->m_Renderer)
	{
		case RENDER_OPENGL:		pFont	 = new QFontOpenGL(m_pEngine);
									break;
		case RENDER_DIRECTX:    pFont	 = new QFontDirectX(m_pEngine);
									break;
	}

	pFont->Create2D(Name,Size);
	unsigned int Index = GetNextIndex();
	m_pFontList[Index] = pFont;
	m_NumElements++;
	return (Index);
}

void QFontManager::Draw2D(int FontID, int x, int y, char *Text)
{
	m_pFontList[FontID]->Draw2D(x,y,Text);
}
