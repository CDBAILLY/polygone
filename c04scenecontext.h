#ifndef C04SCENECONTEXT_H
#define C04SCENECONTEXT_H

#include <QObject>
#include <QString>
#include <QDir>
class C01GraphicsScene;
class View;
class C04SceneContext
{
public:
    ~C04SceneContext();
    C04SceneContext(C01GraphicsScene * scene,View* theMainView,int tabIndex, QString name,QString path="");
    C01GraphicsScene * getScene(void){return theScene;};
    View * getMainView(void){return mainView;};
    int getTabIndex(void){return theTabIndex;};
    void setTabIndex(int index){ theTabIndex=index;};
    QString getFileName(void){return fileName;};
    QDir* getFileDir(void){return fileDir;};
private:
    bool wasSaved;
    QString fileName;
    QDir  *fileDir;
    int theTabIndex;
    C01GraphicsScene * theScene;
    View* mainView;
};

#endif // C04SCENECONTEXT_H
