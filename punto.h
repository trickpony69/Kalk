#ifndef PUNTO_H
#define PUNTO_H

//#include <QtWidgets>
//#include <QPoint>
#include <QVector>
#include <QPoint>
#include <list>
#include "math.h"
#include <iostream>
#include "razionale.h"

using std::ostream;
using std::cout;

class punto;

ostream& operator<<(ostream&, const punto&);

class punto{
    friend ostream& operator<<(ostream&, const punto&);

private:
    razionale x,y;
public:
    punto() {}
    punto( razionale a , razionale b ) : x(a),y(b) {}
    virtual QPoint formatToQtPainter(punto);
    razionale getX() const;
    razionale getY() const;
    static double distanceTwoPoints(punto, punto);
};

#endif // PUNTO_H
