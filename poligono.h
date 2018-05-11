#ifndef POLIGONO_H
#define POLIGONO_H

#include "retta.h"
#include "inputitem.h"
//#include <QPolygonF>
#include <vector>

using std::vector;
using std::istream;

class poligono : public inputitem{
    friend istream& operator>>(istream&,poligono*);
    friend ostream& operator<<(ostream&,poligono*);
private:
    int lati;
protected:
    vector<punto*> pt;
public:
    poligono(int, vector<punto*>);
    poligono() {}
    int GetLati() const;
    vector<punto*> GetPoint() const;
    razionale area() const; //virtuale pura
    virtual razionale perimetro() const ; //virtuale pura
    double lato() const; //ritorna la lunghezza del lato
    razionale isRegular() const;
    static poligono* pars_pol(string);
    virtual double getFisso() const =0;
    vector<punto*> printPoligon(razionale&,razionale&) const;
    //virtual QPolygonF formatToQtPainter() = 0;//virtuale pura
};

#endif // POLIGONO_H
