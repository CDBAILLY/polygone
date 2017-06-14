#ifndef C02QTOOLBUTTON_H
#define C02QTOOLBUTTON_H
#include <QToolButton>
#include "c03statemachinefactory.h"
class C02ToolButton;
class C02QToolButton: public QToolButton
{
    Q_OBJECT
public:
    C02QToolButton();
    ~C02QToolButton();
    C03StateMachineBase*  getNewStateMachine(){return stateFactory.getNewStateMachine();}
    void setStateMachineType(C03StateMachineBase::MachineName type);
    bool hasASubToolButton(){return hasSubToolButton;};
    void setSubToolButton(C02ToolButton * toolButton);
    C02ToolButton * getSubToolButton( void){return theToolButton;};
private:
    C03stateMachineFactory stateFactory;
public slots:
    void changedState(bool checked);
private:
    bool hasSubToolButton;
    C02ToolButton* theToolButton;
};

#endif // C02QTOOLBUTTON_H
