#ifndef PUNTO_H
#define PUNTO_H


#include <QPoint>
#include <QVector>
#include <list>
#include "math.h"
class punto;

static double distanceTwoPoints(punto, punto);

class punto{
    friend double distanceTwoPoints(punto, punto);

private:
    double x,y;
public:
    punto(double a, double b) : x(a),y(b) {}
    QPoint formatToQtPainter(punto);
    double getX();
    double getY();
};

#endif // PUNTO_H
