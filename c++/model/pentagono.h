#ifndef PENTAGONO_H
#define PENTAGONO_H

#include "poligono.h"


class pentagono : public poligono
{
private:
    static double numeroFisso;
public:
    pentagono(int l,vector<punto*> p): poligono(l,p) {}
    pentagono() {}
    double getFisso() const;
    void isFigura() const {cout<<"penta";}
};

#endif // PENTAGONO_H
