#ifndef QUADRATO_H
#define QUADRATO_H

#include "poligono.h"
#include "punto.h"
#include "razionale.h"
#include <vector>

class quadrato : public poligono{
    friend istream& operator>>(istream&,quadrato&);
    friend ostream& operator<<(ostream&, const quadrato&);
public:
    quadrato(int l,list<punto*> p): poligono(l,p) {}
    quadrato() {}
    razionale perimetro() const;
    razionale area() const;
};

#endif // QUADRATO_H
