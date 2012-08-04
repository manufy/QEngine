// SkyDomeVertex.h: interface for the CSkyDomeVertex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKYDOMEVERTEX_H__A1F62B74_5E9F_41DF_9CB3_B09FC525023E__INCLUDED_)
#define AFX_SKYDOMEVERTEX_H__A1F62B74_5E9F_41DF_9CB3_B09FC525023E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QSkyDomeVertex  
{
public:
	QSkyDomeVertex();
	virtual ~QSkyDomeVertex();

	float x;
	float y;
	float z;
	float u;
	float v;
	int r;
	int g;
	int b;

};

#endif // !defined(AFX_SKYDOMEVERTEX_H__A1F62B74_5E9F_41DF_9CB3_B09FC525023E__INCLUDED_)
