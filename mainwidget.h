#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QDebug>

#include "plotwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
private:
    QPushButton*    createPB;
    QPushButton*    deletePB;
    QVBoxLayout*    mainVL;
    QHBoxLayout*    enterHV;
    QMap<QString,PlotWidget*>   plotMap;
    int             plotCnt;
signals:

public slots:
    void CreatePlotSlot();
    void DeletePlotSlot();
};

#endif // MAINWIDGET_H
