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
    QVector<QCPItemLine*> segmenti;
private:

signals:

public slots:
    void pulisci();
};

#endif // GRAFICO_H
