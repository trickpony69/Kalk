#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include "poligono.h"

class triangolo : public poligono
{
public:
    triangolo(int l,vector<punto*> p): poligono(l,p) {}
    triangolo() {}
    razionale perimetro() const;
    razionale area() const;
    void isFigura() const {cout<<"triangolo";}
};

#endif // TRIANGOLO_H
