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
    razionale perimetro() const;
    double getFisso() const;
    vector<retta> printPoligon() const;
    void isFigura() const {cout<<"triangolo";}
};

#endif // TRIANGOLO_H
