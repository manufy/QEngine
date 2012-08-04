// SkyClouds.h: interface for the CSkyClouds class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKYCLOUDS_H__5320EDAD_FADE_4952_B7DA_11D3114C289C__INCLUDED_)
#define AFX_SKYCLOUDS_H__5320EDAD_FADE_4952_B7DA_11D3114C289C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSkyClouds  
{
public:
	void LoadTexture(LPSTR strFileName);
	CSkyClouds();
	virtual ~CSkyClouds();


	CSkyClouds *m_pNext;
};

#endif // !defined(AFX_SKYCLOUDS_H__5320EDAD_FADE_4952_B7DA_11D3114C289C__INCLUDED_)
