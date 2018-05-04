#include "inputitem.h"

#include "retta.h"
#include "poligono.h"


inputitem::~inputitem() {}

istream& operator>>( istream& is , inputitem& in ){
    std::string st;
    bool ok = true;

    while(ok == true){
        //input per prendere anche gli spazi
        std::cout<<"dai:";
        std::getline(is, st);

        //ritorna un tipo retta/punto

        if(typeid(inputitem::pars_start(st)) == typeid(retta)){
            retta ret;
            cin>>ret;
        }
        else if(typeid(inputitem::pars_start(st)) == typeid(punto))
        {
            punto point;
            cin>>point;
        }
        else{
            /*poligono pol;
            cin>>pol;*/
        }
    }
    return is;
}

//data una string ritorna se è un punto , retta o poligono
inputitem* inputitem::pars_start(string s){

}
