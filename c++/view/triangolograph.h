#ifndef TRIANGOLOGRAPH_H
#define TRIANGOLOGRAPH_H

#include "view/poligongraph.h"
#include "model/poligono.h"
#include "view/poligongraph.h"

class triangoloGraph : public poligonGraph{
public:
    triangoloGraph(grafico*,poligono*);
    virtual void drawing(unsigned k);
protected:
    void draw(unsigned k);
};

#endif // TRIANGOLOGRAPH_H
