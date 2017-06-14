/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$                          
**
****************************************************************************/

#include "mainwindow.h"
#include "view.h"
#include "c01graphicsscene.h"
#include "c02toolbutton.h"
#include "c04scenecontext.h"

#include <QMenuBar>
#include <QHBoxLayout>
#include <QSplitter>
#include <QTabWidget>
#include <QtWidgets>
#include <QFrame>
#include <QStyleFactory>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{


    QSplitter *vGlobalHorizontalSplitter = new QSplitter;
    vGlobalHorizontalSplitter->setOrientation(Qt::Horizontal);
    QWidget *vLeftBox=new QWidget;
    QVBoxLayout *vLeftBoxLayout=new QVBoxLayout;
    vLeftBoxLayout->setMargin(0);
    vLeftBoxLayout->setContentsMargins(0,0,0,0);

    vLeftBox->setLayout(vLeftBoxLayout);


    vGlobalHorizontalSplitter->addWidget(vLeftBox);

    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->setTabsClosable(true);
    connect(tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::tabCloseRequested);
    globalContext.setTabWidget(tabWidget);

    vGlobalHorizontalSplitter->addWidget(tabWidget);

    QVBoxLayout *PrimaryLayout=new QVBoxLayout;

    QHBoxLayout *layout = new QHBoxLayout;
    QWidget *layoutWidget=new QWidget;

    layout->addWidget(vGlobalHorizontalSplitter);
    //PrimaryLayout->setStretchFactor(layout,20);

    //PrimaryLayout->addLayout(layout);
    setLayout(PrimaryLayout);
    layoutWidget->setLayout(layout);
    /************  Menu Bar *******************************************/
    QMenuBar * menuBar= new QMenuBar ;
    //-----------
    QMenu *fileMenu = menuBar->addMenu(tr("&File"));
        //-----------
        QAction *newAct = new QAction(tr("&New"), this);;
        newAct->setShortcuts(QKeySequence::New);
        newAct->setStatusTip(tr("Create a new Projet"));
        connect(newAct, &QAction::triggered, this, &MainWindow::newProj);
        fileMenu->addAction(newAct);
        //-----------
        newAct = new QAction(tr("&Open"), this);;
        newAct->setShortcuts(QKeySequence::New);
        newAct->setStatusTip(tr("Open a file"));
        fileMenu->addAction(newAct);
        //-----------
        newAct = new QAction(tr("&Save"), this);;
        newAct->setShortcuts(QKeySequence::New);
        newAct->setStatusTip(tr("Save current project"));
        fileMenu->addAction(newAct);
        //-----------
        newAct = new QAction(tr("&Save as"), this);;
        newAct->setShortcuts(QKeySequence::New);
        newAct->setStatusTip(tr("Save current project as"));
        fileMenu->addAction(newAct);
        //-----------
        newAct = new QAction(tr("&Close"), this);;
        newAct->setShortcuts(QKeySequence::New);
        newAct->setStatusTip(tr("Close project"));
        fileMenu->addAction(newAct);
        connect(newAct, &QAction::triggered, this, &MainWindow::closeProj);
    //-----------
    fileMenu = menuBar->addMenu(tr("&Tools"));
    //-----------
    fileMenu = menuBar->addMenu(tr("&About"));
        //-----------
        newAct = new QAction(tr("&About"), this);;
        newAct->setShortcuts(QKeySequence::New);
        newAct->setStatusTip(tr("Nothing for now"));
        fileMenu->addAction(newAct);
        //-----------
        newAct = new QAction(tr("&Preference"), this);;
        newAct->setShortcuts(QKeySequence::New);
        newAct->setStatusTip(tr("Settings"));
        fileMenu->addAction(newAct);
    /************  End Menu Bar *******************************************/
    PrimaryLayout->addWidget(menuBar);
    menuBar->setFixedHeight(25);
    PrimaryLayout->addWidget(layoutWidget);
    setWindowTitle(tr("Polygone"));
    /******************* nouveau  ******************************************/
    C02ToolButton *toolButton2=new C02ToolButton;
    toolButton2->setIconSize( 30);
    toolButton2->setNbIconHorizontal(2);
    (toolButton2->addToolButton(C03StateMachineBase::MachineBase,QPixmap(":/select.png"),"select 2"))->setChecked(true);
    toolButton2->addToolButton(C03StateMachineBase::MachineBase,QPixmap(":/edit-polygon.png"),"edit polygon 2");
    toolButton2->addToolButton(C03StateMachineBase::MachineBase,QPixmap(":/draw-polygon.png"),"create polygon 2");
    toolButton2->redraw();

    C02ToolButton *toolButton=new C02ToolButton;
    toolButton->setIconSize( 30);
    toolButton->setNbIconHorizontal(2);
    (toolButton->addToolButton(C03StateMachineBase::MachineBase,QPixmap(":/select.png"),"select"))->setChecked(true);
    toolButton->addToolButton(toolButton2,QPixmap(":/edit-polygon.png"),"edit polygon");
    toolButton->addToolButton(C03StateMachineBase::MachineBase,QPixmap(":/draw-polygon.png"),"create polygon");
    toolButton->redraw();
    globalContext.setToolButton(toolButton);

    QFrame * RemainingPlaceWidget=new QFrame;
    RemainingPlaceWidget->setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    //RemainingPlaceWidget->setFixedHeight(65);
    //RemainingPlaceWidget->setMaximumHeight(1000);
    vLeftBoxLayout->addWidget(toolButton);
    vLeftBoxLayout->addWidget(RemainingPlaceWidget);
    //ButtonWidget->setFixedHeight(100);
    vLeftBoxLayout->setStretchFactor(RemainingPlaceWidget,20);


    /******************* creer les scenes ******************************************/
    newProj();
    /******************* creer les outils ******************************************/

}
void MainWindow::newProj()
{

    C01GraphicsScene *scene;
    C04SceneContext *context;
    scene = new C01GraphicsScene;
    scene->populateScene();
    scene->registerToolButton(globalContext.getToolButton());
    QSplitter *horSplitter = new QSplitter;
    QString name=globalContext.getUnusedName();
    int tabIndex=globalContext.getTabWidget()->addTab(horSplitter,name);
    globalContext.getTabWidget()->setCurrentIndex(tabIndex);
    View* theView=scene->addView(name);
    horSplitter->addWidget(theView);
    horSplitter->addWidget(scene->addView(name));
    context =new C04SceneContext(scene,theView,tabIndex,name);
    scene->setSceneContext(context);
    globalContext.addContext(context);
    globalContext.setCurrentContext(context);
    //theView->theGraphicsView()->activateWindow();

    connect(scene, &C01GraphicsScene::sceneActive, this, &MainWindow::sceneActive);
    theView->theGraphicsView()->setFocus();
    globalContext.getToolButton()->restoreDefaultButtons();

}
void MainWindow::tabCloseRequested(int tabIndex)
{
    C04SceneContext* ptContext=globalContext.getPt(tabIndex);
    if (ptContext!=NULL)
    {
        globalContext.removeContext(ptContext);
    }
}
void MainWindow::closeProj()
{
    C04SceneContext* ptContext=globalContext.getCurrentContext();
    if (ptContext!=NULL)
    {
        globalContext.removeContext(ptContext);
    }
}

void  MainWindow::sceneActive(C04SceneContext* context,bool isActive)
{
    QString A;
    A.append("Polygone : ");
    if(isActive)
    {
        A.append(context->getFileName());
        setWindowTitle(A);
        globalContext.setCurrentContext(context);
    }
    else
    {
        //A.append("NONE");
        //globalContext.setCurrentContext(NULL);
    }
    setWindowTitle(A);
}


