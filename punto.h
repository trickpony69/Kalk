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
    double x,y;
public:
    punto(double a, double b) : x(a),y(b) {}
    virtual QPoint formatToQtPainter(punto);
    double getX();
    double getY();
    static double distanceTwoPoints(punto, punto);
};

#endif // PUNTO_H
