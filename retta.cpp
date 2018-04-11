#include "retta.h"


razionale retta::GetA() const { return a; }

razionale retta::GetB() const { return b; }

razionale retta::GetC() const { return c; }

double retta::distancePuntoRetta(punto p, retta r){
    return ((abs(r.a * p.getX() - r.b * p.getY() + r.c))/(sqrt(pow(r.a,2)+pow(r.b,2))));
}

retta retta::rettaFromTwoPoints(punto p1,punto p2){
    double m = ((p2.getY()-p1.getY())/(p2.getX()-p1.getX()));
    return retta(-m,1,((-p2.getY())) + (m*(p2.getX())));
}

ostream& operator<<(ostream& buffer, const retta& r){
    buffer<<"(";
    if(r.a != 0)
        buffer<<r.a<<"x";

    if(r.b > 0) buffer<<"+";
    if(r.b != 0){
        buffer<<r.b<<"y";
    }

    if(r.c > 0) buffer<<"+";
    if(r.c != 0){
        buffer<<r.c;
    }

    buffer<<" =0 )";
    return buffer;
}

double retta::distanceRettaRetta(retta& r2) {
    if(isParallels(*this,r2)){
        //std::cout<<"(0,"<<(0)*(r2.GetA()/r2.GetB()) - r2.GetC()/r2.GetB()<<")"<<std::endl;
        //std::cout<<"(0,"<<(0)*(GetA()/GetB()) - GetC()/GetB()<<")"<<std::endl;
        return distancePuntoRetta(punto(0,(0)*(r2.GetA()/r2.GetB()) - r2.GetC()/r2.GetB()),*this);
    }
    else return 0;
}

bool retta::isParallels(retta& r1 , retta& r2 ){
    //std::cout<<(-1)*(r1.GetA()/r1.GetB())<< " " << (-1)*(r2.GetA()/r2.GetB());
    double coeffA = (-1)*(r1.GetA()/r1.GetB());
    double coeffB = (-1)*(r2.GetA()/r2.GetB());
    return coeffA == coeffB;
}

retta retta::RettaPerpendicolare( retta& r , punto& p ){
    //m è già il nuovo coefficente angolare
    double m = 0;
    if(r.GetB() != 0 && r.GetA() != 0){
        m = (-1)/(r.GetA()/(-1)*r.GetB());
        return retta(m,-1,(-1)*m*p.getX()+p.getY());
    }else{
        if(r.GetA() == 0){
           return retta(-1,0,p.getX());
        }
        else return retta(0,-1,p.getY());
    }
}

retta retta::RettaParallella( retta& r , punto& p ){
    double m = 0;
    if(r.GetB() != 0 && r.GetA() != 0){
        m = (r.GetA()/(-1)*r.GetB());
        return retta(m,-1,(-1)*m*p.getX()+p.getY());
    }
    else{
        if(r.GetA() == 0){
            return retta(0,-1,p.getY());
        }
        else return retta(-1,0,p.getX());
    }
}

punto retta::Intersect(retta& r1, retta& r2) {
    int Det = r1.GetA()*r2.GetB() - r2.GetA()*r1.GetB();
    if(Det != 0){
        int DetX = r1.GetC()*(-1)*r2.GetB() - r2.GetC()*(-1)*r1.GetB();
        int DetY = r1.GetA()*(-1)*r2.GetC() - r2.GetA()*(-1)*r1.GetC();
        return punto(razionale(DetX,Det),razionale(DetY,Det));
    }
    else
    {
        //trovare la y oppure utilizzare il metodo del confronto
        razionale x = ((((r1.GetC()*r2.GetB())/r1.GetB()) - r2.GetC()),((r2.GetA()-(r1.GetA()*r2.GetB())/r1.GetB())));
        return punto(x,y);
    }
}



