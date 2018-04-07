#include "retta.h"
// includere un entry point dove partire

int main(){

    punto p1(2,4);
    punto p2(5,6);
    retta r1(2,3,5);
    //retta rp = rettaFromTwoPoints(p1,p2); //da un errore strano
    cout<<"p1"<<p1<<"p2"<<p2;
    cout<<"r1 "<<r1;
    cout<<"la distanza è "<<distancePuntoRetta(p1,r1);//stesso errore di rettaFromTwoPoints
}
