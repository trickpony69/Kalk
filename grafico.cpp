#include "grafico.h"

grafico::grafico(){
    xAxis->setRange(-10, 10);
    yAxis->setRange(-10, 10);
    replot();
    xAxis->setLabel("x");
    yAxis->setLabel("y");
    axisRect()->setupFullAxesBox(true);
    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    for(int i=0; i<3; i++){
        QVector<QCPItemLine*> f;
        segmenti.push_back(f);
    }

}

QCPItemLine* grafico::readSegmenti(int slot,int index){
    return segmenti[slot][index];
}

void grafico::writeSegmenti(int slot,QCPItemLine* line){
        segmenti[slot].push_back(line);
}

void grafico::pulisci(){
    /*****ci devo pensare*****/
    for(unsigned int i=0; i<segmenti.size(); i++){
        for(unsigned int j=0; j<segmenti[i].size(); j++){
            removeItem(segmenti[i][j]);
            //segmenti[i].pop_back();
        }
    }
    clearGraphs();
    replot();
}

int grafico::getSize(int slot)const{
    return segmenti[slot].size();
}
