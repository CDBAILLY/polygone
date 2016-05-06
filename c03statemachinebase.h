#ifndef C03STATEMACHINEBASE_H
#define C03STATEMACHINEBASE_H

#include <QObject>
class QKeyEvent;
class QGraphicsSceneMouseEvent;
class C01GraphicsScene;
class C03StateMachineBase
{
    //Q_OBJECT
public:
    C03StateMachineBase();
    virtual ~C03StateMachineBase();
    enum State{StateInitial};
    virtual void resetStateMachine(){currentState=State::StateInitial;};
    virtual bool keyPressEvent(C01GraphicsScene *GraphicsScene, QKeyEvent *keyEvent);
    virtual bool keyReleaseEvent(C01GraphicsScene *GraphicsScene, QKeyEvent *keyEvent);
    virtual bool mouseDoubleClickEvent(C01GraphicsScene *GraphicsScene, QGraphicsSceneMouseEvent *mouseEvent);
    virtual bool mouseMoveEvent(C01GraphicsScene *GraphicsScene, QGraphicsSceneMouseEvent *mouseEvent);
    virtual bool mousePressEvent(C01GraphicsScene *GraphicsScene, QGraphicsSceneMouseEvent *mouseEvent);
    virtual bool mouseReleaseEvent(C01GraphicsScene *GraphicsScene, QGraphicsSceneMouseEvent *mouseEvent);

private:
    State currentState;
};

#endif // C03STATEMACHINEBASE_H
