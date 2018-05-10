#ifndef QUADRATO_H
#define QUADRATO_H

#include "poligono.h"
#include "punto.h"
#include "razionale.h"
#include <vector>

class quadrato : public poligono{
    friend istream& operator>>(istream&,quadrato&);
public:
    quadrato(int l,vector<punto*> p): poligono(l,p) {}
    quadrato() {}
    razionale perimetro() const;
    razionale area() const;
    void isFigura() const {cout<<"quadrato";}
};

#endif // QUADRATO_H
