#ifndef PUNTO_H
#define PUNTO_H


#include <QPoint>
#include <QVector>
#include <list>
#include "math.h"
#include <iostream>

using std::ostream;
using std::cout;

class punto;

static double distanceTwoPoints(punto, punto);
ostream& operator<<(ostream&, const punto&);

class punto{
    friend double distanceTwoPoints(punto, punto);
    friend ostream& operator<<(ostream&, const punto&);

private:
    double x,y;
public:
    punto(double a, double b) : x(a),y(b) {}
    QPoint formatToQtPainter(punto);
    double getX();
    double getY();
};

#endif // PUNTO_H
