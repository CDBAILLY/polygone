#include "c01graphicsscene.h"
#include "chip.h"
#include "view.h"

C01GraphicsScene::C01GraphicsScene():QGraphicsScene()
{

}
View* C01GraphicsScene::addView(QString titre)
{
    View *view = new View(titre);
    view->view()->setScene(this);
    return view;
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
