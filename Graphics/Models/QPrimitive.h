// QPrimitive.h: interface for the QPrimitive class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QPRIMITIVE_H__6AEC816C_B1DC_49B1_B250_CD2CD03BBC30__INCLUDED_)
#define AFX_QPRIMITIVE_H__6AEC816C_B1DC_49B1_B250_CD2CD03BBC30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QPrimitive  
{
public:
	virtual void Render();
	QPrimitive();
	virtual ~QPrimitive();
	virtual void Dump(QLog *pLog);

	unsigned int m_NumVertex;

	float *m_pVertex;
	float *m_pUV;

};

#endif // !defined(AFX_QPRIMITIVE_H__6AEC816C_B1DC_49B1_B250_CD2CD03BBC30__INCLUDED_)
