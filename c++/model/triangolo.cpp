#include "triangolo.h"

double triangolo::numeroFisso = 0.289 ;

double triangolo::getfisso() const{
    return numeroFisso;
}

/* CALCOLO DISTANZA TRA I PUNTI TRA 1-2 1-3 2-3 */
double triangolo::perimetro() const{
    double per = 0 ;
    per = per + pt[0]->distanceTwoPoints(*pt[1]) + pt[0]->distanceTwoPoints(*pt[2]) + pt[2]->distanceTwoPoints(*pt[1]) ;

    return per;
}

double triangolo::lato() const {
    if( ( pt[0]->distanceTwoPoints(*pt[1]) == pt[0]->distanceTwoPoints(*pt[2]) ) == pt[2]->distanceTwoPoints(*pt[1])){
        return pt[0]->distanceTwoPoints(*pt[1]);
    }
    else return 0;
}

double triangolo::area( ) const {
    double base = pt[0]->distanceTwoPoints(*pt[1]) ;

    double h = retta::rettaFromTwoPoints(*pt[0],*pt[1]).distancePuntoRetta(*pt[2]);

    return (base*h)/2;
}





