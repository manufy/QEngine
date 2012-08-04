// ROAM.h: interface for the CROAM class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROAM_H__922D3A73_D9EF_4949_BB8A_C059F7478B5F__INCLUDED_)
#define AFX_ROAM_H__922D3A73_D9EF_4949_BB8A_C059F7478B5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ROAMPatch.h"

#define MAP_SIZE (1024)
#define NUM_PATCHES_PER_SIDE (16)
#define POOL_SIZE (25000)

class CROAM  
{
public:
	void Init(unsigned char *hMap);
	ROAMTriTreeNode* AllocateTri();
	CROAM();
	virtual ~CROAM();

	unsigned char *m_HeightMap;										// HeightMap of the Landscape
	CROAMPatch m_Patches[NUM_PATCHES_PER_SIDE][NUM_PATCHES_PER_SIDE];	// Array of patches

	int	m_NextTriNode;										// Index to next free TriTreeNode
	ROAMTriTreeNode m_TriPool[POOL_SIZE];						// Pool of TriTree nodes for splitting

	int GetNextTriNode() { return m_NextTriNode; }
	void SetNextTriNode( int nNextNode ) { m_NextTriNode = nNextNode; }



};

#endif // !defined(AFX_ROAM_H__922D3A73_D9EF_4949_BB8A_C059F7478B5F__INCLUDED_)
