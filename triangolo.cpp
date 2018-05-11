#include "triangolo.h"

double triangolo::numeroFisso = 0.289 ;

double triangolo::getFisso() const{
    return numeroFisso;
}


/* CALCOLO DISTANZA TRA DUE PUNTI TRA 1-2 1-3 2-3 */
razionale triangolo::perimetro() const{
    double per = 0 ;
    per = per + punto::distanceTwoPoints(*pt[0],*pt[1]) + punto::distanceTwoPoints(*pt[0],*pt[2]) + punto::distanceTwoPoints(*pt[1],*pt[2]) ;

}


