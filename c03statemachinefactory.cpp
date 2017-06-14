#include "c03statemachinefactory.h"

C03stateMachineFactory::C03stateMachineFactory()
{
    stateMachineType=C03StateMachineBase::MachineBase;
}

C03StateMachineBase * C03stateMachineFactory::getNewStateMachine()
{
    switch(stateMachineType)
    {
    case C03StateMachineBase::MachineBase:
        return new C03StateMachineBase;
        break;
    default:
        return (C03StateMachineBase*)NULL;
    }
}
void C03stateMachineFactory::setStateMachineType(C03StateMachineBase::MachineName type)
{
    stateMachineType=type;
}
