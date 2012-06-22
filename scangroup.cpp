#include "scangroup.h"

ScanGroup::ScanGroup(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
{
}

bool ScanGroup::selected()
{
    return m_selected;
}

void ScanGroup::setSelected(bool selected)
{
    m_selected = selected;
    emit selectedChanged();
}
