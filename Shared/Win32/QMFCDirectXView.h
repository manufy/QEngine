// QMFCDirectXView.h: interface for the QMFCDirectXView class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QMFCDIRECTXVIEW_H__05CA62E0_4992_408A_9B9B_9FD5DA652AF3__INCLUDED_)
#define AFX_QMFCDIRECTXVIEW_H__05CA62E0_4992_408A_9B9B_9FD5DA652AF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QMFCDirectXView  
{
public:
	QMFCDirectXView();
	virtual ~QMFCDirectXView();

	LPDIRECT3D8             m_pDirect3D;		// Dispositivo Direct3D
};

#endif // !defined(AFX_QMFCDIRECTXVIEW_H__05CA62E0_4992_408A_9B9B_9FD5DA652AF3__INCLUDED_)
