#include "retta.h"


double retta::GetA(){ return a; }

double retta::GetB(){ return b; }

double retta::GetC(){ return c; }

double retta::distancePuntoRetta(punto p, retta r){
    return ((abs(r.a * p.getX() - r.b * p.getY() + r.c))/(sqrt(pow(r.a,2)+pow(r.b,2))));
}

retta retta::rettaFromTwoPoints(punto p1,punto p2){
    double m = ((p2.getY()-p1.getY())/(p2.getX()-p1.getX()));
    return retta(-m,1,((-p2.getY())) + (m*(p2.getX())));
}

ostream& operator<<(ostream& buffer, const retta& r){
    return buffer<<"("<<r.a<<"x+"<<r.b<<"y+"<<r.c<<")"<<std::endl;
}

double retta::distanceRettaRetta(retta& r2) {
    if(!isParallels(*this,r2)){
        return distancePuntoRetta(punto(1,(-1)*(r2.GetA()/r2.GetB()) - r2.GetC()/r2.GetB()),*this);
    }
    else return 0;
}

bool retta::isParallels(retta& r1 , retta& r2 ){
    //std::cout<<(-1)*(r1.GetA()/r1.GetB())<< " " << (-1)*(r2.GetA()/r2.GetB());
    return (-1)*(r1.GetA()/r1.GetB()) == (-1)*(r2.GetA()/r2.GetB());
}
