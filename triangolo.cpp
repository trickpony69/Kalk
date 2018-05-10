#include "triangolo.h"

razionale triangolo::area() const{
    return 0;
}


/* CALCOLO DISTANZA TRA DUE PUNTI TRA 1-2 1-3 2-3 */
razionale triangolo::perimetro() const{

    double per = 0 ;
    per = per + punto::distanceTwoPoints(*pt[0],*pt[1]) + punto::distanceTwoPoints(*pt[0],*pt[2]) + punto::distanceTwoPoints(*pt[1],*pt[2]) ;
    return per;

}


