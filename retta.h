#ifndef RETTA_H
#define RETTA_H

#include "punto.h"

class retta;
static double puntoRetta(punto,retta);

class retta{
     friend double puntoRetta(punto,retta);
private:
    double a;
    double b;
    double c;
public:
    retta(double x=0 , double y = 0 , double l = 0) : a(x),b(y),c(l) {} ;
    double GetA(){ return a; }
    double GetB(){ return b; }
    double GetC(){ return c; }
    /*ritorna un vector di puntatori a punti che sono le coordinate calcolate*/
    QVector<punto*> print();
    //bool isImplicita();

};

#endif // RETTA_H
