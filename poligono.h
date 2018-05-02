#ifndef POLIGONO_H
#define POLIGONO_H

#include "punto.h"
#include "razionale.h"
//#include <QPolygonF>
#include <list>

using std::list;

class poligono{
private:
    int lati;
    list<punto*> pt;
    //bool regolare; PER ORA SOLO REGOLARI
public:
    poligono(int, list<punto*>);
    poligono() {}
    int GetLati() const;
    list<punto*> GetPoint() const;
    virtual razionale area() const = 0;//virtuale pura
    virtual razionale perimetro() const = 0;//virtuale pura
    virtual razionale lato() const; //ritorna la lunghezza del lato
    //virtual QPolygonF formatToQtPainter() = 0;//virtuale pura
};

#endif // POLIGONO_H
