#ifndef C01GRAPHICSSCENE_H
#define C01GRAPHICSSCENE_H

#include <QObject>
#include <qgraphicsscene.h>
#include <qstring.h>
#include "c03statemachinepositioner.h"

class View;
class C03StateMachineBase;
class C02ToolButton;

class C01GraphicsScene:public QGraphicsScene
{
    Q_OBJECT
public:
    C01GraphicsScene();
    ~C01GraphicsScene();
    void populateScene();
    View* addView(QString titre);
    virtual void keyPressEvent(QKeyEvent *keyEvent);
    virtual void keyReleaseEvent(QKeyEvent *keyEvent);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void registerToolButton(C02ToolButton *toolButtonWidget);
    //QWidget * getToolButton();
public slots:
    void aViewGetFocus();
signals:
protected :
    //void createToolButton();
private:
    C03stateMachinePositioner stMachPos;
    //C02ToolButton *toolButton;
};

#endif // C01GRAPHICSSCENE_H
