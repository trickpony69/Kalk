#ifndef RETTA_H
#define RETTA_H

#include "punto.h"

class retta;

//ostream& operator<<(ostream&, const retta&); non serve, come mai ??

class retta{
    friend ostream& operator<<(ostream&, const retta&);//indecisione: uso i getter o la friendship ? Per ora la friendship
private:
    razionale a;
    razionale b;
    razionale c;
public:
    retta(double x=0 , double y = 0 , double l = 0) : a(x),b(y),c(l) {} ;
    razionale GetA() const ;
    razionale GetB() const ;
    razionale GetC() const ;
    static double distancePuntoRetta(punto,retta);
    static retta rettaFromTwoPoints(punto,punto);
    QVector<punto*> printCoord(); //ritorna un vector di puntatori a punti che sono le coordinate calcolate
    //bool isImplicita();
    double distanceRettaRetta(retta&);
    static bool isParallels(retta&,retta&);
    static retta RettaPerpendicolare(retta&,punto&);
    static retta RettaParallella(retta&,punto&);

};

#endif // RETTA_H
