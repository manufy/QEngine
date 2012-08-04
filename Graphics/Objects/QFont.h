// QFont.h: interface for the QFont class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QFONT_H__EF55EE32_30AA_457D_8513_3B6D9CAE4DC9__INCLUDED_)
#define AFX_QFONT_H__EF55EE32_30AA_457D_8513_3B6D9CAE4DC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum eFontType { eFont2D, eFont3D }; // Tipos de fuente de letra: 2d y 3d

class QFont  
{
public:
	virtual void Create2D(char *Name, int Size);
	virtual void Draw2D(int x, int y, char *Text);
	QFont(QEngine *pEngine);
	virtual ~QFont();

	QEngine *m_pEngine;

};

#endif // !defined(AFX_QFONT_H__EF55EE32_30AA_457D_8513_3B6D9CAE4DC9__INCLUDED_)
