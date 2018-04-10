#ifndef POLIGONO_H
#define POLIGONO_H

//#include "punto.h"
#include <QPolygonF>

class poligono{
private:
    int lati;
    bool regolare;//da implementare qui o no ?
public:
    poligono(int l): lati(l),regolare(1){}
    virtual double area() = 0;//virtuale pura
    virtual double perimetro() = 0;//virtuale pura
    virtual QPolygonF formatToQtPainter() = 0;//virtuale pura
};

#endif // POLIGONO_H
