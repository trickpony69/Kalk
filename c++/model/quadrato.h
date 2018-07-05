#ifndef QUADRATO_H
#define QUADRATO_H

#include "poligono.h"
#include <vector>

class quadrato : public poligono{
private:
    static double numeroFisso;
public:
    quadrato(int l,vector<punto*> p): poligono(l,p) {}
    quadrato() {}
    double getfisso() const;
    double area() const;
};

#endif // QUADRATO_H
