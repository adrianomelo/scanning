#include "selectable.h"
#include "scanning.h"
#include "scanningcontrol.h"

#include <QDebug>

ScanningControl::ScanningControl(QObject *parent) :
    QObject(parent), m_index(0)
{
    Scanning *scanning = Scanning::instance();

    if (!scanning)
        return;

    if (scanning->m_root && !scanning->m_selected) {
        scanning->m_selected = scanning->m_root;
        scanning->select(scanning->m_selected);
    }
}

ScanningControl::~ScanningControl()
{
}

void ScanningControl::next()
{
    Scanning *scanning = Scanning::instance();

    if (!scanning)
        return;

    if (!scanning->m_scanning.contains(scanning->m_selected))
        return;

    QList<Selectable *> *list = scanning->m_scanning.value(scanning->m_selected);

    if (list->size() == 0) {
        scanning->select(scanning->m_root);
    } else {
        Selectable *nowSelected = list->at(m_index);

        m_index = nowSelected->selected() ? (m_index + 1) % list->size() : 0;

        Selectable *nextSelected = list->at(m_index);

        nowSelected->setSelected(false);
        nextSelected->setSelected(true);
    }
}

void ScanningControl::select()
{
    Scanning *scanning = Scanning::instance();

    if (!scanning)
        return;

    if (!scanning->m_scanning.contains(scanning->m_selected))
        return;

    QList<Selectable *> *list = scanning->m_scanning.value(scanning->m_selected);

    Selectable *selected = list->at(m_index);
    selected->setSelected(false);

    QList<Selectable *> *listSelected = scanning->m_scanning.value(selected);
    if (listSelected->size() == 0) {
        qDebug() << "Action from " << selected;
        scanning->select(scanning->m_root);
    } else {
        scanning->select(selected);
    }

    m_index = 0;
}

