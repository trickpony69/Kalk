#include "razionale.h"

double razionale::GetNum() const {
    return num;
}

double razionale::GetDen() const {
    return den;
}

razionale::razionale(const razionale& r1 , const razionale& r2) : num(r1.num*r2.den) , den(r2.num*r1.den){
    if((den < 0 && num > 0) || (den < 0 && num < 0)){
        den = den*(-1);
        num = num*(-1);
    }
    riduzione();
}

razionale::razionale(double n, double d): num(n), den(d) {
  if(den==0) {num=0; den=1;} //eccezione
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

        double aux=abs(num)<abs(den)?abs(num):abs(den);
        //fmod ritorna il resto della divisione di num/den con i
        //se è ==0 allora è multiplo
        for(int i=2; i<=aux; i++){
            if(!std::fmod(num,i) && !std::fmod(den,i)){
                num=num/i;
                den=den/i;
                aux=abs(num)<abs(den)?abs(num):abs(den);
                --i;
            }
        }
    }
    else
        den=1;
}

razionale::razionale(const double& d): num(d*pow(10,conteggio(d))),den(pow(10,conteggio(d))) {
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

bool razionale::operator==(const int& i) const{
    return num/den==i;
}

double razionale::converti()const {
    return (this)->operator double();
}

razionale razionale::operator -(const razionale& r) const {
    return *this + (razionale(-1,1)*r) ;
}

razionale razionale::operator /(const razionale& r) const {
    return *this * (r.inverso()) ;
}

string razionale::tostring() const {
    string st;
    if(num > 0) st = st + "+";
    if(!std::fmod(num,1)){
        int n = num;
        st = st + std::to_string(n);
    }
    else st = st + std::to_string(num) ;

    if(!std::fmod(den,1)){
        int d = den;
        if(d != 1)
            st = st + '/' + std::to_string(d);
    }
    else st = st + '/' + std::to_string(den) ;

    return st;
}

std::ostream& operator<<(std::ostream& os, const razionale& r) {
  //return os << "Il razionale rappresentato come un double e'" << r.operator double();
    if(r.den == 1) os<<r.num;
    else os<<r.num<<"/"<<r.den;

    return os;
}

istream& operator>>(istream& is,razionale& r){
    is >> r.num >> r.den;
    return is;
}
