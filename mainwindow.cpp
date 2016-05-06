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

#include <QHBoxLayout>
#include <QSplitter>
#include <QtWidgets>
#include <QStyleFactory>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    h1Splitter = new QSplitter;
    h2Splitter = new QSplitter;

    QSplitter *vGlobalHorizontalSplitter = new QSplitter;
    vGlobalHorizontalSplitter->setOrientation(Qt::Horizontal);
    QWidget *vLeftBox=new QWidget;
    QVBoxLayout *vLeftBoxLayout=new QVBoxLayout;
    vLeftBox->setLayout(vLeftBoxLayout);


    vGlobalHorizontalSplitter->addWidget(vLeftBox);

    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Vertical);
    vSplitter->addWidget(h1Splitter);
    vSplitter->addWidget(h2Splitter);

    vGlobalHorizontalSplitter->addWidget(vSplitter);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(vGlobalHorizontalSplitter);
    setLayout(layout);

    setWindowTitle(tr("Polygone"));
    /******************* tool buttons ******************************************/
 /*   QGridLayout * gridLayout=new QGridLayout;
    //QButtonGroup //pour gerer les boutons ensemble apreès, une classe ferait l'affaire'
    int size = style()->pixelMetric(QStyle::PM_ToolBarIconSize);
    QSize iconSize(size, size);

    QToolButton *zoomOutIcon = new QToolButton;
    zoomOutIcon->setIcon(QPixmap(":/zoomout.png"));
    zoomOutIcon->setIconSize(iconSize);

    gridLayout->addWidget(zoomOutIcon);

    QToolButton *zoomOutIcon1 = new QToolButton;
    zoomOutIcon1->setIcon(QPixmap(":/zoomin.png"));
    zoomOutIcon1->setIconSize(iconSize);

    gridLayout->addWidget(zoomOutIcon1);

    QToolButton *zoomOutIcon2 = new QToolButton;
    zoomOutIcon2->setIcon(QPixmap(":/fileprint.png"));
    zoomOutIcon2->setIconSize(iconSize);

    gridLayout->addWidget(zoomOutIcon2);

    QWidget * ButtonWidget=new QWidget;
    ButtonWidget->setLayout(gridLayout);
    gridLayout->setHorizontalSpacing(0);gridLayout->setVerticalSpacing(0);
    vLeftBoxLayout->addWidget(ButtonWidget);*/
    /******************* nouveau  ******************************************/
    QWidget * RemainingPlaceWidget=new QWidget;
    C02ToolButton *toolButton=new C02ToolButton;
    vLeftBoxLayout->addWidget(toolButton);
    toolButton->setIconSize( 30);
    toolButton->setNbIconHorizontal(2);
    //toolButton->addToolButton(QPixmap(":/select-pass.png"),QPixmap(":/select-gris.png"),QPixmap(":/select-on.png"),QPixmap(":/select-no.png"),"select");
    //toolButton->addToolButton(QPixmap(":/select-pass.png"),QPixmap(":/draw-polygon.png"),QPixmap(":/fileprint.png"),QPixmap(":/zoomout.png"),"truc");
    (toolButton->addToolButton(QPixmap(":/select.png"),"select"))->setChecked(true);
    toolButton->addToolButton(QPixmap(":/edit-polygon.png"),"edit polygon");
    toolButton->addToolButton(QPixmap(":/draw-polygon.png"),"create polygon");
   // toolButton->addToolButton(QPixmap(":/zoomout.png"));
    toolButton->redraw();

    vLeftBoxLayout->addWidget(RemainingPlaceWidget);
 //   ButtonWidget->setFixedHeight(100);

    /******************* creer les scenes ******************************************/
    scene1 = new C01GraphicsScene;
    scene1->populateScene();
    scene1->registerToolButton(toolButton);
    scene2 = new C01GraphicsScene;
    scene2->populateScene();
    scene2->registerToolButton(toolButton);

    h1Splitter->addWidget(scene1->addView("Top left view"));
    h1Splitter->addWidget(scene1->addView("Top right view"));
    h2Splitter->addWidget(scene2->addView("Bottom left view"));
    h2Splitter->addWidget(scene2->addView("Bottom right view"));
    /******************* creer les outils ******************************************/

}


