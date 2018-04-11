#include "punto.h"

razionale punto::getX() const {return x;}

razionale punto::getY() const {return y;}

QPoint punto::formatToQtPainter(punto p){
    return QPoint(p.x,p.y);
}

double punto::distanceTwoPoints(punto p1,punto p2){
    return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
}

ostream& operator<<(ostream& buffer, const punto& p){
    return buffer<<"("<<p.x<<","<<p.y<<")";
}
