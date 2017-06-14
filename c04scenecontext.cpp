#include "c04scenecontext.h"

C04SceneContext::C04SceneContext(C01GraphicsScene * scene,View* theMainView,int tabIndex, QString name,QString path)
{
    theScene=scene;
    mainView=theMainView;
    theTabIndex=tabIndex;
    wasSaved=false;
    fileDir=new QDir(path);
    fileName=name;
}
C04SceneContext::~C04SceneContext()
{
    delete fileDir;
}
