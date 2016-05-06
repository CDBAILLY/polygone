#include "c01graphicsscene.h"
#include "chip.h"
#include "view.h"
#include "c03statemachinebase.h"
#include "c02toolbutton.h"

C01GraphicsScene::C01GraphicsScene():QGraphicsScene()
{
}
C01GraphicsScene::~C01GraphicsScene()
{
}
View* C01GraphicsScene::addView(QString titre)
{
    View *view = new View(titre);
    view->view()->setScene(this);

    QObject::connect(
                view->theGraphicsView(), static_cast<void(GraphicsView::*)()>(&GraphicsView::focusInEvent),
                this, &C01GraphicsScene::aViewGetFocus);
    return view;
}
void C01GraphicsScene::aViewGetFocus()
{
    emit stMachPos.getFocus(&stMachPos);
}

void C01GraphicsScene::populateScene()
{
    QImage image(":/qt4logo.png");

    // Populate scene
    int xx = 0;
    int nitems = 0;
    for (int i = -11000; i < 11000; i += 110) {
        ++xx;
        int yy = 0;
        for (int j = -7000; j < 7000; j += 70) {
            ++yy;
            qreal x = (i + 11000) / 22000.0;
            qreal y = (j + 7000) / 14000.0;

            QColor color(image.pixel(int(image.width() * x), int(image.height() * y)));
            QGraphicsItem *item = new Chip(color, xx, yy);
            item->setPos(QPointF(i, j));
            addItem(item);

            ++nitems;
        }
    }
}
void C01GraphicsScene::keyPressEvent(QKeyEvent *keyEvent)
{
    if (stMachPos.stateMachine()->keyPressEvent(this,keyEvent))
    {
            QGraphicsScene::keyPressEvent(keyEvent);
    }
}
void C01GraphicsScene::keyReleaseEvent(QKeyEvent *keyEvent)
{
    if (stMachPos.stateMachine()->keyReleaseEvent(this,keyEvent))
    {
            QGraphicsScene::keyReleaseEvent(keyEvent);
    }
}
void C01GraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (stMachPos.stateMachine()->mouseDoubleClickEvent(this,mouseEvent))
    {
            QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
    }
}
void C01GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (stMachPos.stateMachine()->mouseMoveEvent(this,mouseEvent))
    {
            QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
}
void C01GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (stMachPos.stateMachine()->mousePressEvent(this,mouseEvent))
    {
            QGraphicsScene::mousePressEvent(mouseEvent);
    }
}
void C01GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (stMachPos.stateMachine()->mouseReleaseEvent(this,mouseEvent))
    {
            QGraphicsScene::mouseReleaseEvent(mouseEvent);
    }
}
void C01GraphicsScene::registerToolButton(C02ToolButton *toolButtonWidget)
{
    toolButtonWidget->getFocus(&stMachPos);
    QObject::connect(&stMachPos, &C03stateMachinePositioner::getFocus,
                     toolButtonWidget, &C02ToolButton::getFocus);

}


/*
void C01GraphicsScene::createToolButton()
{
    toolButton=new C02ToolButton;
    toolButton->setIconSize( 30);
    toolButton->setNbIconHorizontal(2);
    (toolButton->addToolButton(QPixmap(":/select.png"),"select"))->setChecked(true);
    toolButton->addToolButton(QPixmap(":/edit-polygon.png"),"edit polygon");
    toolButton->addToolButton(QPixmap(":/draw-polygon.png"),"create polygon");
   // toolButton->addToolButton(QPixmap(":/zoomout.png"));
    toolButton->redraw();
}*/
/*
QWidget * C01GraphicsScene::getToolButton()
{
    return toolButton;
}
*/
