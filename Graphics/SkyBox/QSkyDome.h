// SkyDome.h: interface for the CSkyDome class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKYDOME_H__74157E85_0618_48F4_B964_E7F2522CC900__INCLUDED_)
#define AFX_SKYDOME_H__74157E85_0618_48F4_B964_E7F2522CC900__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\Shared\Math\Vector3.h"
#include "..\..\Shared\Math\Matrix4.h"

#define PI 3.14159

#include "QSkyDomeVertex.h"
//#include "SkyBody.h"
//#include "SkyClouds.h"

// todo : pasar a CSKy
class QStarCatalog;
class QLog;
 

class QSkyDome  
{
public:
	//void AddClouds(LPSTR strFileName);
	void Render();

	void GenerateDome(float radius, float dtheta, float dphi, float hTile, float vTile);
	int  GetJulianDateT(int Day, int Month, int Year, int Hour, int Min, int Sec);
	int GetEclipticObliquity(float T);
	QSkyDome(QLog *pLog);
	virtual ~QSkyDome();
	QSkyDomeVertex	*m_pVertexList;

//	CSkyBody		*m_pSkyBodyList;
//	CSkyClouds		*m_pSkyCloudsList;

	int				m_NumVertex;  // Number of vertices
	int				m_nResolution;
	float			m_fVertSweep;
	float			m_fRadius;
	float			m_fHeightScale;
	CVector3		m_vOrigin;
	QStarCatalog    *m_pStars;
	QLog			*m_pLog;

	int LoadStars(char * strFileName);
};

#endif // !defined(AFX_SKYDOME_H__74157E85_0618_48F4_B964_E7F2522CC900__INCLUDED_)
