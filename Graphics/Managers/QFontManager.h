// QFontManager.h: interface for the QFontManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QFONTMANAGER_H__3A5B2319_D7EA_4329_829A_53FAF9F11DEF__INCLUDED_)
#define AFX_QFONTMANAGER_H__3A5B2319_D7EA_4329_829A_53FAF9F11DEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\Shared\TDA\QHoleManager.h"

#include "..\Objects\QFont.h"
#include "..\Objects\QFontOpenGL.h"
#include "..\Objects\QFontDirectX.h"

#define MAX_FONTS 1024

class QFontManager  : public QHoleManager
{
public:
	void Draw2D(int FontID, int x, int y, char *Text);
	int Create2D(char *Name, int Size);
	QFontManager(QEngine *pEngine,unsigned int MaxFonts);
	virtual ~QFontManager();


	QFont		**m_pFontList;
	QEngine	    *m_pEngine;		// Guarda rastro de DC's y demás
};

#endif // !defined(AFX_QFONTMANAGER_H__3A5B2319_D7EA_4329_829A_53FAF9F11DEF__INCLUDED_)
