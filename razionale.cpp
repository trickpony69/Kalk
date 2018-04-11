#include "razionale.h"

razionale::razionale(int n, int d): num(n), den(d) {
  if(den==0) {num=0; den=1;}
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

double razionale::converti()const {
    return (this)->operator double();
}

std::ostream& operator<<(std::ostream& os, const razionale& r) {
  //return os << "Il razionale rappresentato come un double e'" << r.operator double();
    return os<<r.num<<"/"<<r.den;
}
