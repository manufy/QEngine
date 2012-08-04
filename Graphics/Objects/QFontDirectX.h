// QFontDirectX.h: interface for the QFontDirectX class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QFONTDIRECTX_H__2144D6D9_269A_4DE0_AF93_578D9782A2D0__INCLUDED_)
#define AFX_QFONTDIRECTX_H__2144D6D9_269A_4DE0_AF93_578D9782A2D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "QFont.h"
class QFontDirectX  : public QFont
{
public:
	void Draw2D(int x, int y, char *Text);
	void Create2D(char *Name, int Size);
	QFontDirectX(QEngine *pEngine);
	virtual ~QFontDirectX();
	
	TCHAR		    m_strFontName[80];            // Font properties
//	LPD3DXFONT		m_Font;
};

#endif // !defined(AFX_QFONTDIRECTX_H__2144D6D9_269A_4DE0_AF93_578D9782A2D0__INCLUDED_)
