#ifndef SCANNING_H
#define SCANNING_H

#include "selectable.h"
#include <QObject>

class Scanning : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Scanning)

private:
    Scanning(QObject *parent = 0);
    ~Scanning();

    static Scanning *m_instance;

public:
    static Scanning *instance();

    void registerItem(Selectable *item);
    void unregisterItem(Selectable *item);
};

#endif // SCANNING_H
