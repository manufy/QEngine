#include "stdafx.h"
#include ".\QObject.h"

QObject::QObject(QEngine *pEngine)
{
	m_pEngine = pEngine;
}

QObject::~QObject(void)
{
}
