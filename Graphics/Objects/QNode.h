#pragma once

class QNode
{
public:
	QNode(void);
	~QNode(void);

	QNode *m_pNext;
	QNode *m_pPrevious;
};
