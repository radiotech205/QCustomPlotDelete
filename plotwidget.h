#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QObject>
#include <QWidget>
#include "QCustomPlot/qcustomplot.h"

class PlotWidget: public QWidget
{
    Q_OBJECT
public:
    PlotWidget(QWidget *parent = nullptr);
    void addRandomGraph(QCustomPlot* customplot);
    void removeGraph(QCustomPlot* customplot);
    QCustomPlot*    plot;
private:

signals:

public slots:
};

#endif // PLOTWIDGET_H
