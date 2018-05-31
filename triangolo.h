#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include "poligono.h"

class triangolo : public poligono
{
private:
    static double numeroFisso;
public:
    triangolo(int l,vector<punto*> p): poligono(l,p) {}
    triangolo() {}
    double perimetro() const;
    double getfisso() const;
    double area() const;
    double lato() const;
};

#endif // TRIANGOLO_H
