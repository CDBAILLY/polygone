#ifndef C02TOOLBUTTON_H
#define C02TOOLBUTTON_H

#include <QObject>
#include <QWidget>
#include <QSize>
#include <QStyle>
#include <QList>
class QToolButton;
class QGridLayout;

class C02ToolButton: public QWidget
{
public:
    C02ToolButton();
    ~C02ToolButton();
    void setIconSize();
    void setIconSize(int size);
    void setNbIconHorizontal(int nb );
    void addToolButton(QPixmap pixmap);
    void redraw();
private:
    int nbIconHorizontal;
    QSize theIconsize;
    QList<QToolButton*> listButton;
    QGridLayout * gridLayout;
};

#endif // C02TOOLBUTTON_H
