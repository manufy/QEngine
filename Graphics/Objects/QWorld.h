#pragma once

#include "QList.h"

class QNode;

class QWorld : public QList
{
public:
	QWorld(void);
	~QWorld(void);

	QNode *Node;
};
