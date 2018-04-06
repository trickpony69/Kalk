#include "retta.h"


static double puntoRetta(punto p,retta r){
    return (abs(r.a * p.getX() - r.b * p.getY() + r.c))/(sqrt(pow(r.a,2)+pow(r.b,2)));

}

