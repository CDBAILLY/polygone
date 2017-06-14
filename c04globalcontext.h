#ifndef C04GLOBALCONTEXT_H
#define C04GLOBALCONTEXT_H

#include <QList>
#include <QObject>
#include <QString>
class QTabWidget;
class C04SceneContext;
class C02ToolButton;
class C04GlobalContext
{
public:
    C04GlobalContext();
    QString getUnusedName(void);
    void addContext(C04SceneContext* ptContext);
    void setCurrentContext(C04SceneContext* ptContext);
    C04SceneContext* getCurrentContext(void);
    void removeContext(C04SceneContext* ptContext);
    int contextExists(C04SceneContext* ptContext);
    C04SceneContext* getPt( int tabIndex);
    void setTabWidget(QTabWidget *tabWidget){theTabWidget=tabWidget;};
    QTabWidget * getTabWidget(void){return theTabWidget;};
    void setToolButton(C02ToolButton*toolButton){theToolButton=toolButton;};
    C02ToolButton*getToolButton(void){return theToolButton;};
private:
    QList<C04SceneContext*> projList;
    C04SceneContext* ptCurrentContext;
    QTabWidget *theTabWidget;
    C02ToolButton *theToolButton;

};

#endif // C04GLOBALCONTEXT_H
