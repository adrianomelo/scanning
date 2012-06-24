#include "selectable.h"
#include "scanning.h"
#include "scangroup.h"

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

void Scanning::registerItem(Selectable *item)
{
    qDebug() << "register " << item;
}

void Scanning::unregisterItem(Selectable *item)
{
    qDebug() << "unregister " << item;
}

