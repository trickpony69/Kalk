#ifndef PUNTO_H
#define PUNTO_H

#include "math.h"
#include "razionale.h"
#include "eccezioni.h"
#include "inputitem.h"


using std::ostream;
using std::cout;
using std::string;

class punto;

ostream& operator<<(ostream&, const punto&);

class punto : public inputitem {
    friend ostream& operator<<(ostream&, const punto&);
private:
    razionale x,y;
public:
    punto() {}
    punto( razionale a , razionale b ) : x(a),y(b) {}
    razionale getX() const;
    razionale getY() const;
    double distanceTwoPoints(const punto&) const;
    void pars_point(string);
    double xToDouble() const;
    double yToDouble() const;
    string toString();
    vector<punto> intersect(inputitem *) const ;
    bool operator==( const punto& );
    double distance(inputitem *) const;
};

#include "retta.h"
#include <locale> //serve per verificare char == numero
#include <sstream> //serve per verificare char == numero
#include <stdlib.h>

#endif // PUNTO_H
