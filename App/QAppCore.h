/** \file QAppCore.h
    \author Manuel Fernández Yáñez
    \date Enero 2003
    \brief Núcleo de una aplicación básica en modo demo para Win32. VERSION ANTIGUA. BORRAR.
**/

#if !defined(AFX_QAPPCORE_H__01FF13BB_AD34_4EDB_869A_3EBB42C7B21E__INCLUDED_)
#define AFX_QAPPCORE_H__01FF13BB_AD34_4EDB_869A_3EBB42C7B21E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QAppWin32;
class QEngine;
class QInputManager;
class QLog;
class QFontManager;

class QAppCore  
{
public:
	virtual void Render();
	virtual void Cycle(float DeltaTime);
	QAppCore(QAppWin32 *pAppWin32);
	virtual ~QAppCore();

	QEngine			*m_pEngine;
	QInputManager	*m_pInputManager;
	QLog			*m_pLog;
	QFontManager    *m_pFontManager;

};

#endif // !defined(AFX_QAPPCORE_H__01FF13BB_AD34_4EDB_869A_3EBB42C7B21E__INCLUDED_)
