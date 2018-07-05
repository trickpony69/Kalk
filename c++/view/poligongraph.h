#ifndef POLIGONGRAPH_H
#define POLIGONGRAPH_H

#include "view/graficelement.h"
#include "model/poligono.h"
#include "model/punto.h"

class poligonGraph : public graficElement{
public:
    poligonGraph(grafico*,poligono*);
    virtual void drawing(unsigned k);
private:


protected:
    vector<punto*> vCoord0;
    poligono* pol;
    void draw(unsigned k);
};

#endif // POLIGONGRAPH_H
