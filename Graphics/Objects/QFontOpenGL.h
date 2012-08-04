// QFontOpenGL.h: interface for the QFontOpenGL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QFONTOPENGL_H__509EB655_54C7_4C55_A0D0_3DF3F5A817E3__INCLUDED_)
#define AFX_QFONTOPENGL_H__509EB655_54C7_4C55_A0D0_3DF3F5A817E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QFont.h"
#define MAX_CHARS 256

class QFontOpenGL  : public QFont
{
public:
	void Create2D(char *strFontName, int Size);
	void Draw2D(int x, int y, char *strText);
	QFontOpenGL(QEngine *pEngine);
	virtual ~QFontOpenGL();
	


	
	HFONT				m_hFont;
	HFONT				m_hOldFont;
	unsigned int		m_FontID;
	GLYPHMETRICSFLOAT	m_GlyphInfo[MAX_CHARS];
	int					m_Height;
	
private:
	void ActivateFont();
	void Position2D(int x, int y);
};

#endif // !defined(AFX_QFONTOPENGL_H__509EB655_54C7_4C55_A0D0_3DF3F5A817E3__INCLUDED_)
