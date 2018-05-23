#include "inputitem.h"

#include "retta.h"
#include "poligono.h"


inputitem::~inputitem() {}

inputitem* inputitem::iniz_input (string st) {

    if(dynamic_cast<retta*>(inputitem::pars_start(st))){
        retta ret;
        try{ret.pars_rect(st);}
        catch(int){
            return new retta(ret);
        }
        catch(...){
            throw;
        }
    }
    else if(dynamic_cast<punto*>(inputitem::pars_start(st)))
    {
        punto point;
        try{point.pars_point(st);}
        catch(input_error){
            throw;
        }
        catch(num_error){
            throw;
        }
        catch(den_error){
            throw;
        }
        catch(int){
            return new punto(point);
        }
    }
    else{
        poligono* p;
        bool errore = true;
        try{ p = poligono::pars_pol(st); }
        catch( input_error ){
            throw;
        }
        catch( irregular_pol ){
            throw;
        }
        return p;
    }
}



//data una string ritorna se è un punto , retta o poligono
//ha senso creare un oggetto e ritornarlo  esfruttare il polimorfisomo? altrimenti stringa
inputitem* inputitem::pars_start(string s){
    unsigned int len = s.length();

    for (unsigned int var = 0; var < len; ++var) {
        if(s[var] == ' '){
            s.erase(s.begin()+var);
            var--;
        }
    }
    //tolto gli spazi

    if(s[0] == '('){
        int cont = 0;
        for (unsigned int i = 0; i < len; ++i) {
            if(s[i] == '('){
                cont++;
            }
        }
        if( cont > 1 ) return 0;
        else return new punto();
    }
    else{
        return new retta();
    }
}

vector<punto> inputitem::intersect(inputitem * i1 , inputitem * i2 ){
    vector<punto> p ;

    if(dynamic_cast<punto*>(i1) || dynamic_cast<punto*>(i2)){
        //c'è almeno un punto
        if(dynamic_cast<retta*>(i1) || dynamic_cast<retta*>(i2)){
            retta * r1 = dynamic_cast<retta*>(i1);
            punto * p1 = dynamic_cast<punto*>(i2);

            if( !r1 ){
                retta * r1 = dynamic_cast<retta*>(i2);
                punto * p1 = dynamic_cast<punto*>(i1);
                double dist = retta::distancePuntoRetta(*p1,*r1);
                if( dist == 0 ) {
                    p.push_back(*p1);
                }
            }else{
                double dist = retta::distancePuntoRetta(*p1,*r1);
                if( dist == 0 ) {
                    p.push_back(*p1);
                }
            }
            return p;
        }
        else if(dynamic_cast<poligono*>(i1) || dynamic_cast<poligono*>(i2)){
            //intersezione poligono punto

        }
        else {
            //sono due punti
            punto * p1 = dynamic_cast<punto*>(i1);
            punto * p2 = dynamic_cast<punto*>(i2);

            if(punto::distanceTwoPoints(*p1,*p2) == 0){
                p.push_back(*p1);
            }
            return p;
        }
    }
    else {
        //non ci sono punti
        if(dynamic_cast<retta*>(i1) || dynamic_cast<retta*>(i2)){
            if(dynamic_cast<poligono*>(i1) || (dynamic_cast<poligono*>(i2))){
                retta * r1 = dynamic_cast<retta*>(i1);
                poligono * pol1 = dynamic_cast<poligono*>(i2);
                if( !r1 ){
                    retta * r1 = dynamic_cast<retta*>(i2);
                    poligono * pol1 = dynamic_cast<poligono*>(i1);
                    return pol1->rettapol(r1);
                }

                return pol1->rettapol(r1);
            }
            else{
                //invoco retta retta
                retta * r1 = dynamic_cast<retta*>(i1);
                retta * r2 = dynamic_cast<retta*>(i2);
                return retta::Intersect(*r1,*r2);
            }
        }
        else {
            poligono * pol1 = dynamic_cast<poligono*>(i1);
            poligono * pol2 = dynamic_cast<poligono*>(i2);
            return pol1->polipoli(pol2);
        }
    }

}
