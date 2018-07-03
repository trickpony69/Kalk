#ifndef GRAFICELEMENT_H
#define GRAFICELEMENT_H

#include "view/grafico.h"

class graficElement{
public:
    graficElement(grafico*);
    virtual void draw(unsigned)const =0;
protected:
    grafico* graficoEl;
};

#endif // GRAFICELEMENT_H
