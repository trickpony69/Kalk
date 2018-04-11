#ifndef RAZIONALE_H
#define RAZIONALE_H

#include<iostream>

class razionale;

std::ostream& operator<<(std::ostream&, const razionale&);

class razionale {
    friend std::ostream& operator<<(std::ostream&, const razionale&);
private:
    int num, den; //den != 0
    //meglio rappresentazioni non minimali di un razionale
public:
    razionale(int =0, int =1); // agisce anche da convertitore int => Raz
    razionale inverso() const;//gira la frazione
    operator double() const; //cast operatore double
    razionale operator+(const razionale&) const;
    razionale operator*(const razionale&) const;
    razionale& operator++();// incremento prefisso
    razionale operator++(int);// incremento postfisso
    bool operator==(const razionale&) const;
    bool operator==(const double&) const;
    double converti() const;
};

#endif
