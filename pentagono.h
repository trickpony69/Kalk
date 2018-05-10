#ifndef PENTAGONO_H
#define PENTAGONO_H

#include "poligono.h"


class pentagono : public poligono
{
public:
    pentagono(int l,vector<punto*> p): poligono(l,p) {}
    pentagono() {}
    razionale area() const;
    void isFigura() const {cout<<"penta";}
};

#endif // PENTAGONO_H
