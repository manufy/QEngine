// QTriangleListFan.h: interface for the QTriangleListFan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QTRIANGLELISTFAN_H__BAA4D12F_62E7_4A5E_824C_58A91BA84D58__INCLUDED_)
#define AFX_QTRIANGLELISTFAN_H__BAA4D12F_62E7_4A5E_824C_58A91BA84D58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QLog;

class QTriangleListFan   : public QPrimitive
{
public:
	QTriangleListFan(QEngine *pEngine);
	QTriangleListFan(QEngine *pEngine,unsigned int NumVertex, float *pVertexList, float *pUVList);
	virtual ~QTriangleListFan();
	void Dump(QLog *pLog);

	void Render(void);


};

#endif // !defined(AFX_QTRIANGLELISTFAN_H__BAA4D12F_62E7_4A5E_824C_58A91BA84D58__INCLUDED_)
