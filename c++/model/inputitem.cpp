#include "inputitem.h"

#include "retta.h"
#include "poligono.h"


inputitem* inputitem::iniz_input (string st) {
    inputitem* input = inputitem::pars_start(st);
    if(dynamic_cast<retta*>(input)){
        retta ret;
        try{ret.pars_rect(st);}
        catch(int){
            input = new retta(ret);
        }
        catch(...){
            throw;
        }
    }
    else if(dynamic_cast<punto*>(input))
    {
        punto point;
        try{point.pars_point(st);}
        catch(input_error){
            throw;
        }
        catch(int){
            input = new punto(point);
        }
    }
    else{
        poligono* p;
        try{ p = poligono::pars_pol(st); }
        catch( input_error ){
            throw;
        }
        catch( irregular_pol ){
            throw;
        }
        catch( num_lati ){
            throw;
        }
        input = p;
    }
    return input;
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


