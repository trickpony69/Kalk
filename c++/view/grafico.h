#ifndef GRAFICO_H
#define GRAFICO_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QPainter>
#include "qcustomplot.h"
#include <iostream>

class grafico : public QCustomPlot{
    Q_OBJECT
public:
    grafico(); //epxlicit o no ?
     QCPItemLine* readSegmenti(int,int);
     void writeSegmenti(int,QCPItemLine*);
     int getSize(int)const;
     void deletePol(int);

private:
    QVector<QVector<QCPItemLine*>> segmenti;
signals:

public slots:
    void pulisci();

};

#endif // GRAFICO_H
