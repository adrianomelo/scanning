#ifndef SCANNINGCONTROL_H
#define SCANNINGCONTROL_H

#include <QObject>

class ScanningControl : public QObject
{
    Q_OBJECT

private:
    int m_index;

public:
    explicit ScanningControl(QObject *parent = 0);
    ~ScanningControl();

    Q_INVOKABLE void next();
    Q_INVOKABLE void select();
};

#endif // SCANNINGCONTROL_H
