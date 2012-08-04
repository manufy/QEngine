// QLog.cpp: implementation of the QLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QLog.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QLog::QLog(char *strFileName)
{
	strcpy(m_FileName,strFileName);
	AddLine("QLog: Comienzo de sesión\n");
}

QLog::~QLog()
{

}

void QLog::AddLine(char *strText)
{
	m_pFile = fopen(m_FileName,"a");
	fprintf(m_pFile,"%s",strText);
	fclose(m_pFile);
}
