#ifndef GRAFICO_H
#define GRAFICO_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QPainter>
#include "qcustomplot.h"

class grafico : public QCustomPlot{
    Q_OBJECT
public:
    grafico(); //epxlicit o no ?
signals:

public slots:
};

#endif // GRAFICO_H
