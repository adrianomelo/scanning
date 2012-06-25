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
    //QList<Selectable *> m_scanningList;

private slots:
    void itemParentChanged();

public:
    static Scanning *instance();

    void registerItem(Selectable *item);
    void unregisterItem(Selectable *item);
};

#endif // SCANNING_H
