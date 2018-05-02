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
        }
    }
    string s;
    int n=0,d=1,sign=1;

    for(unsigned int cont = 0 ; cont < p.length() ; ++cont){
      
        if(p[cont] != '('){
            if(p[cont] == '-'){
                sign = -1;
            }
            else if(p[cont] == '/'){
                if(s.length() == 0) throw num_error();
                std::istringstream(s) >> n;
                s.erase(s.begin(),s.end());
            }
            else if(p[cont] == ';' || p[cont] == ')'){
                if(s.length() == 0){
                    throw num_error();
                    break;
                }

                if(n!=0){
                    if(s.length() == 0) throw den_error();
                    std::istringstream(s) >> d;
                }else{
                    if(s.length() == 0) throw den_error();
                    std::istringstream(s) >> n;
                }
                if(p[cont] == ';'){
                    x = razionale(n*sign,d);
                }
                else{
                    y = razionale(n*sign,d);
                }
                d=1;n=0;

                s.erase(s.begin(),s.end());
                sign = 1;
            }
            else{
                std::locale loc;
                if (isdigit(p[cont],loc))
                {
                  s = s+p[cont];
                }
                else {
		    std::cout<<p[cont];
                    throw input_error();
                }
            }
        }
    }
    if(p[0] == '(' && p[p.length()-1] == ')') throw 1;


}

double punto::xToDouble() const{
    return x.GetNum()/x.GetDen();
}

double punto::yToDouble() const{
    return y.GetNum()/y.GetDen();
}
