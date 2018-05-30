#ifndef POLIGONO_H
#define POLIGONO_H

#include "retta.h"
#include "inputitem.h"
//#include <QPolygonF>
#include <vector>

using std::vector;
using std::istream;

class poligono : public inputitem{
    friend istream& operator>>(istream&,poligono*);
    friend ostream& operator<<(ostream&,poligono*);
private:
    unsigned int lati;
    static void distruggi(vector<punto*>);
    static vector<punto*> copia(vector<punto*>); //(clone)
protected:
    vector<punto*> pt;
public:
    virtual ~poligono();
    poligono(int, vector<punto*>);
    poligono() {}
    poligono(const poligono&);
    unsigned int GetLati() const;
    vector<punto*> GetPoint() const;
    virtual double area() const; //virtuale pura
    virtual double perimetro() const ; //virtuale
    virtual double lato() const; //ritorna la lunghezza del lato
    razionale isRegular() const;
    static poligono* pars_pol(string);
    virtual double getFisso() const =0;

    //intersezione
    static vector<punto> puntint(const poligono& ,const poligono&);
    vector<punto> rettapol(retta*,punto*,punto*) const;
    vector<punto> polipoli(poligono*) const;
    punto* polipunto(punto*) const;
    vector<punto> intersect(inputitem*) const ;

    //overload operator
    poligono& operator=(const poligono&);
    bool operator !=(const poligono&);


    //virtual QPolygonF formatToQtPainter() = 0;//virtuale pura
};

#endif // POLIGONO_H
