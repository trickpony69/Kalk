#include "poligongraph.h"

poligonGraph::poligonGraph(poligono* p) : vCoord0(p->getpoint()), pol(p){}


void poligonGraph::draw(grafico* g,unsigned k){
    int p = 0 ;

    for(unsigned int i=0; i<vCoord0.size(); i++)
       g->writeSegmenti(k,new QCPItemLine(g));

    for(unsigned int i = 0; i<vCoord0.size() - 1; i++){
        for(unsigned int j = i + 1; j<vCoord0.size(); j++){
           if(vCoord0[j]->distanceTwoPoints(*vCoord0[i]) == poligonGraph::pol->lato() || vCoord0.size() == 3){
               g->readSegmenti(k,p)->start->setCoords(QPointF(vCoord0[i]->getX(),vCoord0[i]->getY()));
               g->readSegmenti(k,p)->end->setCoords(QPointF(vCoord0[j]->getX(),vCoord0[j]->getY()));
               ++p;
           }
        }
    }
}

void poligonGraph::drawing(grafico* g,unsigned k){
    this->draw(g,k);
}


poligonGraph::~poligonGraph(){

    for(unsigned int i = 0; i<vCoord0.size() - 1; i++)
        delete vCoord0[i];
}
