#include "view/puntograph.h"

puntoGraph::puntoGraph(grafico* g,punto* p): graficElement(g){

    x.append(p->xToDouble());
    y.append(p->yToDouble());

}

void puntoGraph::draw(unsigned k){

    graficElement::graficoEl->graph(k)->setData(x,y);
    graficElement::graficoEl->graph(k)->setLineStyle(QCPGraph::lsNone);
    graficElement::graficoEl->graph(k)->setScatterStyle(QCPScatterStyle::ssDisc);
    graficElement::graficoEl->replot();

}

void puntoGraph::drawing(unsigned k){ //solo per poter rendere protected il metodo draw

    this->draw(k);
}