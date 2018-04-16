#include "retta.h"
#include <string>


razionale retta::GetA() const { return a; }

razionale retta::GetB() const { return b; }

razionale retta::GetC() const { return c; }

double retta::distancePuntoRetta(punto& p, retta& r){
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
        razionale c = (d2*p1.getX()*(-1)) + (d1*p1.getY());
        return retta(a,b*(-1),c);
    }
}

double retta::distanceRettaRetta(retta& r2) {
    //trovo il punto con x = 0 di r2:
    if(r2.GetA() == 0){
        punto x (0,(-1)*(r2.GetC()/r2.GetB()));
        return distancePuntoRetta(x,*this);
    }
    else if(r2.GetB() == 0){
        punto x ((r2.GetC()/r2.GetA())*(-1),0);
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
        razionale m(r.GetA()*(-1),r.GetB());
        //trovo l'antireciproco del coefficente angolare
        razionale new_m = m.inverso()*(-1);
        //trovo c => y1 + m*x1
        razionale c(new_m*p.getX());
        c=(c*(-1))+p.getY();
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
        razionale m(r.GetA()*(-1),r.GetB());
        //trovo c => y1 + m*x1
        razionale c(m*p.getX());
        c=(c*(-1))+p.getY();
        return retta(m,-1,c);
    }
    else{
        if(r.GetA() == 0){
            return retta(0,-1,p.getY());
        }
        else return retta(-1,0,p.getX());
    }
}

punto retta::Intersect(retta& r1, retta& r2) {
    razionale Det = r1.GetA()*r2.GetB() - r2.GetA()*r1.GetB();

    if(Det != 0){
        razionale DetX = r1.GetC()*(-1)*r2.GetB() - r2.GetC()*(-1)*r1.GetB();
        razionale DetY = r1.GetA()*(-1)*r2.GetC() - r2.GetA()*(-1)*r1.GetC();

        return punto(razionale(DetX,Det),razionale(DetY,Det));
    }
    else
    {
        razionale x((((r1.GetC()*r2.GetB())/r1.GetB()) - r2.GetC()),((r2.GetA()-(r1.GetA()*r2.GetB())/r1.GetB())));
        double coordY = (r1.GetA()*x)/((-1)*(r1.GetB())) + r1.GetC()/((-1)*(r1.GetB()));
        razionale y(coordY,1);
        return punto(x,y);
    }
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

    //input per prendere anche gli spazi
    std::getline(is, rect);

    int len = rect.length();

    std::string s;
    bool raz = false;
    int n=0,d=0,a=0,b=0,c=0;

    for(int i=0;i<len;i++){
        if(rect[i] != '+' && rect[i] != '*' && rect[i] != '=' && rect[i] != '*' && rect[i] != ' ')
        {
            //se è un razionale lo creo
            if(rect[i] == '/'){
                n = stoi( s );
                s = ' ';
                raz = true;
            }
            else {
                //fine del coefficente
                if(rect[i] == 'x'){
                    r.a = razionale(a,1);
                    s = ' ';
                }else if(rect[i] == 'y'){
                    r.b = razionale(b,1);
                    s = ' ';
                }
                else{
                    if(raz == true){
                        //vuol dire che sono a denominatore
                        while(rect[i] != 'x' && rect[i] != 'y' && rect[i] != '=' )
                        {
                            s = s+rect[i];
                            i++;
                        }

                        d = stoi( s );

                        if(rect[i] == 'x'){
                            r.a = razionale(n,d);
                            //cout<<n<<" / "<<d<<"x"<<endl;
                        }else if(rect[i] == 'y'){
                            r.b = razionale(n,d);
                            //cout<<n<<" / "<<d<<"y"<<endl;
                        }else {
                            r.c = razionale(n,d);
                            //cout<<n<<" / "<<d<<endl;
                            break;
                        }
                        s = ' ';
                        raz = false;
                    }
                    else{
                        s = s+rect[i];
                    }
                }
            }
        }
        else if(rect[i] == '='){
            r.c = razionale(c,1);
            break;
        }else {
            s = ' ';
            n=0;d=0;
        }
    }
    return is;
}



