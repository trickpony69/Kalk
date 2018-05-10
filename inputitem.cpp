#include "inputitem.h"

#include "retta.h"
#include "poligono.h"


inputitem::~inputitem() {}

/*
istream& operator>>( istream& is , inputitem* in ){


    in = inputitem::iniz_input();
    //in->isFigura();

    return is;
}*/

inputitem* inputitem::iniz_input () {
    bool ok = true;
    std::string st;

    while(ok == true){

        std::cout<<"dai:"<<std::endl;
        std::getline(cin, st);

        if(dynamic_cast<retta*>(inputitem::pars_start(st))){
            retta ret;
            cout<<"retta ";
            try{ret.pars_rect(st);}
            catch(int){
                //inserito con successo
                ok = false;

                //costruttore di copia di default
                cout<<ret<<std::endl;
                return new retta(ret);
            }
            catch(...){
                ok = true;
                std::cout<<"input errato, reinserisci : "<<std::endl;
            }
        }
        else if(dynamic_cast<punto*>(inputitem::pars_start(st)))
        {
            cout<<"punto ";
            punto point;
            try{point.pars_point(st);}
            catch(input_error){
                std::cerr<<"errore inserimento input punto";
            }
            catch(num_error){
                std::cerr<<"errore numeratore";
            }
            catch(den_error){
                std::cerr<<"errore denominatore";
            }
            catch(int){
                ok = false;
                cout<<point<<std::endl;
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
                std::cerr<<"errore inserimento input poligono"<<std::endl;
                errore = false ;
            }
            catch( irregular_pol ){
                std::cerr<<"Poligono non regolare, reinserisci : "<<std::endl;
                errore = false ;
            }

            if(errore == true){
                cout<<std::endl;
                return p;

            }


        }
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
