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
    Selectable *itemScan = qobject_cast<Selectable *>(item);

    QObject * p = item->parent();
    while (p) {
        Selectable *parent = qobject_cast<Selectable *>(p);

        if (m_scanning.contains(parent)) {
            QList<Selectable *> * list = m_scanning.value(parent);
            list->append(itemScan);
            break;
        }

        p = p->parent();
    }
}

void Scanning::registerItem(Selectable *item)
{
    if (m_scanning.isEmpty())
        m_root = item;

    //m_selectables.append(item);
    m_scanning.insert(item, new QList<Selectable *>());
    QDeclarativeItem::connect(item, SIGNAL(parentChanged()),
                              this, SLOT(itemParentChanged()));
}

void Scanning::unregisterItem(Selectable *item)
{
    //m_selectables.removeOne(item);
    QDeclarativeItem::disconnect(item, SIGNAL(parentChanged()),
                                 this, SLOT(itemParentChanged()));
}

