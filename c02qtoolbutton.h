#ifndef C02QTOOLBUTTON_H
#define C02QTOOLBUTTON_H
#include <QToolButton>

class C02QToolButton: public QToolButton
{
    Q_OBJECT
public:
    C02QToolButton();
public slots:
    void changedState(bool checked);
};

#endif // C02QTOOLBUTTON_H
