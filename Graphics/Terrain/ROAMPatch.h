// ROAMPatch.h: interface for the CROAMPatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROAMPATCH_H__5638AA30_9BAE_47CB_A5BB_96B611ADEEBB__INCLUDED_)
#define AFX_ROAMPATCH_H__5638AA30_9BAE_47CB_A5BB_96B611ADEEBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VARIANCE_DEPTH (9)

struct ROAMTriTreeNode
{
	ROAMTriTreeNode *LeftChild;
	ROAMTriTreeNode *RightChild;
	ROAMTriTreeNode *BaseNeighbor;
	ROAMTriTreeNode *LeftNeighbor;
	ROAMTriTreeNode *RightNeighbor;
};


class CROAMPatch  // Patch con forma de diamante
{


protected:
	unsigned char *m_HeightMap;									// Pointer to height map to use
	int m_WorldX, m_WorldY;										// World coordinate offset of this patch.

	unsigned char m_VarianceLeft[1<<(VARIANCE_DEPTH)];			// Left variance tree
	unsigned char m_VarianceRight[1<<(VARIANCE_DEPTH)];			// Right variance tree

	unsigned char *m_CurrentVariance;							// Which varience we are currently using. [Only valid during the Tessellate and ComputeVariance passes]
	unsigned char m_VarianceDirty;								// Does the Varience Tree need to be recalculated for this Patch?
	unsigned char m_isVisible;									// Is this patch visible in the current frame?

	ROAMTriTreeNode m_BaseLeft;										// Left base triangle tree node
	ROAMTriTreeNode m_BaseRight;									// Right base triangle tree node

	ROAMTriTreeNode *GetBaseLeft()  { return &m_BaseLeft; }
	ROAMTriTreeNode *GetBaseRight() { return &m_BaseRight; }

public:
	CROAMPatch();
	virtual ~CROAMPatch();	
	char isDirty()     { return m_VarianceDirty; }
	int  isVisibile( ) { return m_isVisible; }
};

#endif // !defined(AFX_ROAMPATCH_H__5638AA30_9BAE_47CB_A5BB_96B611ADEEBB__INCLUDED_)
