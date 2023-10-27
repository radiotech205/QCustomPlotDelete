#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    mainVL = new QVBoxLayout();
    this->setLayout(mainVL);

    enterHV = new QHBoxLayout();
    mainVL->addLayout(enterHV);

    createPB = new QPushButton(this);
    createPB->setText("Create");
    enterHV->addWidget(createPB);

    deletePB = new QPushButton(this);
    deletePB->setText("Delete");
    enterHV->addWidget(deletePB);


    enterHV->addItem(new QSpacerItem(0,0, QSizePolicy::Expanding,
                                     QSizePolicy::Minimum));

    connect(createPB, SIGNAL(clicked()), this, SLOT(CreatePlotSlot()));
    connect(deletePB, SIGNAL(clicked()), this, SLOT(DeletePlotSlot()));


    plotMap.clear();
    plotCnt = 0;
}

MainWidget::~MainWidget()
{
//    delete mainVL;
//    delete enterHV;
}

void MainWidget::CreatePlotSlot()
{
    PlotWidget* pw = new PlotWidget(this);
    QString plotCntStr = QString("%1").arg(plotCnt);
    plotMap.insert(plotCntStr, pw);
    pw->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding );
    mainVL->addWidget(pw);
    qDebug() << __FUNCTION__ << plotCnt;
    plotCnt++;
}

void MainWidget::DeletePlotSlot()
{
    if(plotCnt > 0)
    {

        QString plotCntStr = QString("%1").arg(plotCnt);
//        PlotWidget* pw = plotMap.take(plotCntStr);
        //pw->removeGraph(pw->plot);
        //mainVL->removeWidget(pw);
        //delete pw;
        plotCnt--;
        //pw->deleteLater();
        QLayoutItem *wItem = mainVL->takeAt(mainVL->count()-1);
        mainVL->removeWidget(wItem->widget());
        delete wItem->widget();
    }
    qDebug() << __FUNCTION__ << plotCnt << mainVL->count();
}

