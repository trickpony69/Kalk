#ifndef RETTA_H
#define RETTA_H

#include "punto.h"
#include <string>
#include<vector>
using std::istream;
using std::string;
using std::vector;


class retta;

//ostream& operator<<(ostream&, const retta&); non serve, come mai ??

class retta{
    friend istream& operator>>(istream&,retta&);
    friend ostream& operator<<(ostream&, const retta&);//indecisione: uso i getter o la friendship ? Per ora la friendship
private:
    razionale a;
    razionale b;
    razionale c;
public:
    retta() {}
    retta(razionale x , razionale y , razionale l ) : a(x),b(y),c(l) {} ;
    razionale GetA() const ;
    razionale GetB() const ;
    razionale GetC() const ;
    static double distancePuntoRetta(punto&,retta&);
    static retta rettaFromTwoPoints(punto&,punto&);
    punto& printCoord(razionale) const; //ritorna un vector di puntatori a punti che sono le coordinate calcolate
    double distanceRettaRetta(retta&);
    static bool isParallels(retta&,retta&);
    static bool isPerpendicolari(retta&,retta&);
    static retta RettaPerpendicolare(retta&,punto&);
    static retta RettaParallella(retta&,punto&);
    static punto Intersect(retta&,retta&);
    void pars_rect(string);

};

#endif // RETTA_H
