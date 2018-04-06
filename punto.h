#ifndef PUNTO_H
#define PUNTO_H


#include <QPoint>
#include <QVector>
#include <list>

class punto{
    distanceTwoPoints(punto p1, punto p2);

private:
    double x,y;
public:
    punto(double a, double b) : x(a),y(b) {}
    QPoint formatToQtPainter(punto);
};

#endif // PUNTO_H
