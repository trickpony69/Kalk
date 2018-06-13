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

QCPItemLine* grafico::readSegmenti(int slot,int index){
    return segmenti[slot][index];
}

void grafico::writeSegmenti(int slot,QCPItemLine* line){
        segmenti[slot].push_back(line);
}

void grafico::deletePol(int slot){
    for(int i=segmenti[slot].size()-1; i>=0;i--){
        removeItem(segmenti[slot][i]);
        segmenti[slot].remove(i);
    }
}

void grafico::pulisci(){
    /*****ci devo pensare non so se lascia garbage*****/
        for(int i=0; i<segmenti.size(); i++)
            deletePol(i);
        if(!segmenti.isEmpty())
            segmenti.clear();

        //ripopola il vettore più esterno
        for(int i=0; i<3; i++){
            QVector<QCPItemLine*> f;
            segmenti.push_back(f);
        }
        clearGraphs();
        replot();
}

int grafico::getSize(int slot)const{
    return segmenti[slot].size();
}
