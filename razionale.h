#ifndef RAZIONALE_H
#define RAZIONALE_H

#include<iostream>
#include <cmath>
using std::istream;
using std::string;


using std::abs;

class razionale;

std::ostream& operator<<(std::ostream&, const razionale&);

class razionale {
    friend istream& operator>>(istream&,razionale&);
    friend std::ostream& operator<<(std::ostream&, const razionale&);
private:
    double num, den; //den != 0
public:
    razionale() { num = 0 ; den = 1; }

    double GetNum() const;
    double GetDen() const;
    razionale(const double&);
    razionale(const razionale&,const razionale&);
    void riduzione();
    int conteggio(double);
    razionale inverso() const;//gira la frazione
    razionale(double , double );// agisce anche da convertitore int => Raz
    razionale operator+(const razionale&) const;
    razionale operator*(const razionale&) const;
    razionale operator*(const double&) const;
    razionale& operator++();// incremento prefisso
    razionale operator++(int);// incremento postfisso
    bool operator==(const razionale&) const;
    bool operator==(const double&) const;
    bool operator==(const int&) const;
    double converti() const;
    razionale operator-(const razionale&) const;
    razionale operator/(const razionale&) const;
    string tostring() const;
    operator double() const; //cast operatore double
};

#endif
