#include "quadrato.h"

double quadrato::numeroFisso = 0.5;


double quadrato::getFisso() const {
    return numeroFisso;
}

double quadrato::area() const {
    return lato()*lato();
}




