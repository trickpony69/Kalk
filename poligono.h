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
    int lati;
protected:
    vector<punto*> pt;
public:
    virtual ~poligono(); //è da ridefinire e invocare il distruttore di punto
    poligono(int, vector<punto*>);
    poligono() {}
    poligono(const poligono&);
    int GetLati() const;
    vector<punto*> GetPoint() const;
    virtual double area() const; //virtuale pura
    virtual double perimetro() const ; //virtuale
    virtual double lato() const; //ritorna la lunghezza del lato
    razionale isRegular() const;
    static poligono* pars_pol(string);
    static vector<punto> puntint(const poligono& ,const poligono&);
    virtual double getFisso() const =0;

    //intersezione
    vector<punto> rettapol(retta*,punto* , punto*) const;
    vector<punto> polipoli(poligono*) const;
    punto* polipunto(punto*) const;
    vector<punto> intersect(inputitem*) const ;

    //distruzione,copia profonda
    void distruggi(vector<punto*>);
    poligono& operator=(const poligono&);
    vector<punto*> copia(vector<punto*>) const;
    bool operator !=(const poligono&);


    //virtual QPolygonF formatToQtPainter() = 0;//virtuale pura
};

#endif // POLIGONO_H
