#include "C03StateMachineBase.h"
#include "c03statemachinepositioner.h"

C03stateMachinePositioner::C03stateMachinePositioner()
{
    setDefaultStateMachine();
}
void C03stateMachinePositioner::setCurrentStateMachine(C03StateMachineBase* current)
{
    delete currentStateMachine;
    currentStateMachine=current;
}

void C03stateMachinePositioner::setDefaultStateMachine()
{
    currentStateMachine=new C03StateMachineBase;
}

void C03stateMachinePositioner::setStateMachine(C03StateMachineBase* stateMachine,QList<int> buttonList)
{   //retenir arborescence menus
    stateList=buttonList;
    currentStateMachine=stateMachine;
}
