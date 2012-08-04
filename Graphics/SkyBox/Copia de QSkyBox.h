// SkyBox.h: interface for the CSkyBox class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKYBOX_H__806EAEEB_5EBD_4129_ADD1_E4316DC7993F__INCLUDED_)
#define AFX_SKYBOX_H__806EAEEB_5EBD_4129_ADD1_E4316DC7993F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\Managers\QTextureManager.h"

class CSkyBox  
{
public:
	void CreateSkyBox(QTextureManager *TextureManager,float x, float y, float z, float width, float height, float length);
	void Init(QTextureManager *TextureManager);
	CSkyBox();
	virtual ~CSkyBox();
};

#endif // !defined(AFX_SKYBOX_H__806EAEEB_5EBD_4129_ADD1_E4316DC7993F__INCLUDED_)
