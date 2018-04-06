#include "punto.h"

double punto::getX(){return x;}

double punto::getY(){return y;}

QPoint punto::formatToQtPainter(punto p){
    return QPoint(p.x,p.y);
}

static double distanceTwoPoints(punto p1,punto p2){
    return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
}


