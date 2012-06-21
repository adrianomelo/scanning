#ifndef SCANNING_H
#define SCANNING_H

#include <QtDeclarative/QDeclarativeItem>

class Scanning : public QDeclarativeItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Scanning)
    
public:
    Scanning(QDeclarativeItem *parent = 0);
    ~Scanning();
};

QML_DECLARE_TYPE(Scanning)

#endif // SCANNING_H

