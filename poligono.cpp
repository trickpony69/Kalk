#include "poligono.h"
#include "triangolo.h"
#include "quadrato.h"
#include "pentagono.h"


poligono::poligono(int l , vector<punto*> p):lati(l){
    int num = l ;
    vector<punto*>::iterator it = p.begin();
    while(num && it != p.end()){
        pt.push_back(*it);
        ++it;
    }
}


int poligono::GetLati() const {
    return lati;
}

vector<punto*> poligono::GetPoint() const {
    return pt;
}

//massimo tre controlli : visto che utilizziamo poligoni regolari fino a 5 lati quindi prendendo tre segmenti posso
//capire qual'e' il lato del poligono
double poligono::lato() const{

    double lat = punto::distanceTwoPoints(*pt[1],*pt[0]);

    for(int i = 2 ; i < 4 ; i ++ ){
       double p = punto::distanceTwoPoints(*pt[i],*pt[0]);
       if(p < lat) lat = p ;
    }

    return lat;
}

//se è regolare ritorna la misura del lato altrimenti ritorna 0
razionale poligono::isRegular() const {

    double conf = lato();
    int check = 0 ;
    for(unsigned int i = 0 ; i < pt.size() ; ++i ){
        for(unsigned int j = 0 ; j < pt.size() ; ++j ){
            if(punto::distanceTwoPoints(*pt[i],*pt[j]) == conf) {
                check++;
            }
        }
    }

    if(check == GetLati()){
        return razionale(conf);
    }
    else return razionale(0,0);
}

//------------------ OPERATOR >> - << ----------------

istream& operator>>(istream& is , poligono* p){
    std::string punti;

}

ostream& operator<<(ostream& os , poligono* q){
    vector<punto*> p = q->GetPoint();
    vector<punto*>::const_iterator it = p.cbegin();
    for(;it != p.cend() ; ++it){
        os<<**it<<" ";
    }
    return os;
}

//parser poligono
poligono* poligono::pars_pol(string s){

    unsigned int len = s.length();

    for (unsigned int var = 0; var < len; ++var) {
        if(s[var] == ' '){
            s.erase(s.begin()+var);
            var--;
        }
    }
    //tolto gli spazi

    /*  1 trovo i punti
     *  2 verifico se è regolare
     *  3 se è regolare lo ritorno altrimenti eccez
    */

    int pc = 0 , pa = 0 , pv = 0 ;

    for (unsigned int var = 0; var < len; ++var) {
        if(s[var] == ')') pc ++;
        if(s[var] == '(') pa ++;
        if(s[var] == ';') pv ++;
    }

    vector<punto*> temp;

    if(pc == pa && pc/2 == pv){
        //ok parsiamo i punti

        while(pv > 0){
            punto point;
            //parso punto per punto e man mano che li trovo giusti li inserisco nel vector

            try{point.pars_point(s);}

            catch(input_error){
                //rimando l'eccezione al chiamante
                throw input_error();
            }
            catch(num_error){
                throw input_error();
            }
            catch(den_error){
                throw input_error();
            }
            catch(int){
                //invoco il costruttore di copia standard
                temp.push_back(new punto(point));
            }
            --pv;
        }

        if( pc/2 == 3 ){
            triangolo tr(pc/2,temp);
            if( tr.isRegular() != razionale(0,0) )
                return &tr;
            else
                throw input_error();
        }
        else if( pc/2 == 4 )
        {
            quadrato qr(pc/2,temp);
            if( qr.isRegular() != razionale(0,0) )
                return &qr;
            else
                throw input_error();
        }
        else if( pc/2 == 5 ){
            pentagono pt(pc/2,temp);
            if( pt.isRegular() != razionale(0,0) )
                return &pt;
            else
                throw input_error();
        }

    }
    else
        throw input_error();
}




