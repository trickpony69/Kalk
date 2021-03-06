#include "punto.h"



razionale punto::getX() const {return x;}

razionale punto::getY() const {return y;}

bool punto::operator ==(const punto& p){
    if((p.getX() == getX()) && (p.getY()) == getY()){
        return true;
    }
    else return false;
}

double punto::distanceTwoPoints(const punto& p1) const{
    return sqrt(pow((x-p1.x),2)+pow((y-p1.y),2));
}

double punto::distance(inputitem * i) const {
    if(typeid(*i) == typeid(retta)){
        return i->distance(const_cast<punto*>(this));
    }
    else if( typeid(punto) == typeid(*i) ){
        return distanceTwoPoints(*(dynamic_cast<punto*>(i)));
    }
    else return i->distance(const_cast<punto*>(this));
}

ostream& operator<<(ostream& buffer, const punto& p){
    return buffer<<"("<<p.x<<";"<<p.y<<")";
}


void punto::pars_point(string p){
    //rimuove gli spazi
    unsigned int len = p.length();
    for (unsigned int var = 0; var < len; ++var) {
        if(p[var] == ' '){
            p.erase(p.begin()+var);
            var--;
            len--;
        }
    }
    string s;
    double n=0,d=1;
    int sign=1;

    //verifico se è un double
    bool doub = false;
    double virgola = 1 , n1;
    //virgola vale : 10 se ho un numero dopo la virgola  ,100 se ho due punti dopo la virgola , 1000 se ho tre punti dopo la virgola

    for(unsigned int cont = 0 ; cont < p.length() ; ++cont){


        if(p[cont] != '('){
            if(p[cont] == '-' || p[cont] == '+'){
                if(p[cont] == '-' && sign == -1 )
                    sign = 1;
                else if(p[cont] == '-')
                    sign = -1;

            }
            else if(p[cont] == '/'){
                if(s.length() == 0) throw input_error("Manca il numeratore.");

                if(doub) {
                    n1 = std::stoi( s );
                    n = n1 / virgola;
                }
                else n = std::stoi( s );

                doub = false;
                virgola = 1;


                if( n == 0 ){
                    while( p[cont] != ';' && p[cont] != ')' )
                        cont++;
                    if(p[cont] == ';')
                        x = razionale(0,1);
                    else
                        y = razionale(0,1);
                }
                s.erase(s.begin(),s.end());
            }
            else if(p[cont] == ';' || p[cont] == ')'){
                if(s.length() == 0){
                    throw input_error("Errore: manca un input.");
                }

                if(n != 0){


                    if(doub){
                        n1 = std::stoi( s );
                        d = n1 / virgola;
                    }
                    else d = std::stoi( s );


                    doub = false;
                    virgola = 1;

                    if( d == 0 ) throw input_error("Errore al denominatore.");

                }else{

                    if(doub) {
                        n1 = std::stoi( s );
                        n = n1 / virgola;
                    }
                    else n = std::stoi( s );


                    virgola = 1 ;
                    doub = false;

                    d = 1;
                }
                if(p[cont] == ';'){
                    x = razionale(n*sign,d);
                }
                else{
                    y = razionale(n*sign,d);
                    //è finito il punto perchè sono ')'
                    break;
                }

                d=1;n=0;
                s.erase(s.begin(),s.end());
                sign = 1;
            }
            else{
                //p[cont] e' un valore numerico
                std::locale loc;
                if(p[cont] == '.'){
                    doub = true;
                }
                else if(isdigit(p[cont],loc))
                {
                  if(doub) virgola *= 10 ;
                  s = s+p[cont];
                }
                else {
                    throw input_error("Errore: valore non numerico.");
                }
            }
        }
    }
    if(p[0] == '(' && p[p.length()-1] == ')') {
        throw 1;
    }
    else throw input_error("Errore: mancano le parentesi.");
}

double punto::xToDouble() const{
    return x.converti();
}

double punto::yToDouble() const{
    return y.converti();
}

//serve per la gui
string punto::toString(){


    std::string st ;

    st = st + x.tostring() + ";" + y.tostring();

    return st;
}

vector<punto> punto::intersect( inputitem* i ) const {
    vector<punto> punt;
    if(typeid(*i) == typeid(punto)){
        punto * p = dynamic_cast<punto*>(i);
        if( distanceTwoPoints(*p) == 0 ) {
            punt.push_back(*p);
        }
        return punt;
    }
    //rilancio la chiamata cambiando l'oggetto di invocazione
    return i->intersect(const_cast<punto*>(this));
}


