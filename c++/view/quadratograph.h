#ifndef QUADRATOGRAPH_H
#define QUADRATOGRAPH_H

#include "view/poligongraph.h"

class quadratoGraph : public poligonGraph{
public:
    quadratoGraph(grafico*,poligono*);
    void drawing(unsigned k);
protected:
    void draw(unsigned k);
};

#endif // QUADRATOGRAPH_H
