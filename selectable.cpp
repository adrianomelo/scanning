#include "selectable.h"
#include "scanning.h"

Selectable::Selectable(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
{
    Scanning *scanning = Scanning::instance();
    scanning->registerItem(this);
}

Selectable::~Selectable()
{
    Scanning *scanning = Scanning::instance();
    scanning->unregisterItem(this);
}

bool Selectable::selected()
{
    return m_selected;
}

void Selectable::setSelected(bool selected)
{
    m_selected = selected;
    emit selectedChanged();
}
