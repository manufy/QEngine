#pragma once

class QNode;

class QList
{
public:
	QList(void);
	~QList(void);

	QNode *m_pfirst;
	QNode *m_plast;
	unsigned int m_NumElements;
};
