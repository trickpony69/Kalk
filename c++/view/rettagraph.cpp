#include "rettagraph.h"

rettaGraph::rettaGraph(punto mi,punto ma) : min(mi), max(ma){}


void rettaGraph::drawing(grafico* g,unsigned int k){

    g->writeSegmenti(k,new QCPItemLine(g));
    g->readSegmenti(k,0)->start->setCoords(QPointF(min.getX(),min.getY()));
    g->readSegmenti(k,0)->end->setCoords(QPointF(max.getX(),max.getY()));
}

void rettaGraph::draw(grafico* g,unsigned int k){

    this->drawing(g,k);
}
