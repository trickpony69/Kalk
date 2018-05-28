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
    for(unsigned int i = 0 ; i < pt.size()-1 ; ++i ){
        for(unsigned int j = i+1 ; j < pt.size() ; ++j ){
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

//-----------------DISTR PROFONDO-------------------

poligono::~poligono(){
    distruggi(pt);
}

void poligono::distruggi(vector<punto*> v) {
    for(unsigned int i = 0 ; i < v.size() ; ++i ){
        delete v[i];//invoco distruttore di punto
    }
}

//---------------COPIA PROFONDA-------------

vector<punto*> poligono::copia(vector<punto*> v) const{
    vector<punto*> n ;
    for( unsigned int i = 0 ; i < v.size() ; ++i ){
        n.push_back(new punto(*v[i]));
    }
    return n;
}


//-------------COSTRUTTORE DI COPIA PROFONDA--------

poligono::poligono(const poligono & p){
    lati = p.lati;
    pt = copia(p.pt);
}


//------------------ OPERATOR ----------------

poligono& poligono::operator = ( const poligono& p ) {
    if(this != &p){
        distruggi(pt);
        pt = copia(p.pt);
    }
    return *this;
}

bool poligono::operator !=(const poligono& p ){
    if(p.lati == lati){
        int cont = 0 ;
        vector<punto*> p1 = p.GetPoint();
        vector<punto*> p2 = GetPoint();
        for(unsigned int i = 0 ; i < p1.size() -1 ; ++ i){
            for(unsigned int j = i + 1 ; j < p2.size() ; ++j ){
                if( *p1[i] == *p2[j] ) cont ++;
            }
        }
        if(cont == lati) return true;
    }
    return false;
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
/*-------------------------------------------------------------------*/

poligono* poligono::pars_pol(string s){

    //potrebbe essere evitato, ma la rende autonoma nel caso di una chiamata esplicita
    unsigned int len = s.length();

    for (unsigned int var = 0; var < len; ++var) {
        if(s[var] == ' '){
            s.erase(s.begin()+var);
            --var;
            len--;
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

    //cout<<pc<<" "<<pa<<" "<<pv;

    if(pc == pa && pc == pv){
        //ok parsiamo i punti
        //cout<<"ok "<<pv<<std::endl;

        for (unsigned int var = 0; var < len; ++var) {
            string single_point;
            for (unsigned int i = var; s[i] != ')' ; ++i) {
                single_point = single_point + s[i] ;
            }

            var = var + single_point.length();
            single_point = single_point + s[var] ;
            //cout<<single_point;

            punto point;
            //parso punto per punto e man mano che li trovo giusti li inserisco nel vector

            try{point.pars_point(single_point);}

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
                //cout<<point;
                temp.push_back(new punto(point));
            }
            --pv;
        }

        if( pc == 3 ){
            triangolo tr(pc,temp);
            //if( tr.isRegular() != razionale(0,0) )
                return new triangolo(tr);
            //else
               // throw irregular_pol();
        }
        else if( pc == 4 )
        {
            quadrato qr(pc,temp);

            if( qr.isRegular() != razionale(0,0) )
                return new quadrato(qr);
            else
                throw irregular_pol();
        }
        else if( pc == 5 ){
            pentagono pent(pc,temp);
            vector<punto*> p = pent.GetPoint();

            for(unsigned int i=0; i<p.size(); i++) cout<<*p[i]<<" - ";

            if( pent.isRegular() != razionale(0,0) )
                return new pentagono(pent);
            else
                throw irregular_pol();
        }
        else {
            throw num_lati();
        }

    }
    else
        throw input_error();
}

/*------------------------------------------------------*/

double poligono::perimetro() const {
    return GetLati()*lato();
}

double poligono::area() const {
    double apotema = GetLati() * getFisso();
    return (perimetro()*apotema)/2;
}

vector<punto> poligono::rettapol(retta * r , punto * p1 = NULL  ,punto * p2 = NULL) const{
    vector<punto> p;

    vector<punto*> vCoord0 = GetPoint();

    for(unsigned int i = 0; i<vCoord0.size() - 1; i++){
        for(unsigned int j = i + 1; j<vCoord0.size(); j++){
           if(punto::distanceTwoPoints(*vCoord0[i],*vCoord0[j]) == lato() || vCoord0.size() == 3){
                retta prova = retta::rettaFromTwoPoints(*vCoord0[i],*vCoord0[j]);
                vector<punto> intr = retta::Intersect(prova,*r);
                //intersezione tra due rette è al massimo un punto
                if(intr.size() > 0){

                    //devo verificare che le x della retta coincidono in qualche range con le x del poligono


                    if( (vCoord0[i]->getX() <= intr[0].getX() && vCoord0[j]->getX() >= intr[0].getX() )
                            || (vCoord0[i]->getX() >= intr[0].getX() && vCoord0[j]->getX() <= intr[0].getX() ) )
                    {
                        if( (vCoord0[i]->getY() <= intr[0].getY() && vCoord0[j]->getY() >= intr[0].getY() )
                                || (vCoord0[i]->getY() >= intr[0].getY() && vCoord0[j]->getY() <= intr[0].getY() ) )
                        {
                            if(p1 && p2){ //invocata in polipoli quindi passo i punti e verifico i "range"
                                if( ( (p1->getX() <= intr[0].getX() && p2->getX() >= intr[0].getX() )
                                        || (p1->getX() >= intr[0].getX() && p2->getX() <= intr[0].getX() ) ) && ( (p1->getY() <= intr[0].getY() && p2->getY() >= intr[0].getY() )
                                        || (p1->getY() >= intr[0].getY() && p2->getY() <= intr[0].getY() ) ) )
                                    {
                                        p.push_back(punto(intr[0]));
                                    }
                            }
                            else {
                                p.push_back(punto(intr[0]));//copio il punto dentro
                            }
                        }
                    }
                }
                intr.erase(intr.begin(),intr.end());
           }
        }
    }

    if( p.size() > 1 ){
        for( unsigned int i = 0 ; i < p.size() - 1 ; ++i ){
            for( unsigned int j = i + 1 ; j < p.size() ; ++j ){
                if( p[i] == p[j] ) p.erase(p.begin()+j);
            }
        }
    }


    return p;
}

vector<punto> poligono::puntint(const poligono & p1,const poligono & p2){
    vector<punto*> punti = p2.GetPoint();//garbage
    vector<punto> inter;
    for(unsigned int i = 0; i < punti.size(); i++){
        if(p1.polipunto(punti[i])){
           inter.push_back(*(p1.polipunto(punti[i])));
        }
    }
    //distruggi(punti)
    vector<punto*> punti2 = p1.GetPoint();
    for(unsigned int i = 0; i < punti2.size(); i++){
        if(p2.polipunto(punti2[i])){
            inter.push_back(*(p2.polipunto(punti2[i])));
        }
    }
    return inter;
}

vector<punto> poligono::polipoli(poligono * pol) const{
    vector<punto> p,puntinterni;

    puntinterni = poligono::puntint(*this,*pol);

    vector<punto*> vCoord0 = GetPoint();

    for(unsigned int i = 0; i<vCoord0.size() - 1; i++){
        for(unsigned int j = i + 1; j<vCoord0.size(); j++){
             if(punto::distanceTwoPoints(*vCoord0[i],*vCoord0[j]) == lato() || vCoord0.size() == 3){
                 retta prova = retta::rettaFromTwoPoints(*vCoord0[i],*vCoord0[j]);
                 vector<punto> single = pol->rettapol(&prova,vCoord0[i],vCoord0[j]);
                 p.vector::insert(p.end(), single.begin(), single.end());
             }
        }
    }

    //vCoord0.distruggi(); distruttore dei punti

    if( puntinterni.size() > 0 ){
        p.vector::insert(p.end(), puntinterni.begin(), puntinterni.end());
    }

    //verifico non ci siano doppioni

    for( unsigned int i = 0 ; i < p.size() - 1 ; ++i ){
        for( unsigned int j = i + 1 ; j < p.size() ; ++j ){
            if( p[i] == p[j] ) p.erase(p.begin()+j);
        }
    }

    return p;
}

punto* poligono::polipunto( punto * p ) const{
    //prima verifico che sia un vertice del poligono
    vector<punto> punt;

    vector<punto*> lat = GetPoint();

    for( unsigned int i = 0 ; i < lat.size() ; ++i ){
       if(*lat[i] == *p){
           return p;
       }
    }

    retta paralx(0,1,-3);
    retta r = retta::RettaParallela(paralx,*p);

    //r è una retta parallela all'asse x passante per p

    vector<punto> inter = rettapol(&r);

    if( inter.size() == 2 ) {
        //ok allora verifico che sia uno a dx e uno a sx del punto
       if((inter[0].getX() <= p->getX() && inter[1].getX() >= p->getX())
               ||(inter[0].getX() >= p->getX() && inter[1].getX() <= p->getX() ) )
       {
           return new punto(*p);
       }
    }

    return 0;
}


vector<punto> poligono::intersect(inputitem* i) const {
    if( typeid(punto) == typeid(*i) ){
        punto * p = dynamic_cast<punto*>(i);
        vector<punto> punt ;
        punto * ptemp = polipunto(p);
        if(ptemp) punt.push_back(*ptemp);
        return punt;
    }
    else{
        if(typeid(retta) == typeid(*i)){
            return rettapol(dynamic_cast<retta*>(i));
        }
        else return polipoli(dynamic_cast<poligono*>(i));
    }
}


// se ritorno un vector di size == 1 è un vertice del poligono









