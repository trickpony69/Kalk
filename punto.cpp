#include "punto.h"
#include <locale>
#include <sstream>

razionale punto::getX() const {return x;}

razionale punto::getY() const {return y;}

QPoint punto::formatToQtPainter(punto p){
    return QPoint(p.x,p.y);
}

double punto::distanceTwoPoints(punto p1,punto p2){
    return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
}

ostream& operator<<(ostream& buffer, const punto& p){
    return buffer<<"("<<p.x<<";"<<p.y<<")";
}

istream& operator>>(istream& is, punto& p){
    std::string point;

    //input per prendere anche gli spazi
    std::getline(is, point);

    p.pars_point(point);

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
                if(s.length() == 0) cout<<'eccezione numeratore inesistente'<<std::endl;
                std::istringstream(s) >> n;
                s.erase(s.begin(),s.end());
            }
            else if(p[cont] == ';' || p[cont] == ')'){
                if(s.length() == 0){
                    std::cout<<"eccezione"<<std::endl;
                    break;
                }

                if(n!=0){
                    if(s.length() == 0) cout<<'eccezione denominatore inesistente'<<std::endl;
                    std::istringstream(s) >> d;
                }else{
                    if(s.length() == 0) cout<<'eccezione denominatore inesistente'<<std::endl;
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
                    cout<<"eccezione simbolo sbagliato"<<std::endl;
                    break;
                }
            }
        }
    }


}
