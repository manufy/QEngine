/** \file QLog.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Logs
	
**/
#if !defined(AFX_QLOG_H__80726C1A_1A2D_4853_9D55_79EE4459FD1F__INCLUDED_)
#define AFX_QLOG_H__80726C1A_1A2D_4853_9D55_79EE4459FD1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QLog  
{
public:
	void AddLine(char *strText);
	QLog(char *strFileName);
	virtual ~QLog();
	char				m_Text[80];

private:

	FILE *m_pFile;				// Handle del fichero
	char m_FileName[20];		// Nombre del fichero

};

#endif // !defined(AFX_QLOG_H__80726C1A_1A2D_4853_9D55_79EE4459FD1F__INCLUDED_)
