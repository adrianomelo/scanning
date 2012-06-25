#include "selectable.h"
#include "scanning.h"
#include "scangroup.h"

#include <QObject>
#include <QList>
#include <QHash>

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

void Scanning::itemParentChanged()
{
    QObject *item = this->sender();
    QObject *itemParent = item->parent();

    /*if (itemParent) {
        Selectable *parent = qobject_cast<Selectable *>(itemParent);
        qDebug() << m_selectables.contains(parent);
    }*/

    qDebug() << "item " << item << " parent " << itemParent;
}

void Scanning::registerItem(Selectable *item)
{
    /*if (!m_selectables.contains(item)) {
        QList<Selectable *> *list = new QList<Selectable *>();
        m_selectables.insert(item, list);
    }*/

    QDeclarativeItem::connect(item, SIGNAL(parentChanged()),
                     this, SLOT(itemParentChanged()));
}

void Scanning::unregisterItem(Selectable *item)
{
    //m_selectables.remove(item);
    QDeclarativeItem::disconnect(item, SIGNAL(parentChanged()),
                     this, SLOT(itemParentChanged()));
}

