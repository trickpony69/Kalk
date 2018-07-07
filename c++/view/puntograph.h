#ifndef PUNTOGRAPH_H
#define PUNTOGRAPH_H

#include "view/graphicelement.h"
#include "model/punto.h"

class puntoGraph : public graphicElement{
public:
    puntoGraph(punto*);
    virtual void drawing(grafico*,unsigned);
private:
    QVector<double> x,y;
protected:
    virtual void draw(grafico*,unsigned);
};

#endif // PUNTOGRAPH_H
