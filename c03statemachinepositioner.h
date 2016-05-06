#ifndef C03STATEMACHINEPOSITIONER_H
#define C03STATEMACHINEPOSITIONER_H

#include <QObject>
class C03StateMachineBase;
class C03stateMachinePositioner:public QObject
{
    Q_OBJECT
public:
    C03stateMachinePositioner();
    void setCurrentStateMachine(C03StateMachineBase* current);
    void setDefaultStateMachine();
public slots:
    void setStateMachine(C03StateMachineBase* stateMachine,QList<int> buttonList);
    C03StateMachineBase* stateMachine(){return currentStateMachine;};
    QList<int> getStateList(void){return stateList;}
signals:
    getFocus(C03stateMachinePositioner* stMachPos);
private:
    C03StateMachineBase* currentStateMachine;
    QList<int> stateList;
};

#endif // C03STATEMACHINEPOSITIONER_H
