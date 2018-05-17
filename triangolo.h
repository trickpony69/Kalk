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
    double getFisso() const;
    double area() const;
    //vector<retta> printPoligon() const;
    void isFigura() const {cout<<"triangolo";}
    double lato() const;
};

#endif // TRIANGOLO_H
