// PatchROAM.h: interface for the CPatchROAM class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PATCHROAM_H__4E6A9401_1E05_4A27_AEF6_B31F737EA870__INCLUDED_)
#define AFX_PATCHROAM_H__4E6A9401_1E05_4A27_AEF6_B31F737EA870__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VARIANCE_DEPTH (9)


//
// Estructura Triangle Tree Node
// Almacena los punteros
//

struct TriTreeNode
{
	TriTreeNode *LeftChild;
	TriTreeNode *RightChild;
	TriTreeNode *BaseNeighbor;
	TriTreeNode *LeftNeighbor;
	TriTreeNode *RightNeighbor;
};


class CPatchROAM  
{
;

#endif // !defined(AFX_PATCHROAM_H__4E6A9401_1E05_4A27_AEF6_B31F737EA870__INCLUDED_)
