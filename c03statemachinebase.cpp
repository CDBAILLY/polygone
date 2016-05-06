#include "c01graphicsscene.h"
#include "c03statemachinebase.h"

C03StateMachineBase::C03StateMachineBase()
{

}
C03StateMachineBase::~C03StateMachineBase()
{

}

bool C03StateMachineBase::keyPressEvent(C01GraphicsScene *GraphicsScene, QKeyEvent *keyEvent)
{
    return true;
}
bool C03StateMachineBase::keyReleaseEvent(C01GraphicsScene *GraphicsScene, QKeyEvent *keyEvent)
{
    return true;
}
bool C03StateMachineBase::mouseDoubleClickEvent(C01GraphicsScene *GraphicsScene, QGraphicsSceneMouseEvent *mouseEvent)
{
    return true;
}
bool C03StateMachineBase::mouseMoveEvent(C01GraphicsScene *GraphicsScene, QGraphicsSceneMouseEvent *mouseEvent)
{
    return true;
}
bool C03StateMachineBase::mousePressEvent(C01GraphicsScene *GraphicsScene, QGraphicsSceneMouseEvent *mouseEvent)
{
    return true;
}
bool C03StateMachineBase::mouseReleaseEvent(C01GraphicsScene *GraphicsScene, QGraphicsSceneMouseEvent *mouseEvent)
{
    return true;
}
