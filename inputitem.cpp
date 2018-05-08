#include "inputitem.h"

#include "retta.h"
#include "poligono.h"


inputitem::~inputitem() {}

istream& operator>>( istream& is , inputitem* in ){
    std::string st;
    bool ok = true;

    while(ok == true){
        //input per prendere anche gli spazi
        std::cout<<"daie:";
        std::getline(is, st);

        if(typeid(*(inputitem::pars_start(st))) == typeid(retta)){
            retta ret;
            try{ret.pars_rect(st);}
            catch(int){
                //inserito con successo
                ok = false;
                //costruttore di copia di default
                in = new retta(ret);
            }
            catch(...){
                ok = true;
                std::cout<<"input errato, reinserisci : "<<std::endl;
            }
        }
        else if(typeid(*(inputitem::pars_start(st))) == typeid(punto))
        {
            punto point;
            try{point.pars_point(st);}
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
                in = new punto(point);
            }
        }
        else{
            poligono* pol;
            //devo inizializzare il puntatore a : quadrato , triang , penta
            //assegnazione standard
            try{in = poligono::pars_pol(st);}
            catch(input_error){
                std::cerr<<"errore inserimento input";
            }
        }
    }
    return is;
}

//data una string ritorna se è un punto , retta o poligono
inputitem* inputitem::pars_start(string s){
    unsigned int len = s.length();
    bool trovato = false;
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
        if( cont > 0 ) return 0;
        else return new punto();
    }
    else{
        return new retta();
    }


}
