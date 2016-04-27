#include "c02toolbutton.h"
#include <QGridLayout>
#include <QToolButton>
C02ToolButton::~C02ToolButton()
{

}
  C02ToolButton::C02ToolButton():QWidget()
{
    nbIconHorizontal=2;
    gridLayout=new QGridLayout;
    this->setLayout(gridLayout);
    gridLayout->setHorizontalSpacing(0);gridLayout->setVerticalSpacing(0);
    gridLayout->setMargin(0);
    gridLayout->setContentsMargins(0,0,0,0);
    this->setContentsMargins(0,0,0,0);
    setIconSize();

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
void C02ToolButton::addToolButton(QPixmap pixmap)
{
    QToolButton* button;
    button=new QToolButton;
    button->setIcon(pixmap);
    button->setIconSize(theIconsize);
    listButton.append(button);
}
void C02ToolButton::redraw( )
{
   for(int i=0;i<listButton.size();i++)
   {
       gridLayout->removeWidget(listButton.at(i));
   }
   for(int i=0;i<listButton.size();i++)
   {
       listButton.at(i)->setIconSize(theIconsize);
       gridLayout->addWidget(listButton.at(i),i/nbIconHorizontal,i%nbIconHorizontal+10);
   }
   setFixedWidth(nbIconHorizontal*theIconsize.width()+10);
   setFixedHeight(((listButton.size()+nbIconHorizontal-1)/nbIconHorizontal)*theIconsize.height()+10);
}
