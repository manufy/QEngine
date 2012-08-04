#pragma once

class QEngine;

class QObject
{
public:
	QObject(QEngine *pEngine);
	~QObject(void);

	QEngine *m_pEngine;
};
