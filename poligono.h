#ifndef POLIGONO_H
#define POLIGONO_H

#include "retta.h"
//#include <QPolygonF>
#include <vector>

using std::vector;

class poligono{
private:
    int lati;
    vector<punto*> pt;
    //bool regolare; PER ORA SOLO REGOLARI
public:
    poligono(int, vector<punto*>);
    poligono() {}
    int GetLati() const;
    vector<punto*> GetPoint() const;
    virtual razionale area() const = 0; //virtuale pura
    virtual razionale perimetro() const = 0; //virtuale pura
    double razionale lato() const; //ritorna la lunghezza del lato
    razionale isRegular() const;
    //virtual QPolygonF formatToQtPainter() = 0;//virtuale pura
};

#endif // POLIGONO_H
