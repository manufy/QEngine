// QModelMD2.h: interface for the QModelMD2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QMODELMD2_H__857500CF_9EA7_4A55_9DAA_B9C8446A7274__INCLUDED_)
#define AFX_QMODELMD2_H__857500CF_9EA7_4A55_9DAA_B9C8446A7274__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//* MD2 constantes */

#define ANIMATE_CURRENT -100

#define IDLE1				0
#define RUN					1
#define SHOT_STAND			2
#define SHOT_SHOULDER		3
#define JUMP				4
#define IDLE2				5
#define SHOT_FALLDOWN		6
#define IDLE3				7
#define IDLE4				8
#define CROUCH				9
#define CROUCH_CRAWL		10
#define CROUCH_IDLE			11
#define CROUCH_DEATH		12
#define DEATH_FALLBACK		13
#define DEATH_FALLFORWARD	14
#define DEATH_FALLBACKSLOW	15

#define IDLE1_START					0
#define IDLE1_END					39
#define RUN_START					40
#define RUN_END						45
#define SHOT_STAND_START			46
#define SHOT_STAND_END				60
#define SHOT_SHOULDER_START			61
#define SHOT_SHOULDER_END			66
#define JUMP_START					67
#define JUMP_END					73
#define IDLE2_START					74
#define IDLE2_END					95
#define SHOT_FALLDOWN_START			96
#define SHOT_FALLDOWN_END			112
#define IDLE3_START					113
#define IDLE3_END					122
#define IDLE4_START					123
#define IDLE4_END					135
#define CROUCH_START				136
#define CROUCH_END					154
#define CROUCH_CRAWL_START			155
#define CROUCH_CRAWL_END			161
#define CROUCH_IDLE_START			162
#define CROUCH_IDLE_END				169
#define CROUCH_DEATH_START			170
#define CROUCH_DEATH_END			177
#define DEATH_FALLBACK_START		178
#define DEATH_FALLBACK_END			185
#define DEATH_FALLFORWARD_START		186
#define DEATH_FALLFORWARD_END		190
#define DEATH_FALLBACKSLOW_START	191
#define DEATH_FALLBACKSLOW_END		198



typedef struct MD2_HEADER_TYPE
{
	int magic;
	int version;
	int skinWidth;
	int skinHeight;
	int frameSize;
	int numSkins;
	int numVertices;
	int numTexcoords;
	int numTriangles;	
	int numGlCommands;
	int numFrames;
	int offsetSkins;
	int offsetTexcoords;
	int offsetTriangles;
	int offsetFrames;
	int offsetGlCommands;
	int offsetEnd;
} MD2_HEADER, *MD2_HEADER_PTR;

typedef struct MD2_VERTEX_TYPE
{
	unsigned char vertex[3];
	unsigned char lightNormalIndex;
} MD2_VERTEX, *MD2_VERTEX_PTR;


typedef struct MD2_FRAME_TYPE
{
	float	   scale[3];
	float	   translate[3];
	char	   name[16];
	MD2_VERTEX vertices[1];
} MD2_FRAME, *MD2_FRAME_PTR;

typedef struct MD2_MODELVERTEX_TYPE
{
	float x,y,z;
	float u,v;
} MD2_MODELVERTEX, *MD2_MODELVERTEX_PTR;

typedef struct MD2_GLVERTEX_TYPE
{
	float Vertex[3];
	float TexCoord[2];
} MD2_GLVERTEX;

#include "QModel.h"

class QModelMD2  : public QModelKeyframed
{

private:

	
	int					m_NumGLCommands;
	long				*m_pGLCommands;
	int					m_NumTriangles;
	
public:
	void Import();
	int  Load(char *strFileName);
	QModelMD2(QEngine *pEngine);
	virtual ~QModelMD2();
	void Render();


	int					m_FrameSize;
	int					m_NumFrames;
	char				*m_pMD2Frames;



	void Dump(void);
};

#endif // !defined(AFX_QMODELMD2_H__857500CF_9EA7_4A55_9DAA_B9C8446A7274__INCLUDED_)
