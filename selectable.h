#ifndef SELECTABLE_H
#define SELECTABLE_H

#include <QDeclarativeItem>

class Selectable : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(bool selected READ selected() WRITE setSelected NOTIFY selectedChanged)

public:
    explicit Selectable(QDeclarativeItem *parent = 0);
    ~Selectable();

    bool selected();
    void setSelected(bool selected);

signals:
    void selectedChanged();

private:
    bool m_selected;
};

#endif // SELECTABLE_H
