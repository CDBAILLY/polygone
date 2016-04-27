#ifndef C01GRAPHICSSCENE_H
#define C01GRAPHICSSCENE_H

#include <QObject>
#include <qgraphicsscene.h>
#include <qstring.h>
class View;

class C01GraphicsScene:public QGraphicsScene
{
public:
    C01GraphicsScene();
    void populateScene();
    View* addView(QString titre);
};

#endif // C01GRAPHICSSCENE_H
