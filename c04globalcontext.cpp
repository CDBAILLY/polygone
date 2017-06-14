#include "c04globalcontext.h"
#include "c04scenecontext.h"
#include "c02toolbutton.h"
#include "c01graphicsscene.h"
#include "view.h"
#include <QTabWidget>

C04GlobalContext::C04GlobalContext()
{
    ptCurrentContext=NULL;
}
QString C04GlobalContext::getUnusedName(void)
{
    QString baseName="newproj";
    QString name;
    char theName[30];
    int i=0;
    bool foundName=false;
    do
    {
        sprintf(theName,"nomProj%u",i);
        name=theName;
        foundName=true;
        for(int j=0;j<projList.size();j++)
        {
            if (projList.at(j)->getFileName()==name)
            {
                foundName=false;
            }
        }
        i++;
    }while(foundName==false);
    return name;
}
void C04GlobalContext::addContext(C04SceneContext* context)
{
    projList.append(context);
}
void C04GlobalContext::setCurrentContext(C04SceneContext* ptContext)
{
    if(contextExists(ptContext)>-1)
    {
        ptCurrentContext=ptContext;
    }
    else
    {
        ptCurrentContext=NULL;
    }
}
int C04GlobalContext::contextExists(C04SceneContext* ptContext)
{
    for(int j=0;j<projList.size();j++)
    {
        if (projList.at(j)==ptContext)
        {
            return j;
        }
    }
    return -1;
}
C04SceneContext* C04GlobalContext::getPt(int tabIndex)
{
    for(int j=0;j<projList.size();j++)
    {
        if (projList.at(j)->getTabIndex()==tabIndex)
        {
            return projList.at(j);
        }
    }
    return NULL;
}
C04SceneContext* C04GlobalContext::getCurrentContext(void)
{
     return ptCurrentContext;
}
void C04GlobalContext::removeContext(C04SceneContext* ptContext)
{
    int tabNum=contextExists(ptContext);
    if(tabNum>-1)
    {
        if(ptContext==ptCurrentContext)//il faut changer de contexte
        {
            //attention, il faut se deconnecter de toolsButton
            theToolButton->getFocus(NULL);
            for(int j=0;j<projList.size();j++)
            {
                if (projList.at(j)==ptContext)
                {
                    projList.removeAt(j);
                    break;
                }
            }
            for(int j=0;j<projList.size();j++)
            {
                if (projList.at(j)->getTabIndex()>=tabNum)
                {
                    projList.at(j)->setTabIndex(projList.at(j)->getTabIndex()-1);
                }
            }
            if(projList.size()>0)
            {//on active le premier venu
                ptCurrentContext=projList.at(0);
                theTabWidget->setCurrentIndex(ptCurrentContext->getTabIndex());
                ptCurrentContext->getMainView()->theGraphicsView()->setFocus();
            }else
            {
                ptCurrentContext=NULL;
            }
        }
        else
        {
            for(int j=0;j<projList.size();j++)
            {
                if (projList.at(j)==ptContext)
                {
                    projList.removeAt(j);
                    break;
                }
            }
            for(int j=0;j<projList.size();j++)
            {
                if (projList.at(j)->getTabIndex()>=tabNum)
                {
                    projList.at(j)->setTabIndex(projList.at(j)->getTabIndex()-1);
                }
            }
        }
        // maintenant le dégager
        delete ptContext->getScene();
        theTabWidget->removeTab(ptContext->getTabIndex());
    }
}
