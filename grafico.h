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
     QCPItemLine* readSegmenti(unsigned int);
     void writeSegmenti(QCPItemLine*);
     int getSize()const;

private:
    QVector<QCPItemLine*> segmenti;
signals:

public slots:
    void pulisci();
};

#endif // GRAFICO_H
