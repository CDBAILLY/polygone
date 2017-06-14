#ifndef C02TOOLBUTTON_H
#define C02TOOLBUTTON_H

#include <QObject>
#include <QFrame>
#include <QSize>
#include <QStyle>
#include <QList>
#include <QToolButton>
#include "c02qbuttongroup.h"
#include "c02qtoolbutton.h"
#include "c03statemachinebase.h"
class QGridLayout;
class QVBoxLayout;
class C03stateMachinePositioner;
//class C03StateMachineBase;

class C02ToolButton: public QFrame
{
    Q_OBJECT
public:
    C02ToolButton();
    ~C02ToolButton();
    void setIconSize();
    void setIconSize(int size);
    void setNbIconHorizontal(int nb );
    void setStateMachine(C03StateMachineBase* stateMachine,QList<int> buttonList);
    void setMenuPere(C02ToolButton* menu){menuPere=menu;};
    void redraw();
    int checkedId(void);
    C02QToolButton* addToolButton(C02ToolButton* menuFils,QPixmap pixmap,QString toolTip);
    C02QToolButton* addToolButton(C03StateMachineBase::MachineName stateMachineName,QPixmap pixmap,QString toolTip);
    void restoreDefaultButtons(void);
protected:
    void restoreButtons(int i,QList<int> buttonList);//restore l'état après qu-ait été positionné theStMachPos
    C02QToolButton* addToolButton(QPixmap pixmap);
    C02QToolButton* addToolButton(QIcon icon);
    C02QToolButton* addToolButton(QPixmap pixmap,QString toolTip);
    C02QToolButton* addToolButton(QPixmap pNorm,QPixmap pAct,QPixmap pSel,QPixmap pDis,QString toolTip);
    void setDefaultButton(int id){defaultButton=id;}
    int getDefaultButton(void){return defaultButton;}
public slots:
    void getFocus(C03stateMachinePositioner* stMachPos);
    void buttonToggled(int id, bool checked);
private:
    int nbIconHorizontal;
    QSize theIconsize;
    //QList<QToolButton*> listButton;
    QGridLayout * gridLayout;
    C02QButtonGroup buttonGroup;
    //adresse du positionner de la scene concernee
    C03stateMachinePositioner* theStMachPos;
    C02ToolButton* menuPere;
    QVBoxLayout* subToolButtonLayout;
    QWidget *toolButtonWidget;
    int defaultButton;
};

#endif // C02TOOLBUTTON_H
