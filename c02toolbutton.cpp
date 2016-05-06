#include "c02toolbutton.h"
#include "c03statemachinepositioner.h"
#include "c03statemachinebase.h"
#include <QGridLayout>
#include <QToolButton>
C02ToolButton::~C02ToolButton()
{

}
  C02ToolButton::C02ToolButton():QWidget()
{
    nbIconHorizontal=2;
    theStMachPos=(C03stateMachinePositioner*)NULL;
    menuPere=(C02ToolButton*)NULL;;
    gridLayout=new QGridLayout;
    this->setLayout(gridLayout);
    gridLayout->setHorizontalSpacing(0);gridLayout->setVerticalSpacing(0);
    gridLayout->setMargin(0);
    gridLayout->setContentsMargins(0,0,0,0);
    buttonGroup.setExclusive(true);
    this->setContentsMargins(0,0,0,0);
    //setStyleSheet("QToolButton { background-color: yellow }");
    setIconSize();
    QObject::connect(&buttonGroup, static_cast<void(QButtonGroup::*)(int, bool)>(&QButtonGroup::buttonToggled),
                     this, &C02ToolButton::buttonToggled
                     );

}
  void C02ToolButton::buttonToggled(int id, bool checked)
  {
      if (checked)
      {
          // soit on doit creer la machine d-etat
          // soit on doit creer le menu fils et l'afficher
          // pour l'instant on crree la machine d'état base
          if (theStMachPos!=NULL)
          {
              QList<int> alist;
              alist.prepend(id);
              theStMachPos->setStateMachine(new C03StateMachineBase, alist );
          }

      }
  }
    void C02ToolButton::setIconSize()
{
    int size = style()->pixelMetric(QStyle::PM_ToolBarIconSize);
    theIconsize=QSize(size, size);
}
void C02ToolButton::setIconSize(int size)
{
    theIconsize=QSize(size, size);
}
void C02ToolButton::setNbIconHorizontal(int nb )
{
    nbIconHorizontal=nb;
}
QToolButton* C02ToolButton::addToolButton(QIcon icon)
{
    QToolButton* button;
    button=new QToolButton;
    //pixmap.scaled()
    //button->setIcon(pixmap.scaled(theIconsize,Qt::KeepAspectRatio));
    button->setCheckable(true );
    button->setIcon(icon);
    button->setIconSize(theIconsize);
    buttonGroup.addButton(button);
    QList<QToolButton*> listButton=buttonGroup.buttons();
    //listButton.append(button);
    gridLayout->addWidget(button,(listButton.size()-1)/nbIconHorizontal,(listButton.size()-1)%nbIconHorizontal);
    return button;
}
QToolButton* C02ToolButton::addToolButton(QPixmap pixmap)
{
     return  addToolButton(QIcon(pixmap));
}
QToolButton* C02ToolButton::addToolButton(QPixmap pixmap, QString toolTip)
{
    QToolButton* button;
    button=addToolButton(pixmap);
    button->setToolTip(toolTip);
    return button;
}
QToolButton* C02ToolButton::addToolButton(QPixmap pNorm,QPixmap pAct,QPixmap pSel,QPixmap pDis, QString toolTip)
{
    QIcon icon;
    QToolButton* button;
    icon.addPixmap(pNorm,QIcon::Mode::Normal,QIcon::State::Off);
    icon.addPixmap(pSel,QIcon::Mode::Normal,QIcon::State::On);
    /*icon.addPixmap(pAct,QIcon::Mode::Active,QIcon::State::Off);
    icon.addPixmap(pSel,QIcon::Mode::Selected,QIcon::State::Off);
    icon.addPixmap(pDis,QIcon::Mode::Disabled,QIcon::State::Off);
    icon.addPixmap(pNorm,QIcon::Mode::Active,QIcon::State::On);
    icon.addPixmap(pAct,QIcon::Mode::Selected,QIcon::State::On);
    icon.addPixmap(pSel,QIcon::Mode::Disabled,QIcon::State::On);
    icon.addPixmap(pDis,QIcon::Mode::Normal,QIcon::State::On);*/
    button=addToolButton(icon);
    button->setToolTip(toolTip);
    return button;
}
void C02ToolButton::redraw( )
{
   QList<QToolButton*> listButton=buttonGroup.buttons();
   for(int i=0;i<listButton.size();i++)
   {
       gridLayout->removeWidget(listButton.at(i));
   }
   for(int i=0;i<listButton.size();i++)
   {
       listButton.at(i)->setIconSize(theIconsize);
       gridLayout->addWidget(listButton.at(i),i/nbIconHorizontal,i%nbIconHorizontal);
   }
   setFixedWidth(nbIconHorizontal*theIconsize.width()+10);
   setFixedHeight(((listButton.size()+nbIconHorizontal-1)/nbIconHorizontal)*theIconsize.height()+10);
}
void C02ToolButton::getFocus(C03stateMachinePositioner* stMachPos)
{
    theStMachPos=stMachPos;
    //provisoire, a reprendre apres
    if (theStMachPos->getStateList().size()>0)
    {
        buttonGroup.button(theStMachPos->getStateList().at(0))->setChecked(true);
    }

}
void C02ToolButton::setStateMachine(C03StateMachineBase* stateMachine,QList<int> buttonList)
{
    buttonList.prepend(buttonGroup.checkedId());
    //retenir arborescence menus
    if (menuPere!=NULL)
    {
        menuPere->setStateMachine(stateMachine,buttonList);
    }
    else if(theStMachPos!=NULL)
    {
        theStMachPos->setStateMachine(stateMachine,buttonList);
    }
}
