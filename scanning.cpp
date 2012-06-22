#include "scanning.h"

#include <QObject>

Scanning *Scanning::m_instance = 0;

Scanning::Scanning(QObject *parent):
    QObject(parent)
{
}

Scanning::~Scanning()
{
}

Scanning *Scanning::instance()
{
    if (!m_instance)
        m_instance = new Scanning();

    return m_instance;
}
