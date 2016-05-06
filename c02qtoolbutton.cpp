#include "c02qtoolbutton.h"

C02QToolButton::C02QToolButton(): QToolButton()
{
    QObject::connect(this, SIGNAL(toggled()), this, SLOT(changedState()));
}
void C02QToolButton::changedState(bool checked)
{
    if (checked)
    {
        //this->icon().
    }

}
