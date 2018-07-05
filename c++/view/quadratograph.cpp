#include "quadratograph.h"

quadratoGraph::quadratoGraph(grafico* g, poligono* p): poligonGraph(g,p){

}

void quadratoGraph::draw(unsigned k){

    int p = 0 ;

    for(unsigned int i=0; i<poligonGraph::vCoord0.size(); i++)
       graficoEl->writeSegmenti(k,new QCPItemLine(graficoEl));

    for(unsigned int i = 0; i<poligonGraph::vCoord0.size() - 1; i++){
        for(unsigned int j = i + 1; j<vCoord0.size(); j++){
           if(poligonGraph::vCoord0[j]->distanceTwoPoints(*poligonGraph::vCoord0[i]) == poligonGraph::pol->lato() /*|| vCoord0.size() == 3*/){
               graficoEl->readSegmenti(k,p)->start->setCoords(QPointF(poligonGraph::vCoord0[i]->getX(),poligonGraph::vCoord0[i]->getY()));
               graficoEl->readSegmenti(k,p)->end->setCoords(QPointF(poligonGraph::vCoord0[j]->getX(),poligonGraph::vCoord0[j]->getY()));
               ++p;
               qDebug("creato e disegnato lato quadrato");
           }
        }
    }

    for(unsigned int i = 0; i<vCoord0.size() - 1; i++){
        delete vCoord0[i];  //aggiunto nel remake, nessuno si occupava del garbage di VCoord0 mi pare
    }

}

void quadratoGraph::drawing(unsigned k) {

    this->draw(k);
    graficoEl->replot();
}
