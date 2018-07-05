#ifndef GRAFICELEMENT_H
#define GRAFICELEMENT_H

#include "view/grafico.h"

class graficElement{
public:
    graficElement(grafico*);
    virtual void drawing(unsigned) =0;
protected:
    grafico* graficoEl;
    virtual void draw(unsigned) =0;
};

#endif // GRAFICELEMENT_H
