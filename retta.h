#ifndef RETTA_H
#define RETTA_H

#include "punto.h"

class retta;

//ostream& operator<<(ostream&, const retta&); non serve, come mai ??

class retta{
     friend ostream& operator<<(ostream&, const retta&);//indecisione: uso i getter o la friendship ? Per ora la friendship
private:
    double a;
    double b;
    double c;
public:
    retta(double x=0 , double y = 0 , double l = 0) : a(x),b(y),c(l) {} ;
    double GetA();
    double GetB();
    double GetC();
    static double distancePuntoRetta(punto,retta);
    static retta rettaFromTwoPoints(punto,punto);
    QVector<punto*> printCoord(); //ritorna un vector di puntatori a punti che sono le coordinate calcolate
    //bool isImplicita();

};

#endif // RETTA_H
