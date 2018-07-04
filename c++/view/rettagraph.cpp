#include "rettagraph.h"

rettaGraph::rettaGraph(grafico* g,punto mi,punto ma): graficElement(g), min(mi), max(ma){}


void rettaGraph::drawing(unsigned int k){

    graficElement::graficoEl->writeSegmenti(k,new QCPItemLine(graficElement::graficoEl));
    graficElement::graficoEl->readSegmenti(k,0)->start->setCoords(QPointF(min.getX(),min.getY()));
    graficElement::graficoEl->readSegmenti(k,0)->end->setCoords(QPointF(max.getX(),max.getY()));
}

void rettaGraph::draw(unsigned int k){

    this->drawing(k);
}
