/** \file QHoleNode.h 
    \author Manuel Fernández Yáñez
    \date Enero-Julio 2003
    \brief Hueco
	
**/
#if !defined(AFX_QHOLENODE_H__A8A303F6_7C46_43AF_BE58_9F66FE17DAFF__INCLUDED_)
#define AFX_QHOLENODE_H__A8A303F6_7C46_43AF_BE58_9F66FE17DAFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QHoleNode  
{
public:
	QHoleNode(int Index, QHoleNode *Queue);
	QHoleNode();
	virtual ~QHoleNode();

	int		   m_Index;   // Indice al hueco
	QHoleNode *m_pNext; // Puntero al siguiente nodo
};

#endif // !defined(AFX_QHOLENODE_H__A8A303F6_7C46_43AF_BE58_9F66FE17DAFF__INCLUDED_)
