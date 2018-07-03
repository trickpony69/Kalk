#include "puntograph.h"

puntoGraph::puntoGraph(grafico* g,punto* p): graficElement(g){

    x.append(p->xToDouble());
    y.append(p->yToDouble());

}

void draw(unsigned k) const{

    graficElement::graficoEl->graph(k)->setData(x,y);
    graficElement::graficoEl->graph(k)->setLineStyle(QCPGraph::lsNone);
    graficElement::graficoEl->graph(k)->setScatterStyle(QCPScatterStyle::ssDisc);
    graficElement::graficoEl->replot();

}
