#ifndef SCANNING_H
#define SCANNING_H

#include "selectable.h"
#include <QObject>
#include <QList>
#include <QHash>

class Scanning : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Scanning)

private:
    Scanning(QObject *parent = 0);
    ~Scanning();

    static Scanning *m_instance;

protected:
private slots:
    void itemParentChanged();

public:
    Selectable *m_selected;
    Selectable *m_root;
    //QList<Selectable *> m_selectables;
    QHash<Selectable *, QList <Selectable *> *> m_scanning;

    static Scanning *instance();

    void registerItem(Selectable *item);
    void unregisterItem(Selectable *item);

    void select(Selectable *item);
    void unselect(Selectable *item);
};

#endif // SCANNING_H
