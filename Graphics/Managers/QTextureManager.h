// QTextureManager.h: interface for the QTextureManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QTEXTUREMANAGER_H__C7367C8B_0D0F_46C8_9A44_F77059937EB5__INCLUDED_)
#define AFX_QTEXTUREMANAGER_H__C7367C8B_0D0F_46C8_9A44_F77059937EB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\jpeglib.h"

#define TGA_RGB		 2		// This tells us it's a normal RGB (really BGR) file
#define TGA_A		 3		// This tells us it's a ALPHA file
#define TGA_RLE		10		// This tells us that the targa is Run-Length Encoded (RLE)

struct TGAImage
{
	int channels;			// The channels in the image (3 = RGB : 4 = RGBA)
	int sizeX;				// The width of the image in pixels
	int sizeY;				// The height of the image in pixels
	unsigned char *data;	// The image pixel data
};

#define TEXTURE_BMP "BMP"
#define TEXTURE_TGA "TGA"
#define TEXTURE_JPG "JPG"

enum eTextureType {BMP,TGA,JPG};


class QTextureManager  : public QHoleManager
{
public:
	bool DecodeJPG(jpeg_decompress_struct *cinfo, JPGImage *pImageData);
	TGAImage* LoadTGA(char *filename);
	JPGImage* LoadJPG(char *filename);
	bool Load(char *strFileName, char *strFileType, int TextureID);
	int Add(char *strFileName, char *strFileType);
	QTextureManager(QEngine *pEngine, unsigned int MaxTextures);
	virtual ~QTextureManager();

	QEngine *m_pEngine;

	
	unsigned int m_Textures[MAX_TEXTURES];
};

#endif // !defined(AFX_QTEXTUREMANAGER_H__C7367C8B_0D0F_46C8_9A44_F77059937EB5__INCLUDED_)
