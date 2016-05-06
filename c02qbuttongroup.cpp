#include "c02qbuttongroup.h"

C02QButtonGroup::C02QButtonGroup():QButtonGroup()
{

}

QList<QToolButton *>	C02QButtonGroup::buttons()const
{
    QList<QToolButton *> list;
    QList<QAbstractButton *> ablistlist=QButtonGroup::buttons();
    for (int i=0;i<ablistlist.size();i++)
    {
        list.append((QToolButton*)ablistlist.at(i));
    }
    return list;

}
