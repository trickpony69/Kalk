#include "poligono.h"


poligono::poligono(int l , list<punto*> p):lati(l){
    int num = l ;
    list<punto*>::iterator it = p.begin();
    while(num && it != p.end()){
        pt.push_back(*it);
        ++it;
    }
}

razionale poligono::lato() const{
    list<punto*>::const_iterator it = pt.cbegin();
    punto* rif = *it;
    ++it ;
    vector<razionale> dist;
    for(; it != pt.cend(); ++it){
        razionale temp(punto::distanceTwoPoints(**it,*rif));
        dist.push_back(temp);
    }
    vector<razionale>::iterator raz = dist.begin();
    razionale min = *raz;
    ++raz;
    for(; raz != dist.end() ; ++raz ){
        if(*raz < min) min = *raz;
    }
    return min;
}

int poligono::GetLati() const {
    return lati;
}

list<punto*> poligono::GetPoint() const {
    return pt;
}




