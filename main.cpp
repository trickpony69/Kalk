#include "retta.h"
// includere un entry point dove partire

int main(){

    punto p1(2,4);
    punto p2(5,6);
    retta r1(2,3,5);
    retta rp = retta::rettaFromTwoPoints(p1,p2); //da un errore strano
    cout<<"p1"<<p1<<"p2"<<p2;
    cout<<"r1 "<<r1;
    cout<<"la distanza tra p1 e r1 è "<<retta::distancePuntoRetta(p1,r1)<<std::endl;//stesso errore di rettaFromTwoPoints
    cout<<"la retta tra p1 e p2 è "<<rp;
    cout<<"la distanza tra p1 e p2 è "<<punto::distanceTwoPoints(p1,p2);
}
