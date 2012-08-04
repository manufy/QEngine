// QMFCApp.h: interface for the QMFCApp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QMFCAPP_H__BA2A6C1F_1779_44CD_95CF_E099B130C992__INCLUDED_)
#define AFX_QMFCAPP_H__BA2A6C1F_1779_44CD_95CF_E099B130C992__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QMFCApp  : public CWinApp
{
public:
	virtual void SaveConfig();
	void LoadConfig();
	QMFCApp* GetApp();
	QMFCApp();
	virtual ~QMFCApp();

	int m_Renderer;
	int	m_RendererFrames;
	int m_RendererLimitFrames;
};

#endif // !defined(AFX_QMFCAPP_H__BA2A6C1F_1779_44CD_95CF_E099B130C992__INCLUDED_)
