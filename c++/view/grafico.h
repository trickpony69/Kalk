#ifndef GRAFICO_H
#define GRAFICO_H

#include "view/qcustomplot.h"

class grafico : public QCustomPlot{
    Q_OBJECT
public:
    grafico();
    virtual ~grafico(){}
    QCPItemLine* readSegmenti(int,int);
    void writeSegmenti(int,QCPItemLine*);
    int getSize(int)const;
    void deletePol(int);

private:
    QVector<QVector<QCPItemLine*>> segmenti; //segmenti.size puo' essere max = 3 cioe' il massimo numero di slot

public slots:
    void pulisci();

};

#endif // GRAFICO_H
