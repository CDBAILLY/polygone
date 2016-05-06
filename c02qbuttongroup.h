#ifndef C02QBUTTONGROUP_H
#define C02QBUTTONGROUP_H

#include <QButtonGroup>
class QToolButton;
class C02QButtonGroup: public QButtonGroup
{
public:
    C02QButtonGroup();
    QList<QToolButton *>	buttons() const;



};

#endif // C02QBUTTONGROUP_H
