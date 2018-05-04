#include "poligono.h"


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

//------------------    OPERATOR INPUT ----------------

istream& operator>>(istream& is , poligono& p){
    std::string punti;

}




