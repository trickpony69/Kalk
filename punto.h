#ifndef PUNTO_H
#define PUNTO_H

//#include <QtWidgets>
//#include <QPoint>
#include <QVector>
//#include <QPoint>
#include <list>
#include "math.h"
#include <iostream>
#include "razionale.h"
#include "eccezioni.h"
#include "inputitem.h"
#include "retta.h"

using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::string;

class punto;

ostream& operator<<(ostream&, const punto&);

class punto : public inputitem {
    friend ostream& operator<<(ostream&, const punto&);
    friend istream& operator>>(istream&, punto&);
private:
    razionale x,y;
public:
    punto() {}
    virtual ~punto() {}
    punto( razionale a , razionale b ) : x(a),y(b) {}
    //virtual QPoint formatToQtPainter(punto);
    razionale getX() const;
    razionale getY() const;
    static double distanceTwoPoints(const punto&,const punto&);
    void pars_point(string);
    double xToDouble() const;
    double yToDouble() const;
    QString toString();
    vector<punto> intersect(inputitem *) const ;
    bool operator==( const punto& );
    double distance(inputitem *) const;

};

#endif // PUNTO_H
