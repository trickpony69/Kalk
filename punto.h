#ifndef PUNTO_H
#define PUNTO_H
#include <QtCore>
#include <QPoint>

class punto{
private:
    double x,y;
public:
    punto(double a, double b) : x(a),y(b) {}
    Qpoint formatToQtPainter(punto);
};

#endif // PUNTO_H
