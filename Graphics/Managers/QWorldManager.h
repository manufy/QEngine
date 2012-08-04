#pragma once

#include "QList.h"

class QWorld;
class QWorldManager : public QList
{
public:
	QWorldManager(void);
	~QWorldManager(void);
	int Add(QWorld *pWorld);
};
