#include "triangolo.h"

double triangolo::numeroFisso = 0.289 ;

double triangolo::getfisso() const{
    return numeroFisso;
}

/* CALCOLO DISTANZA TRA I PUNTI TRA 1-2 1-3 2-3 */
double triangolo::perimetro() const{
    double per = 0 ;
    per = per + punto::distanceTwoPoints(*pt[0],*pt[1]) + punto::distanceTwoPoints(*pt[0],*pt[2]) + punto::distanceTwoPoints(*pt[1],*pt[2]) ;

    return per;
}

double triangolo::lato() const {
    if( punto::distanceTwoPoints(*pt[0],*pt[1]) == punto::distanceTwoPoints(*pt[0],*pt[2]) == punto::distanceTwoPoints(*pt[1],*pt[2])){
        return punto::distanceTwoPoints(*pt[0],*pt[1]);
    }
    else return 0;
}

double triangolo::area( ) const {
    double base = punto::distanceTwoPoints(*pt[0],*pt[1]) ;

    double h = retta::distancePuntoRetta(*pt[2],retta::rettaFromTwoPoints(*pt[0],*pt[1]));

    return (base*h)/2;
}





