#ifndef RETTA_H
#define RETTA_H
#include "eccezioni.h"
#include "punto.h"
#include "inputitem.h"
#include <string>
#include <vector>
using std::ostream;
using std::string;
using std::vector;

class retta : public inputitem {
    friend ostream& operator<<(ostream&, const retta&);
private:
    razionale a;
    razionale b;
    razionale c;
public:
    retta(razionale x = 0 , razionale y = 0  , razionale l = 0 ) : a(x),b(y),c(l) {}
    razionale GetA() const;
    razionale GetB() const;
    razionale GetC() const;
    double distancePuntoRetta(const punto&) const;
    static retta rettaFromTwoPoints(const punto&,const punto&);
    punto printCoord_x(razionale) const;
    double distanceRettaRetta(retta&) const;
    bool isParallels(retta&) const;
    bool isPerpendicolari(retta&) const;
    retta RettaPerpendicolare(punto&) const;
    retta RettaParallela(punto&) const;
    vector<punto> Intersect_rette(const retta&) const;
    void pars_rect(string);
    vector<punto> print_rect(const razionale&,const razionale&);
    vector<punto> intersect(inputitem*) const ;
    QString toString()const;
    double distance(inputitem *) const;
};

#endif // RETTA_H
