#include "razionale.h"

razionale::razionale(int n, int d): num(n), den(d) {
  if(den==0) {num=0; den=1;}
  else{
    riduzione();
    if(num<0 && den <0){
        num=abs(num);
        den=abs(den);
    }
  }
}

int razionale::conteggio(double d){
    int i=0;
    while(d*pow(10,i)-floor(d*pow(10,i)) && i<= 10)
        i++;
    return i;
}

void razionale::riduzione(){
    if(num==den)
            num=den=1;
    else if(num!=0){
        int aux=abs(num)<abs(den)?abs(num):abs(den);
        for(int i=2; i<=aux; i++)
            if(num%i==0 && den%i==0){
                num=num/i;
                den=den/i;
                aux=(num<den)?num:den;
                i--;
            }
    }
    else
        den=1;
}

razionale::razionale(double d): num(d*pow(10,conteggio(d))),den(pow(10,conteggio(d))) {
    riduzione();
    if(num<0 && den <0){
        num=abs(num);
        den=abs(den);
    }
}

razionale razionale::inverso() const {
  return razionale(den,num);
}

razionale::operator double() const {
  return static_cast<double>(num)/
    static_cast<double>(den);
}

razionale razionale::operator+(const razionale& r) const {
  return razionale(num*r.den + den*r.num, den*r.den);
}

razionale razionale::operator*(const double& r) const {
  return razionale(num*r, den);
}

razionale razionale::operator*(const razionale& r) const {
  return razionale(num*r.num, den*r.den);
}

razionale& razionale::operator++() {
  num += den;
  return *this;
}

razionale razionale::operator++(int) {
  razionale x(*this);
  num += den;
  return x;
}

bool razionale::operator==(const razionale& r) const {
  return num*r.den ==r.num*den;
}

bool razionale::operator==(const double& d) const {
  return num/den == d;
}

double razionale::converti()const {
    return (this)->operator double();
}

std::ostream& operator<<(std::ostream& os, const razionale& r) {
  //return os << "Il razionale rappresentato come un double e'" << r.operator double();
    if(r.den == 1) os<<r.num;
    else os<<r.num<<"/"<<r.den;

    return os;
}
