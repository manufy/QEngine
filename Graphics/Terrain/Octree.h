// Octree.h: interface for the COctree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OCTREE_H__987B3F37_F5F8_47FF_8324_67038B3BD9D7__INCLUDED_)
#define AFX_OCTREE_H__987B3F37_F5F8_47FF_8324_67038B3BD9D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Vector3.h"

enum eOctreeNodes
{
	TOP_LEFT_FRONT,			// 0
	TOP_LEFT_BACK,			// 1
	TOP_RIGHT_BACK,			// etc...
	TOP_RIGHT_FRONT,
	BOTTOM_LEFT_FRONT,
	BOTTOM_LEFT_BACK,
	BOTTOM_RIGHT_BACK,
	BOTTOM_RIGHT_FRONT
};


class COctree  
{
public:
	void Render();
	void Init();
	COctree();
	virtual ~COctree();

	
	bool m_bSubDivided;	// Octree subdividido

	
	float m_Width;	// Tamaño del cubo para el nodo actual

	
	int m_NumTriangles;	// Numero de triangulos


	CVector3 m_vCenter;	// Centro

	
	CVector3 *m_pVertices;	// Triangulos a dibujar en este nodo

	
	COctree *m_pOctreeNodes[8];	// 8 Hijos
};

#endif // !defined(AFX_OCTREE_H__987B3F37_F5F8_47FF_8324_67038B3BD9D7__INCLUDED_)
