#ifndef RETTA_H
#define RETTA_H


class retta
{
private:
    double a;
    double b;
    double c;
public:
    retta(double x=0 , double y = 0 , double l = 0) : a(x),b(y),c(l) {} ;
    double GetA(){ return a; }
    double GetB(){ return b; }
    double GetC(){ return c; }
    /*ritorna un vector di puntatori a punti che sono le coordinate calcolate*/
    vector<punto*> print(retta);

};

#endif // RETTA_H
