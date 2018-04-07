#include "retta.h"

static double distancePuntoRetta(punto p,retta r){
    return ((abs(r.a * p.getX() - r.b * p.getY() + r.c))/(sqrt(pow(r.a,2)+pow(r.b,2))));
}

static retta rettaFromTwoPoints(punto p1,punto p2){
    double m = ((p2.getY()-p1.getY())/(p2.getX()-p1.getX()));
    return retta(-m,1,((-p2.getY())) + (m*(p2.getX())));
}

ostream& operator<<(ostream& buffer, const retta& r){
    return buffer<<r.a<<"x+"<<r.b<<"y+"<<r.c<<std::endl;
}
