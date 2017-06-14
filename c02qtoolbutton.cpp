#include "c02qtoolbutton.h"
#include "c02toolbutton.h"

C02QToolButton::~C02QToolButton()
{
    if(hasSubToolButton)
    {
        delete theToolButton;
        hasSubToolButton=false;
    }
}
C02QToolButton::C02QToolButton(): QToolButton()
{
    //QObject::connect(this, SIGNAL(toggled()), this, SLOT(changedState()));
    hasSubToolButton=false;
}
void C02QToolButton::setSubToolButton(C02ToolButton * toolButton)
{
    if(hasSubToolButton)
    {
        delete theToolButton;
    }
    theToolButton=toolButton;
    hasSubToolButton=true;
}
void C02QToolButton::setStateMachineType(C03StateMachineBase::MachineName type)
{
    if(hasSubToolButton)
    {
        delete theToolButton;
        hasSubToolButton=false;
    }
    stateFactory.setStateMachineType(type);
}

void C02QToolButton::changedState(bool checked)
{
    if (checked)
    {
        //this->icon().
    }
}
