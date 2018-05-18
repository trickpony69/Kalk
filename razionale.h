#ifndef RAZIONALE_H
#define RAZIONALE_H

#include<iostream>
using std::istream;
#include <cmath>

using std::abs;

class razionale;

std::ostream& operator<<(std::ostream&, const razionale&);

class razionale {
    friend istream& operator>>(istream&,razionale&);
    friend std::ostream& operator<<(std::ostream&, const razionale&);
private:
    double num, den; //den != 0
    //meglio rappresentazioni non minimali di un razionale
public:
    razionale() {}
    razionale(double , double );// agisce anche da convertitore int => Raz
    double GetNum() const;
    double GetDen() const;
    razionale(const double&);
    razionale(const razionale&,const razionale&);
    void riduzione();
    int conteggio(double);
    razionale inverso() const;//gira la frazione
    operator double() const; //cast operatore double
    razionale operator+(const razionale&) const;
    razionale operator*(const razionale&) const;
    razionale operator*(const double&) const;
    razionale& operator++();// incremento prefisso
    razionale operator++(int);// incremento postfisso
    bool operator==(const razionale&) const;
    bool operator==(const double&) const;
    bool operator==(const int&) const;
    double converti() const;
};

#endif
