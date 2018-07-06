#include "view/puntograph.h"

puntoGraph::puntoGraph(punto* p){

    x.append(p->xToDouble());
    y.append(p->yToDouble());
}

void puntoGraph::draw(grafico* g,unsigned k){

    g->graph(k)->setData(x,y);
    g->graph(k)->setLineStyle(QCPGraph::lsNone);
    g->graph(k)->setScatterStyle(QCPScatterStyle::ssDisc);
    g->replot();

}

void puntoGraph::drawing(grafico* g,unsigned k){ //solo per poter rendere protected il metodo draw

    this->draw(g,k);
}
