#ifndef C03STATEMACHINEFACTORY_H
#define C03STATEMACHINEFACTORY_H
#include "c03statemachinebase.h"

class C03stateMachineFactory
{
public:
    C03stateMachineFactory();
    C03StateMachineBase*  getNewStateMachine();
    void setStateMachineType(C03StateMachineBase::MachineName type);
private:
    C03StateMachineBase::MachineName stateMachineType;
};

#endif // C03STATEMACHINEFACTORY_H
