#include "c02toolbutton.h"
#include "c03statemachinepositioner.h"
#include "c03statemachinebase.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QToolButton>
C02ToolButton::~C02ToolButton()
{

}
  C02ToolButton::C02ToolButton():QFrame()
{
      nbIconHorizontal=2;
      theStMachPos=(C03stateMachinePositioner*)NULL;
      setFrameStyle(Sunken | StyledPanel);
      //QWidget::i
      menuPere=(C02ToolButton*)NULL;;
      QVBoxLayout *AllLayout=new QVBoxLayout;
      AllLayout->setMargin(0);
      AllLayout->setContentsMargins(0,0,0,0);
      toolButtonWidget=new QWidget;
      this->setLayout(AllLayout);
      AllLayout->addWidget(toolButtonWidget);
      AllLayout->addWidget(toolButtonWidget,0,Qt::AlignCenter);
      gridLayout=new QGridLayout;
      toolButtonWidget->setLayout(gridLayout);

      QWidget *subToolButtonWidget=new QWidget;
      AllLayout->addWidget(subToolButtonWidget);
      subToolButtonLayout=new QVBoxLayout;
      subToolButtonLayout->setMargin(0);
      subToolButtonLayout->setContentsMargins(0,0,0,0);
      subToolButtonWidget->setLayout(subToolButtonLayout);
      gridLayout->setHorizontalSpacing(0);gridLayout->setVerticalSpacing(0);
      gridLayout->setMargin(1);
      gridLayout->setContentsMargins(1,1,1,1);
      buttonGroup.setExclusive(true);
      this->setContentsMargins(2,2,2,2);
      //setStyleSheet("QToolButton { background-color: yellow }");
      setIconSize();
/*
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
*/
    QObject::connect(&buttonGroup, static_cast<void(QButtonGroup::*)(int, bool)>(&QButtonGroup::buttonToggled),
                     this, &C02ToolButton::buttonToggled
                     );

}
  void C02ToolButton::buttonToggled(int id, bool checked)
  {
      C02QToolButton* button;
      // il faut récupérer le bouton
      button = static_cast<C02QToolButton*>(buttonGroup.button(id));
      if (checked)
      {
          if(button->hasASubToolButton())
          {
              C02ToolButton* subToolButton=button->getSubToolButton();
          // on doit installer le sub button
          // soit on doit creer la machine d-etat
          // soit on doit creer le menu fils et l'afficher
          // pour l'instant on crree la machine d'état base
            subToolButtonLayout->addWidget(subToolButton);
            subToolButton->setMenuPere(this);
            subToolButton->show();
            subToolButton->buttonToggled(subToolButton->getDefaultButton(),true);
            //subToolButton->buttonToggled(subToolButton->checkedId(),true);
          }else
          {
              while (QLayoutItem* item = subToolButtonLayout->takeAt(0))
               {
                  item->invalidate();
                  if (QWidget* widget = item->widget())widget->hide();
                  subToolButtonLayout->removeItem(item);
               }
              QList<int> alist;
              setStateMachine(button->getNewStateMachine(), alist);
          }
      }
  }
  void C02ToolButton::restoreButtons(int i,QList<int> buttonList)
  {
      C02QToolButton* button;
      // il faut récupérer le bouton il faudrait deconnecter les signals pour que ce ne soit pas reporté dans la scene avant la fin
      button = static_cast<C02QToolButton*>(buttonGroup.button(buttonList.at(i)));
      button->setChecked(true);
       if(button->hasASubToolButton())
      {
          C02ToolButton* subToolButton=button->getSubToolButton();
      // on doit installer le sub button
      // soit on doit creer la machine d-etat
      // soit on doit creer le menu fils et l'afficher
      // pour l'instant on crree la machine d'état base
        subToolButtonLayout->addWidget(subToolButton);
        subToolButton->setMenuPere(this);
        subToolButton->show();
        if (buttonList.size()>(i+1))
        {
            subToolButton->restoreButtons(i+1,buttonList);
        }
        //subToolButton->buttonToggled(subToolButton->checkedId(),true);
      }else
      {
          while (QLayoutItem* item = subToolButtonLayout->takeAt(0))
           {
              item->invalidate();
              if (QWidget* widget = item->widget())widget->hide();
              subToolButtonLayout->removeItem(item);
           }
          QList<int> alist;
          setStateMachine(button->getNewStateMachine(), alist);
       }
  }
  void C02ToolButton::restoreDefaultButtons(void)
  {
      C02QToolButton* button;
      // il faut récupérer le bouton il faudrait deconnecter les signals pour que ce ne soit pas reporté dans la scene avant la fin
      button = static_cast<C02QToolButton*>(buttonGroup.button(getDefaultButton()));
      button->setChecked(true);
      if(button->hasASubToolButton())
      {
       C02ToolButton* subToolButton=button->getSubToolButton();
      // on doit installer le sub button
      // soit on doit creer la machine d-etat
      // soit on doit creer le menu fils et l'afficher
      // pour l'instant on crree la machine d'état base
        subToolButtonLayout->addWidget(subToolButton);
        subToolButton->setMenuPere(this);
        subToolButton->show();
        subToolButton->restoreDefaultButtons();
        //subToolButton->buttonToggled(subToolButton->checkedId(),true);
      }else
      {
          while (QLayoutItem* item = subToolButtonLayout->takeAt(0))
           {
              item->invalidate();
              if (QWidget* widget = item->widget())widget->hide();
              subToolButtonLayout->removeItem(item);
           }
          QList<int> alist;
          setStateMachine(button->getNewStateMachine(), alist);
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

int C02ToolButton::checkedId()
{
    return buttonGroup.checkedId();
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
C02QToolButton* C02ToolButton::addToolButton(QIcon icon)
{
    C02QToolButton* button;
    button=new C02QToolButton;
    //pixmap.scaled()
    //button->setIcon(pixmap.scaled(theIconsize,Qt::KeepAspectRatio));
    button->setCheckable(true );
    button->setIcon(icon);
    button->setIconSize(theIconsize);
    buttonGroup.addButton(button);
    QList<QToolButton*> listButton=buttonGroup.buttons();
    //listButton.append(button);
    gridLayout->addWidget(button,(listButton.size()-1)/nbIconHorizontal,(listButton.size()-1)%nbIconHorizontal,0,0,Qt::AlignCenter);
    if(listButton.size()==1)
    {
        button->setChecked(true);//par defaut le premier est checked
        setDefaultButton(buttonGroup.checkedId());
    }
    return button;
}
C02QToolButton* C02ToolButton::addToolButton(QPixmap pixmap)
{
     return  addToolButton(QIcon(pixmap));
}
C02QToolButton* C02ToolButton::addToolButton(QPixmap pixmap, QString toolTip)
{
    C02QToolButton* button;
    button=addToolButton(pixmap);
    button->setToolTip(toolTip);
    return button;
}
C02QToolButton* C02ToolButton::addToolButton(C02ToolButton* menuFils,QPixmap pixmap, QString toolTip)
{
    C02QToolButton* button;
    button=addToolButton(pixmap);
    button->setToolTip(toolTip);
    button->setSubToolButton(menuFils);
    return button;
}
C02QToolButton* C02ToolButton::addToolButton(C03StateMachineBase::MachineName stateMachineName,QPixmap pixmap, QString toolTip)
{
    C02QToolButton* button;
    button=addToolButton(pixmap);
    button->setToolTip(toolTip);
    button->setStateMachineType(stateMachineName);
    return button;
}
C02QToolButton* C02ToolButton::addToolButton(QPixmap pNorm,QPixmap pAct,QPixmap pSel,QPixmap pDis, QString toolTip)
{
    QIcon icon;
    C02QToolButton* button;
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

   toolButtonWidget->setFixedWidth(nbIconHorizontal*theIconsize.width()+20);
   toolButtonWidget->setFixedHeight(((listButton.size()+nbIconHorizontal-1)/nbIconHorizontal)*theIconsize.height()+20);
}
void C02ToolButton::getFocus(C03stateMachinePositioner* stMachPos)
{
    theStMachPos=stMachPos;
    //provisoire, a reprendre apres
    if(stMachPos!=NULL)
    {
        if (theStMachPos->getStateList().size()>0)
        {
            restoreButtons(0,theStMachPos->getStateList());
            //buttonGroup.button(theStMachPos->getStateList().at(0))->setChecked(true);
        }
    }else
    {
        restoreDefaultButtons();
    }
}
