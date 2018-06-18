#include "retta.h"
#include <iostream>
#include <locale>
#include <sstream>
using std::vector;

razionale retta::GetA() const { return a; }

razionale retta::GetB() const { return b; }

razionale retta::GetC() const { return c; }

double retta::distancePuntoRetta(const punto& p) const{
    return ((abs(a * p.getX() + b * p.getY() + c))/(sqrt(pow(a,2)+pow(b,2))));
}

double retta::distanceRettaRetta(retta& r2) const {
    //trovo il punto con x = 0 di r2:
    if(r2.GetA() == 0){
        punto x (0,(-1)*(r2.GetC()/r2.GetB()));
        return distancePuntoRetta(x);
    }
    else if(r2.GetB() == 0){
        punto x ((r2.GetC()/r2.GetA())*(razionale(-1,1)),0);
        return distancePuntoRetta(x);
    }
    else{
        punto x (0,(-1)*(r2.GetA()/r2.GetB())*(0) - r2.GetC()/r2.GetB());
        return distancePuntoRetta(x);
    }

}

double retta::distance(inputitem * i) const {
    if((i->intersect(const_cast<retta*>(this))).size() == 1) return 0;


    if(typeid(*i) == typeid(retta)){
        return distanceRettaRetta(*(dynamic_cast<retta*>(i)));
    }
    else if( typeid(punto) == typeid(*i) ){
        return distancePuntoRetta(*(dynamic_cast<punto*>(i)));
    }
    else return i->distance(const_cast<retta*>(this));
}

retta retta::rettaFromTwoPoints(const punto& p1,const punto& p2){
    if(p1.getX() == p2.getX() && p1.getY() != p2.getY()){
        return retta(-1,0,p1.getX());
    }
    else if(p1.getX() != p2.getX() && p1.getY() == p2.getY()){
        return retta(0,-1,p1.getY());
    }
    else{
        razionale d1(p2.getX() - p1.getX());
        razionale d2(p2.getY() - p1.getY());
        razionale a = d2;
        razionale b = d1;
        razionale c = (d2*p1.getX()*(razionale(-1,1))) + (d1*p1.getY());
        return retta(a,b*(razionale(-1,1)),c);
    }
}

bool retta::isParallels(retta& r1 ) const{
    razionale coeffA = razionale((razionale(-1,1))*(r1.GetA()/r1.GetB()));
    razionale coeffB = razionale((razionale(-1,1))*(GetA()/GetB()));

    if( (r1.GetA() == 0 && GetB() == 0) || (r1.GetB() == 0 && GetA() == 0) ){
        return false;
    }

    return coeffA == coeffB;
}

bool retta::isPerpendicolari(retta& r1 ) const{
    if((-1)*(r1.GetA()/r1.GetB()) == -1/((-1)*(GetA()/GetB())))
        return true;
    else return false;
}

retta retta::RettaPerpendicolare( punto& p ) const{
    //m è già il nuovo coefficente angolare
    if(GetB() != 0 && GetA() != 0){
        //trovo il coefficente angolare
        razionale m(GetA()*(razionale(-1,1)),GetB());
        //trovo l'antireciproco del coefficente angolare
        razionale new_m = m.inverso()*(razionale(-1,1));
        //trovo c => y1 + m*x1
        razionale c(new_m*p.getX());
        c=(c*(razionale(-1,1)))+p.getY();
        return retta(new_m,-1,c);
    }else{
        if(GetA() == 0){
           return retta(-1,0,p.getX());
        }
        else return retta(0,-1,p.getY());
    }
}

retta retta::RettaParallela(punto& p ) const{
    if(GetB() != 0 && GetA() != 0){
        //trovo il coefficente angolare
        razionale m(GetA()*(razionale(-1,1)),GetB());
        //trovo c => y1 + m*x1
        razionale c(m*p.getX());
        c=(c*(razionale(-1,1)))+p.getY();
        return retta(m,-1,c);
    }
    else{
        if(GetA() == 0){
            return retta(0,-1,p.getY());
        }
        else return retta(-1,0,p.getX());
    }
}

vector<punto> retta::Intersect_rette(const retta& r2) const {
    razionale Det = (GetA()*r2.GetB()) - (r2.GetA()*GetB());
    vector<punto> p;

    if(r2.isParallels(const_cast<retta&>(*this))) return p;

    

    if(Det != 0){
        razionale DetX = razionale( GetC()*(razionale(-1,1))*r2.GetB() + razionale(-1,1)*(r2.GetC()*(razionale(-1,1))*GetB()) , Det);
        razionale DetY = razionale(GetA()*(razionale(-1,1))*r2.GetC() + razionale(-1,1)*(r2.GetA()*(razionale(-1,1))*GetC() ) , Det);
        p.push_back(punto(DetX,DetY));
        return p;
    }
    else
    {
        razionale x((((GetC()*r2.GetB())/GetB()) - r2.GetC()),((r2.GetA()-(GetA()*r2.GetB())/GetB())));
        razionale y = razionale((GetA()*x)/(razionale(-1,1)*(GetB())) + GetC()/(razionale(-1,1)*(GetB())));
        p.push_back(punto(x,y));
        return p;
    }
}

//ritorna un vector di razionali: indice dispari = x , indice pari = y
punto retta::printCoord_x(razionale x) const{
    if(GetB() == 0 && GetA() == 0){
        throw not_implicit();
    }
    else if(GetB() == 0){
        razionale x( GetC()*(razionale(-1,1)),GetA());
        return punto(x,razionale(1,1));
    }
    else{
        razionale y(((GetA()*(razionale(-1,1)))*x + GetC()*(razionale(-1,1))),GetB());
        return punto(x,y);
    }
}

//per ora distanza standard tra i punti : 1 cm (modificabile ??)
vector<punto> retta::print_rect(const razionale& r1 ,const razionale& r2){
    vector<punto> pt;
    if(GetB() == 0){
        punto p1(razionale(-1,1)*razionale(GetC(),GetA()),r1);
        punto p2(razionale(-1,1)*razionale(GetC(),GetA()),r2);
        pt.push_back(p1);
        pt.push_back(p2);
    }
    else{
        pt.push_back(printCoord_x(r1));
        pt.push_back(printCoord_x(r2));
    }
    return pt;
}

vector<punto> retta::intersect( inputitem *i ) const {
    vector<punto> punt ;

    if( typeid(*i) == typeid(retta) ){
        retta * r = dynamic_cast<retta*>(i);
        return r->Intersect_rette(*this);

    }else if( typeid(*i) == typeid(punto) ){
        punto * p = dynamic_cast<punto*>(i);
        if(distancePuntoRetta(*p) == 0 ){
            punt.push_back(*p);
        }
        return punt;
    }

    //i = poligono
    return i->intersect(const_cast<retta*>(this));
}

QString retta::toString()const{
    std::string st;

    if(a.GetNum() != 0) st = st + a.tostring() + "x ";
    if(b.GetNum() != 0) st = st + b.tostring() + "y ";
    if(c.GetNum() != 0) st = st + c.tostring();

    QString qstr = QString::fromStdString(st);

    return qstr;
}

//-----------------------OVERLOAD OPERATORI---------------------------------------------------

ostream& operator<<(ostream& buffer, const retta& r){
    buffer<<"(";
    if(r.a != 0)
        buffer<<r.a<<"x";

    if(r.b >= 0) buffer<<"+";
    if(r.b != 0){
        buffer<<r.b<<"y";
    }

    if(r.c >= 0) buffer<<"+";
    if(r.c != 0){
        buffer<<r.c;
    }

    buffer<<" =0 )";
    return buffer;
}


void retta::pars_rect(string rect)
{
    unsigned int len = rect.length();
    bool trovato = false ;
    for (unsigned int var = 0; var < len; ++var) {
        if(rect[var] == ' '){
            rect.erase(rect.begin()+var);
            var--;
            len--;
        }
        if(rect[var] == '=') trovato = true;
    }

    if( !trovato ) rect = rect + '=';

    std::string s;
    retta r;

    // raz = verifica se è una frazione .
    // incx = incy = serve per verificare se trova due volte la
    // la x o la y .
    bool raz = false , incx = false , incy = false , doub = false , segno = false ;

    //n = num , d = den , x = coeff x , y = coeff y , tn = termine noto
    double n=0,d=0,x=0,y=0,tn=0;

    int sign = 1;
    double virgola = 1 , n1;

    for(unsigned int i = 0 ; i < rect.length() ; i++){
        //vado a verificare ci sia solo una x e una y altrimenti non e' nella forma prevista
        if(rect[i] == 'y' && !incy) incy = true ;
        else if(rect[i] == 'y' && incy) throw not_implicit();

        if(rect[i] == 'x' && !incx) incx = true ;
        else if(rect[i] == 'x' && incx) throw not_implicit();

        if(rect[i] != '*' && rect[i] != '=')
        {
            if(rect[i] == '-' || rect[i] == '+'){
                //verifico se il termine noto è a primo o secondo membro

                if(s.length() > 0){
                    n1 = std::stoi( s );
                    tn = n1 / virgola;

                    virgola = 1;
                    doub = false;

                    if((b.GetNum() != 0 || a.GetNum() != 0) && !segno) throw input_error();
                    c = razionale(sign*tn,1);
                    sign = 1;
                    segno = false;
                    s.erase(s.begin(),s.end());
                }
                if(rect[i] == '-' && sign == 1) sign = -1;
                else if(rect[i] == '-' && sign == -1) sign = 1;

                segno = true;


            }
            else if(rect[i] == '/'){

                n1 = std::stoi( s );
                n = n1 / virgola;

                virgola = 1;
                doub = false;

                s.erase(s.begin(),s.end());
                raz = true;
            }
            else {
                //caso in cui ci sia un x o y al denominatore
                if( (rect[i] == 'x' || rect[i] == 'y') && raz == true )
                    throw input_error("x/y non può essere a denominatore");

                if(rect[i] == 'x'){
                    if(s.length() == 0) s='1';

                    n1 = std::stoi( s );
                    x = n1 / virgola;

                    virgola = 1;
                    doub = false;
                    if((b.GetNum() != 0 || c.GetNum() != 0) && !segno) throw input_error();

                    a = razionale(sign*x,1);
                    sign = 1;
                    segno = false;
                    s.erase(s.begin(),s.end());
                }else if(rect[i] == 'y'){
                    if(s.length() == 0) s='1';

                    n1 = std::stoi( s );
                    y = n1 / virgola;

                    virgola = 1;
                    doub = false;

                    if((a.GetNum() != 0 || c.GetNum() != 0) && !segno) throw input_error();
                    b = razionale(sign*y,1);
                    sign = 1;
                    segno = false;
                    s.erase(s.begin(),s.end());
                }
                else{
                    if(raz == true){
                        //vuol dire che sono a denominatore
                        while(rect[i] != 'x' && rect[i] != 'y' && rect[i] != '=' && rect[i] != '+' && rect[i] != '-')
                        {
                            if(doub) virgola *= 10 ;
                            if(rect[i] == '.'){
                                doub = true;
                            }
                            else s = s+rect[i];
                            i++;
                        }

                        n1 = std::stoi( s );
                        d = n1 / virgola;

                        virgola = 1;
                        doub = false;

                        if(rect[i] == 'x'){
                            if((b.GetNum() != 0 || c.GetNum() != 0) && !segno) throw input_error();
                            a = razionale(sign*n,d);
                            segno = false;
                            sign = 1;
                        }else if(rect[i] == 'y'){
                            if((a.GetNum() != 0 || c.GetNum() != 0) && !segno) throw input_error();
                            b = razionale(sign*n,d);
                            sign = 1;
                            segno = false;
                        }else {
                            if((a.GetNum() != 0 || b.GetNum() != 0) && !segno) throw input_error();
                            c = razionale(sign*n,d);
                            sign = 1;
                            segno = false;
                        }

                        //decremento cosi posso ripartire il ciclo dal segno
                        if(rect[i] == '-' || rect[i] == '+') --i;
                        n=0;d=1;
                        s.erase(s.begin(),s.end());
                        raz = false;
                    }
                    else{

                        std::locale loc;
                        //verifico se rect[i] == numero
                        if(rect[i] == '.'){
                            doub = true;
                        }
                        else if(isdigit(rect[i],loc))
                        {
                          if(doub) virgola *= 10 ;
                          s = s+rect[i];
                        }
                        else throw input_error("Carattere non riconosciuto.");
                        //inserito un input errato: carattere non riconosciuto
                    }
                }
            }
        }
        else if(rect[i] == '=' || rect[i+1] == '='){
            //termine noto ==> tn
             if(s.length() > 0){
                 n1 = std::stoi( s );
                 tn = n1 / virgola;

                 virgola = 1;
                 doub = false;

                 if((b.GetNum() != 0 || a.GetNum() != 0) && !segno) throw input_error();

                 c = razionale(sign*tn,1);
                 segno = false;

                 s.erase(s.begin(),s.end());
              }
              sign = 1;
              break;
        }else {
            s.erase(s.begin(),s.end());
            n=0;d=0;
        }
    }
    if(a.GetNum() == 0 && b.GetNum() == 0){
        throw input_error("Mancano le incognite x y .");
    }
    else{
        throw 1;
    }


}



