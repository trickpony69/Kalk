#ifndef PUNTOGRAPH_H
#define PUNTOGRAPH_H

#include "view/graficelement.h"
#include "model/punto.h"

class puntoGraph : public graficElement{
public:
    puntoGraph(grafico*,punto*);
    virtual void drawing(unsigned);
private:
    QVector<double> x,y;
protected:
    virtual void draw(unsigned);
};

#endif // PUNTOGRAPH_H
