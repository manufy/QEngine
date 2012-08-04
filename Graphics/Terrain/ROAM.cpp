// ROAM.cpp: implementation of the CROAM class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ROAM.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CROAM::CROAM()
{

}

CROAM::~CROAM()
{

}

ROAMTriTreeNode* CROAM::AllocateTri() 
{
	ROAMTriTreeNode *pTri;

	// Si no hay sitio, devuelve NULL

	if ( m_NextTriNode >= POOL_SIZE )
		return NULL;

	pTri = &(m_TriPool[m_NextTriNode++]);
	pTri->LeftChild = pTri->RightChild = NULL;

	return pTri;
}

void CROAM::Init(unsigned char *hMap)
{	CROAMPatch *patch;
	int X, Y;

	// Store the Height Field array
	m_HeightMap = hMap;

	// Initialize all terrain patches
	for ( Y=0; Y < NUM_PATCHES_PER_SIDE; Y++)
		for ( X=0; X < NUM_PATCHES_PER_SIDE; X++ )
		{
			patch = &(m_Patches[Y][X]);
		//	patch->Init( X*PATCH_SIZE, Y*PATCH_SIZE, X*PATCH_SIZE, Y*PATCH_SIZE, hMap );
	//		patch->ComputeVariance();
		}

}
