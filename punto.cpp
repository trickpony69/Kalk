#include "punto.h"
#include <locale>
#include <sstream>

razionale punto::getX() const {return x;}

razionale punto::getY() const {return y;}

/*QPoint punto::formatToQtPainter(punto p){
    return QPoint(p.x,p.y);
}*/

double punto::distanceTwoPoints(punto p1,punto p2){
    return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
}

ostream& operator<<(ostream& buffer, const punto& p){
    return buffer<<"("<<p.x<<";"<<p.y<<")";
}

istream& operator>>(istream& is, punto& p){
    std::string point;
    bool ok = true;

    while(ok == true){
	    //input per prendere anche gli spazi
	    cout<<"dai:";
	    std::getline(is, point);

	    try{p.pars_point(point);}

	    catch(input_error){
            std::cerr<<"errore inserimento input";
	    }
	    catch(num_error){
            std::cerr<<"errore numeratore";
	    }
	    catch(den_error){
            std::cerr<<"errore denominatore";
	    }
	    catch(int){
	        ok = false;
	    }
    }
    return is;
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

    for(unsigned int cont = 0 ; cont < p.length() ; ++cont){

        if(p[cont] != '('){
            if(p[cont] == '-'){
                sign = -1;
            }
            else if(p[cont] == '/'){
                if(s.length() == 0) throw num_error();

                if(doub) n = std::stod( s );
                else n = std::stoi( s );

                cout<<n;

                doub = false;

                if( n == 0 ){
                    x = razionale(0,1);
                    while( p[cont] != ';' && p[cont] != ')' )
                        cont++;

                }
                s.erase(s.begin(),s.end());
            }
            else if(p[cont] == ';' || p[cont] == ')'){
                if(s.length() == 0){
                    throw input_error();
                }

                if(n != 0){
                    if(doub) d = std::stod( s );
                    else d = std::stoi( s );

                    doub = false;

                    if( d == 0 ) throw den_error();

                }else{
                    if(doub) n = std::stod( s );
                    else n = std::stoi( s );

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
                std::locale loc;
                if(p[cont] == '.'){
                    doub = true;
                    s = s+p[cont];
                }
                else if(isdigit(p[cont],loc))
                {
                  s = s+p[cont];
                }
                else {
                    throw input_error();
                }
            }
        }
    }
    if(p[0] == '(' && p[p.length()-1] == ')') {
        cout<<x<<" "<<y<<endl;
        throw 1;
    }
    else throw input_error();


}

double punto::xToDouble() const{
    return x.GetNum()/x.GetDen();
}

double punto::yToDouble() const{
    return y.GetNum()/y.GetDen();
}

QString punto::toString(){
    x.riduzione();
    y.riduzione();
    return QString(QString::number(x.GetNum())+'/'+QString::number(x.GetDen())+';'+QString::number(y.GetNum())+'/'+QString::number(y.GetDen()));
}

vector<punto> punto::intersect( inputitem* i ) const {
    vector<punto> punt;
    if(typeid(*i) == typeid(punto)){
        punto * p = dynamic_cast<punto*>(i);
        if( punto::distanceTwoPoints(*p,*this) == 0 ) {
            punt.push_back(*p);
        }
        return punt;
    }
    //se sono qua vuol dire che l'oggetto di invocazione ha come TD(punto)
    return i->intersect(const_cast<punto*>(this));
}


