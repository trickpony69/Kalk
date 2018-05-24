#include "retta.h"

#include <iostream>
#include <locale>
#include <sstream>
using std::vector;

razionale retta::GetA() const { return a; }

razionale retta::GetB() const { return b; }

razionale retta::GetC() const { return c; }

double retta::distancePuntoRetta(const punto& p, const retta& r){
    return ((abs(r.a * p.getX() + r.b * p.getY() + r.c))/(sqrt(pow(r.a,2)+pow(r.b,2))));
}

retta retta::rettaFromTwoPoints(punto& p1,punto& p2){
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

double retta::distanceRettaRetta(retta& r2) {
    //trovo il punto con x = 0 di r2:
    if(r2.GetA() == 0){
        punto x (0,(-1)*(r2.GetC()/r2.GetB()));
        return distancePuntoRetta(x,*this);
    }
    else if(r2.GetB() == 0){
        punto x ((r2.GetC()/r2.GetA())*(razionale(-1,1)),0);
        return distancePuntoRetta(x,*this);
    }
    else{
        punto x (0,(-1)*(r2.GetA()/r2.GetB())*(0) - r2.GetC()/r2.GetB());
        return distancePuntoRetta(x,*this);
    }

}

bool retta::isParallels(retta& r1 , retta& r2 ){
    double coeffA = (-1)*(r1.GetA()/r1.GetB());
    double coeffB = (-1)*(r2.GetA()/r2.GetB());
    return coeffA == coeffB;
}

bool retta::isPerpendicolari(retta& r1 , retta& r2){
    if((-1)*(r1.GetA()/r1.GetB()) == -1/((-1)*(r2.GetA()/r2.GetB())))
        return true;
    else return false;
}

retta retta::RettaPerpendicolare( retta& r , punto& p ){
    //m è già il nuovo coefficente angolare
    if(r.GetB() != 0 && r.GetA() != 0){
        //trovo il coefficente angolare
        razionale m(r.GetA()*(razionale(-1,1)),r.GetB());
        //trovo l'antireciproco del coefficente angolare
        razionale new_m = m.inverso()*(razionale(-1,1));
        //trovo c => y1 + m*x1
        razionale c(new_m*p.getX());
        c=(c*(razionale(-1,1)))+p.getY();
        //cout<<c;
        return retta(new_m,-1,c);
    }else{
        if(r.GetA() == 0){
           return retta(-1,0,p.getX());
        }
        else return retta(0,-1,p.getY());
    }
}

retta retta::RettaParallella( retta& r , punto& p ){
    if(r.GetB() != 0 && r.GetA() != 0){
        //trovo il coefficente angolare
        razionale m(r.GetA()*(razionale(-1,1)),r.GetB());
        //trovo c => y1 + m*x1
        razionale c(m*p.getX());
        c=(c*(razionale(-1,1)))+p.getY();
        return retta(m,-1,c);
    }
    else{
        if(r.GetA() == 0){
            return retta(0,-1,p.getY());
        }
        else return retta(-1,0,p.getX());
    }
}

vector<punto> retta::Intersect(const retta& r1,const retta& r2) {
    razionale Det = r1.GetA()*r2.GetB() - r2.GetA()*r1.GetB();
    vector<punto> p;

    if(Det != 0){
        razionale DetX = r1.GetC()*(razionale(-1,1))*r2.GetB() - r2.GetC()*(razionale(-1,1))*r1.GetB();
        razionale DetY = r1.GetA()*(razionale(-1,1))*r2.GetC() - r2.GetA()*(razionale(-1,1))*r1.GetC();
        p.push_back(punto(razionale(DetX,Det),razionale(DetY,Det)));
        return p;
    }
    else
    {
        razionale x((((r1.GetC()*r2.GetB())/r1.GetB()) - r2.GetC()),((r2.GetA()-(r1.GetA()*r2.GetB())/r1.GetB())));
        double coordY = (r1.GetA()*x)/((-1)*(r1.GetB())) + r1.GetC()/((-1)*(r1.GetB()));
        razionale y(coordY,1);
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
        cout<<"ciao";
        retta * r = dynamic_cast<retta*>(i);
        return retta::Intersect(*r,*this);

    }else if( typeid(*i) == typeid(punto) ){
        punto * p = dynamic_cast<punto*>(i);
        if( retta::distancePuntoRetta(*p,*this) == 0 ){
            punt.push_back(*p);
        }
        return punt;
    }

    //i = poligono
    return i->intersect(const_cast<retta*>(this));
}



//-----------------------OVERLOAD OPERATORI---------------------------------------------------

ostream& operator<<(ostream& buffer, const retta& r){
    buffer<<"(";
    if(r.a != 0)
        buffer<<r.a<<"x";

    if(r.b > 0) buffer<<"+";
    if(r.b != 0){
        buffer<<r.b<<"y";
    }

    if(r.c > 0) buffer<<"+";
    if(r.c != 0){
        buffer<<r.c;
    }

    buffer<<" =0 )";
    return buffer;
}



istream& operator>>(istream& is, retta& r){
    std::string rect;
    bool ok = true;
    //input per prendere anche gli spazi
    while(ok == true){
        std::cout<<"dai:"<<std::endl;
        std::getline(is, rect);

        try{r.pars_rect(rect);}
        catch(int){
	//inserito con successo
	    ok = false;
        }
        catch(...){
            ok = true;
        }
	
    }

    return is;
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
    bool raz = false , incx = false , incy = false , doub = false;

    //n = num , d = den , x = coeff x , y = coeff y , tn = termine noto
    double n=0,d=0,x=0,y=0,tn=0;

    int sign = 1;


    for(unsigned int i = 0 ; i < rect.length() ; i++){
        //vado a verificare ci sia solo una x e una y altrimenti non e' nella forma prevista
        if(rect[i] == 'y' && !incy) incy = true ;
        else if(rect[i] == 'y' && incy) throw not_implicit();

        if(rect[i] == 'x' && !incx) incx = true ;
        else if(rect[i] == 'x' && incx) throw not_implicit();

        //cout<<s<<endl;

        if(rect[i] != '*' && rect[i] != '=')
        {
            if(rect[i] == '-' || rect[i] == '+'){
                //verifico se il termine noto è a primo o secondo membro
                if(s.length() > 0){

                    if(doub) tn = std::stod( s );
                    else tn = std::stoi( s );

                    doub = false;

                    c = razionale(sign*tn,1);
                    sign = 1;

                    s.erase(s.begin(),s.end());
                }
                if(rect[i] == '-') sign = -1;
            }
            else if(rect[i] == '/'){

                if(doub) n = std::stod( s );
                else n = std::stoi( s );

                doub = false;

                s.erase(s.begin(),s.end());
                raz = true;
            }
            else {
                //caso in cui ci sia un x o y al denominatore
                if( (rect[i] == 'x' || rect[i] == 'y') && raz == true )
                    throw input_error();

                if(rect[i] == 'x'){
                    if(s.length() == 0) s='1';

                    if(doub) x = std::stod( s );
                    else x = std::stoi( s );

                    doub = false;

                    a = razionale(sign*x,1);
                    sign = 1;
                    s.erase(s.begin(),s.end());
                }else if(rect[i] == 'y'){
                    if(s.length() == 0) s='1';

                    if(doub) y = std::stod( s );
                    else y = std::stoi( s );

                    doub = false;

                    b = razionale(sign*y,1);
                    sign = 1;
                    s.erase(s.begin(),s.end());
                }
                else{
                    if(raz == true){
                        //vuol dire che sono a denominatore
                        while(rect[i] != 'x' && rect[i] != 'y' && rect[i] != '=' && rect[i] != '+' && rect[i] != '-')
                        {
                            if(rect[i] == '.'){
                                doub = true;
                            }
                            s = s+rect[i];
                            i++;
                        }

                        if(doub) d = std::stod( s );
                        else d = std::stoi( s );

                        doub = false;

                        if(rect[i] == 'x'){
                            a = razionale(sign*n,d);
                            sign = 1;
                        }else if(rect[i] == 'y'){
                            b = razionale(sign*n,d);
                            sign = 1;
                        }else {
                            c = razionale(sign*n,d);
                            sign = 1;
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
                            s = s + rect[i];
                            doub = true;
                        }
                        else if(isdigit(rect[i],loc))
                        {
                          s = s+rect[i];
                        }
                        else throw input_error();
                        //inserito un input errato: carattere non riconosciuto
                    }
                }
            }
        }
        else if(rect[i] == '=' || rect[i+1] == '='){
            //termine noto ==> tn
             if(s.length() > 0){
                 if(doub) tn = std::stod( s );
                 else tn = std::stoi( s );

                 doub = false;

                 c = razionale(sign*tn,1);
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
        throw input_error();
    }
    else{
        throw 1;
    }


}



