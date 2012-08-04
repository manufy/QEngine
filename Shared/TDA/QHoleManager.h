/** \file QHoleManager.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Gestor de huecos en arrays
	
**/
#if !defined(AFX_QHOLEMANAGER_H__6F3E5A28_0E3F_4736_B635_4279290D7620__INCLUDED_)
#define AFX_QHOLEMANAGER_H__6F3E5A28_0E3F_4736_B635_4279290D7620__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QHoleNode;

class QHoleManager  
{
public:
	unsigned int GetNumElements();
	unsigned int GetNextIndex();
	QHoleManager(unsigned int NumElements);
	virtual ~QHoleManager();

	QHoleNode	*m_pHolesQueue; // Estructura PILA para los huecos

	unsigned int m_NumHoles;
	unsigned int m_NumElements;
	unsigned int m_NextElement;
	unsigned int m_MaxElements;
	

};

#endif // !defined(AFX_QHOLEMANAGER_H__6F3E5A28_0E3F_4736_B635_4279290D7620__INCLUDED_)
