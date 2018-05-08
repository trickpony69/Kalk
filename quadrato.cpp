#include "quadrato.h"

//OVERLOADING INPUT-OUTPUT ***************************

istream& operator>>(istream& is,quadrato& q){
    std::string point;
    int l;
    bool esci = false;
    while(!esci){
        std::cout<<"lati: ";
        std::cin>>l;
        if(l>2) esci = true;
    }
    int ok = l;
    //input per prendere anche gli spazi
    vector<punto*> iniz;
    while(ok>0){
        std::cout<<"punto:"<<std::endl;
        std::getline(is, point);
        punto p = punto();
        try{p.pars_point(point);}
        catch(int){
            //inserito con successo
            --ok;
            punto* punt = new punto(p);
            iniz.push_back(punt);
        }
        catch(...){
            std::cerr<<"errato"<<std::endl;
        }

    }
    q = quadrato(l,iniz);
    return is;
}



//----------------------------------------------------
razionale quadrato::area() const{
    return 0;
}

razionale quadrato::perimetro() const{
    return 0;
}

