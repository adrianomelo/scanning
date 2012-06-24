#ifndef SCANGROUP_H
#define SCANGROUP_H

#include "selectable.h"

class ScanGroup : public Selectable
{
    Q_OBJECT

public:
    explicit ScanGroup(QDeclarativeItem *parent = 0);
    ~ScanGroup();

};

#endif // SCANGROUP_H
