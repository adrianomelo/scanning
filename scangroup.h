#ifndef SCANGROUP_H
#define SCANGROUP_H

#include <QDeclarativeItem>

class ScanGroup : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(bool selected READ selected() WRITE setSelected NOTIFY selectedChanged)

public:
    explicit ScanGroup(QDeclarativeItem *parent = 0);

    bool selected();
    void setSelected(bool selected);

signals:
    void selectedChanged();

private:
    bool m_selected;
};

#endif // SCANGROUP_H
