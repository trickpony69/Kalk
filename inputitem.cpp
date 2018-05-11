#include "inputitem.h"

#include "retta.h"
#include "poligono.h"


inputitem::~inputitem() {}

inputitem* inputitem::iniz_input (string st) {
  /*  bool ok = true;
    std::string st;

    while(ok == true){

        std::cout<<"dai:"<<std::endl;
        std::getline(cin, st);*/

        if(dynamic_cast<retta*>(inputitem::pars_start(st))){
            retta ret;
            cout<<"retta ";
            try{ret.pars_rect(st);}
            catch(int){
                //ok = false;
                cout<<ret<<std::endl;
                return new retta(ret);
            }
            catch(...){
                //ok = true;
                //rilancio l'eccezione al chiamante
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
               // ok = false;
                return new punto(point);
            }
        }
        else{
            //devo inizializzare il puntatore a : quadrato , triang , penta
            //assegnazione standard
            poligono* p;
            bool errore = true;
            try{ p = poligono::pars_pol(st); }
            catch( input_error ){
                throw;
                errore = false ;
            }
            catch( irregular_pol ){
                throw;
                errore = false ;
            }

            if(errore == true){
                return p;
            }


        }
    //}
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
