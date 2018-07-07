#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include "view/grafico.h"
#include "model/inputitem.h"

class graphicElement{
public:
    virtual void drawing(grafico*,unsigned)=0;
    static graphicElement* parsGraphicEl(inputitem*);
    virtual ~graphicElement(){}
protected:
    virtual void draw(grafico*,unsigned)=0;
};

#endif // GRAFICELEMENT_H

