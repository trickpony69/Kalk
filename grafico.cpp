#include "grafico.h"

grafico::grafico(){
    // The following plot setup is mostly taken from the plot demos:
    //addGraph();
    //graph()->setPen(QPen(Qt::blue));
    //graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
    //graph()->setPen(QPen(Qt::red));
    // set axes ranges, so we see all data:
    xAxis->setRange(-10, 10);
    yAxis->setRange(-10, 10);
    replot();
    xAxis->setLabel("x");
    yAxis->setLabel("y");
    axisRect()->setupFullAxesBox(true);
    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void grafico::pulisci(){
    clearGraphs();
    replot();
}
