#ifndef POLIGONGRAPH_H
#define POLIGONGRAPH_H

#include "view/graphicelement.h"
#include "model/poligono.h"
#include "model/punto.h"

class poligonGraph : public graphicElement{
public:
    poligonGraph(poligono*);
    virtual void drawing(grafico*,unsigned k);
    ~poligonGraph();
private:


protected:
    vector<punto*> vCoord0;
    poligono* pol;
    void draw(grafico*,unsigned k);
};

#endif // POLIGONGRAPH_H
