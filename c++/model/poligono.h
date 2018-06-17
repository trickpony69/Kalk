#ifndef POLIGONO_H
#define POLIGONO_H

#include "retta.h"
#include "inputitem.h"
#include <vector>

using std::vector;
using std::istream;

class poligono : public inputitem{
    friend ostream& operator<<(ostream&,poligono*);
private:
    unsigned int lati;
    static void distruggi(vector<punto*>);
    static vector<punto*> copia(vector<punto*>); 
    static double distrettapol(retta*,poligono*);
    static double distpuntopol(punto*,poligono*);
    static double distpolipoli(poligono*,poligono*);
protected:
    vector<punto*> pt; 
public:
    virtual ~poligono();
    poligono(int, vector<punto*>);
    poligono() {} 
    poligono(const poligono&);
    unsigned int getlati() const;
    vector<punto*> getpoint() const;
    virtual double area() const;
    virtual double perimetro() const ;
    virtual double lato() const; 
    bool isRegular() const;
    static poligono* pars_pol(string);
    virtual double getfisso() const =0;

    //distanza
    double distance(inputitem*) const; 

    //intersezione
    static vector<punto> puntint(const poligono& ,const poligono&);
    vector<punto> rettapol(retta*,punto*,punto*) const;
    vector<punto> polipoli(poligono*) const;
    bool polipunto(punto*) const;
    vector<punto> intersect(inputitem*) const ;

    //overload operator
    poligono& operator=(const poligono&); 
    bool operator !=(const poligono&);

};

#endif 
