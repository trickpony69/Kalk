#ifndef RETTA_H
#define RETTA_H
#include "eccezioni.h"
#include "punto.h"
#include "inputitem.h"
#include <string>
#include <vector>
using std::istream;
using std::string;
using std::vector;


class retta;

//ostream& operator<<(ostream&, const retta&); non serve, come mai ??

class retta : public inputitem {
    friend istream& operator>>(istream&,retta&);
    friend ostream& operator<<(ostream&, const retta&);//indecisione: uso i getter o la friendship ? Per ora la friendship
private:
    razionale a;
    razionale b;
    razionale c;
public:
    virtual ~retta() {}
    retta(razionale x = 0 , razionale y = 0  , razionale l = 0 ) : a(x),b(y),c(l) {}
    razionale GetA() const;
    razionale GetB() const;
    razionale GetC() const;
    static double distancePuntoRetta(const punto&,const retta&);
    static retta rettaFromTwoPoints(punto&,punto&);
    punto printCoord_x(razionale) const; //ritorna un vector di punti che sono le coordinate calcolate
    double distanceRettaRetta(retta&);
    static bool isParallels(retta&,retta&);
    static bool isPerpendicolari(retta&,retta&);
    static retta RettaPerpendicolare(retta&,punto&);
    static retta RettaParallella(retta&,punto&);
    static vector<punto> Intersect(const retta&,const retta&);
    void pars_rect(string);
    void isFigura() const {cout<<"retta"; }
    vector<punto> print_rect(const razionale&,const razionale&);
    vector<punto> intersect(inputitem*) const ;
    QString toString()const;

};

#endif // RETTA_H
