#ifndef GRAFICELEMENT_H
#define GRAFICELEMENT_H

#include "view/grafico.h"
#include "model/inputitem.h"

class graficElement{
public:
    virtual void drawing(grafico*,unsigned)=0;
    static graficElement* parsGraphicEl(inputitem*);
protected:
    virtual void draw(grafico*,unsigned)=0;
};

#endif // GRAFICELEMENT_H
