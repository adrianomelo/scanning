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

    qDebug() << "scanningcontrol root " << scanning->m_root;

    if (scanning->m_root && !scanning->m_selected) {
        scanning->m_selected = scanning->m_root;
        scanning->select(scanning->m_selected);
    }

    qDebug() << "scanningcontrol";
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

    qDebug() << "m_index " << m_index << " list size " << list->size();

    if (list->size() == 0) {
        scanning->select(scanning->m_root);
    } else {
        Selectable *nowSelected = list->at(m_index);
        nowSelected->setSelected(false);

        m_index = (m_index + 1) % list->size();

        Selectable *nextSelected = list->at(m_index);
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

    qDebug() << "Selected m_index " << m_index << " list size " << list->size();

    Selectable *selected = list->at(m_index);
    scanning->select(selected);
    selected->setSelected(false);
    m_index = 0;
}

