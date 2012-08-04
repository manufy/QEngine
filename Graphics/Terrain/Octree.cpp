// Octree.cpp: implementation of the COctree class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Octree.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COctree::COctree()
{
	Init();

}

COctree::~COctree()
{
// Free the triangle data if it's not NULL
	if( m_pVertices )
	{
		delete m_pVertices;	
		m_pVertices = NULL;
	}

	// Go through all of the nodes and free them if they were allocated
	for(int i = 0; i < 8; i++)
	{
		// Make sure this node is valid
		if(m_pOctreeNodes[i])
		{
			// Free this array index.  This will call the deconstructor which will
			// free the octree data correctly.  This allows us to forget about it's clean up
			delete m_pOctreeNodes[i];
			m_pOctreeNodes[i] = NULL;
		}
	}

	// Initialize the octree data members
	Init();
}

void COctree::Init()
{
	m_bSubDivided = false;
	m_Width = 0; 
	m_NumTriangles = 0;
	m_vCenter = CVector3(0, 0, 0);
	m_pVertices = NULL;
	memset(m_pOctreeNodes, 0, sizeof(m_pOctreeNodes));	
}

void COctree::Render()
{

}
