#ifndef C02TOOLBUTTON_H
#define C02TOOLBUTTON_H

#include <QObject>
#include <QWidget>
#include <QSize>
#include <QStyle>
#include <QList>
#include <QToolButton>
#include "c02qbuttongroup.h"
class QGridLayout;
class C03stateMachinePositioner;
class C03StateMachineBase;

class C02ToolButton: public QWidget
{
    Q_OBJECT
public:
    C02ToolButton();
    ~C02ToolButton();
    void setIconSize();
    void setIconSize(int size);
    void setNbIconHorizontal(int nb );
    QToolButton* addToolButton(QPixmap pixmap);
    QToolButton* addToolButton(QIcon icon);
    QToolButton* addToolButton(QPixmap pixmap,QString toolTip);
    QToolButton* addToolButton(QPixmap pNorm,QPixmap pAct,QPixmap pSel,QPixmap pDis,QString toolTip);
    void setStateMachine(C03StateMachineBase* stateMachine,QList<int> buttonList);
    void redraw();
public slots:
    void getFocus(C03stateMachinePositioner* stMachPos);
    void buttonToggled(int id, bool checked);
private:
    int nbIconHorizontal;
    QSize theIconsize;
    //QList<QToolButton*> listButton;
    QGridLayout * gridLayout;
    C02QButtonGroup buttonGroup;
    C03stateMachinePositioner* theStMachPos;
    C02ToolButton* menuPere;
};

#endif // C02TOOLBUTTON_H
