#include "grafico.h"

grafico::grafico(){
    xAxis->setRange(-10, 10);
    yAxis->setRange(-10, 10);
    replot();
    xAxis->setLabel("x");
    yAxis->setLabel("y");
    axisRect()->setupFullAxesBox(true);
    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

QCPItemLine* grafico::readSegmenti(unsigned int index){
    return segmenti[index];
}

void grafico::writeSegmenti(QCPItemLine* line){
    segmenti.push_back(line);
}


void grafico::pulisci(){
    clearGraphs();
    for(unsigned int i=0; i<segmenti.size(); i++){
        removeItem(segmenti[i]);
    }
    replot();
}

int grafico::getSize()const{
    return segmenti.size();
}
