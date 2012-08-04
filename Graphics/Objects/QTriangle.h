// QTriangle.h: interface for the QTriangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QTRIANGLE_H__8624EA1A_FDE7_4FAE_BA46_93F2A32C8536__INCLUDED_)
#define AFX_QTRIANGLE_H__8624EA1A_FDE7_4FAE_BA46_93F2A32C8536__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QVertexManager;

class QTriangle  
{
public:
	void Render(QVertexManager *pVertexManager);

	QTriangle();
	QTriangle(QTriangle *NewTriangle);
	virtual ~QTriangle();

	unsigned int m_VertexA;
	unsigned int m_VertexB;
	unsigned int m_VertexC;
};

#endif // !defined(AFX_QTRIANGLE_H__8624EA1A_FDE7_4FAE_BA46_93F2A32C8536__INCLUDED_)
