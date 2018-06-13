#include "poligono.h"
#include "triangolo.h"
#include "quadrato.h"
#include <algorithm>
#include <iomanip> //arrotonda


poligono::poligono(int l , vector<punto*> p):lati(l){
    int num = l ;
    vector<punto*>::iterator it = p.begin();
    while(num && it != p.end()){
        pt.push_back(*it);
        ++it;
        num--;
    }
}


unsigned int poligono::getlati() const {
    return lati;
}

vector<punto*> poligono::getpoint() const {
    return copia(pt); //ritorno la copia dei puntatori a punto
}

//massimo tre controlli : visto che utilizziamo poligoni regolari fino a 5 lati quindi prendendo tre segmenti posso
//capire qual'e' il lato del poligono
double poligono::lato() const{

    double lat = punto::distanceTwoPoints(*pt[1],*pt[0]);

    //il lato e' la distanza minima tra i punti inseriti
    for(int i = 2 ; i < 4 ; i ++ ){
       double p = punto::distanceTwoPoints(*pt[i],*pt[0]);
       if(p < lat) lat = p ;

    }

    return lat;
}

//se è regolare ritorna la misura del lato altrimenti ritorna 0
bool poligono::isRegular() const {

    for(unsigned int i = 0 ; i < pt.size()-1 ; ++i ){
        for(unsigned int j = i+1 ; j < pt.size() ; ++j ){
            if(*pt[i] == *pt[j]) return false;
        }
    }

    if(getlati() == 3){
        retta r = retta::rettaFromTwoPoints(*pt[0],*pt[1]);

        if((r.intersect(pt[2])).size() >= 1){
            return false;
        }
        return true;
    }
    else{
        double conf = lato();

        unsigned int check = 0 ;
        for(unsigned int i = 0 ; i < pt.size()-1 ; ++i ){
            for(unsigned int j = i+1 ; j < pt.size() ; ++j ){
                if(punto::distanceTwoPoints(*pt[i],*pt[j]) == conf) {
                    check++; //verifico di avere  n lati uguali al lato()
                }
            }
        }

        if(check == getlati()){
            return true;
        }
        else return false;
    }


}

//-----------------DISTR PROFONDO-------------------

poligono::~poligono(){
    distruggi(pt);
}

void poligono::distruggi(vector<punto*> v) {
    vector<punto*>::iterator it = v.begin();
    for( ; it != v.end() ; ++it ){
        //cout<<"esiste  "<<**it<<endl;
        delete *it;
        /*if(*it) cout<<"esiste  "<<**it<<endl<<endl;
        else cout<<"non esiste";*/
        v.erase(it);
        --it;
    }

    if(v.size() == 0) cout<<"distrutto";
}

//---------------COPIA PROFONDA-------------

vector<punto*> poligono::copia(vector<punto*> v){
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

poligono& poligono::operator=( const poligono& p ) {
    if(this != &p){

        distruggi(pt);
        pt = copia(p.pt);
    }
    return *this;
}

bool poligono::operator !=(const poligono& p ){
    if(p.lati == lati){
        unsigned int cont = 0 ;
        vector<punto*> p1 = p.getpoint();
        vector<punto*> p2 = getpoint();
        for(unsigned int i = 0 ; i < p1.size() -1 ; ++ i){
            for(unsigned int j = i + 1 ; j < p2.size() ; ++j ){
                if( *p1[i] == *p2[j] ) cont ++;
            }
        }
        if(cont == lati) return true;

        distruggi(p1);// p1 e p2 sono copie e non i veri punti
        distruggi(p2);
    }
    return false;
}

ostream& operator<<(ostream& os , poligono* q){
    vector<punto*> p = q->pt;
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

    if(pc == pa && pc == pv){
        //ok parsiamo i punti

        for (unsigned int var = 0; var < len; ++var) {
            string single_point;
            for (unsigned int i = var; s[i] != ')' ; ++i) {
                single_point = single_point + s[i] ;
            }

            var = var + single_point.length();
            single_point = single_point + s[var] ;

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
                temp.push_back(new punto(point));
            }

        }

        if( pc == 3 ){
            triangolo tr(pc,temp);
            if( tr.isRegular()  )
                return new triangolo(tr);
            else
                throw irregular_pol();
        }
        else if( pc == 4 )
        {
            quadrato qr(pc,temp);

            if( qr.isRegular()  )
                return new quadrato(qr);
            else
                throw irregular_pol();
        }
        else {
            /* se avanza tempo creare classe poligono irregolare che disegna i punti*/
            throw num_lati();
        }

    }
    else
        throw input_error();
}

/*------------------------------------------------------*/

double poligono::perimetro() const {
    return getlati()*lato();
}

double poligono::area() const {
    double apotema = getlati() * getfisso();
    return (perimetro()*apotema)/2;
}

vector<punto> poligono::rettapol(retta * r , punto * p1 = nullptr  ,punto * p2 = nullptr) const{
    vector<punto> p;

    /*double d = 1;
    int digits = 3;
    std::cout << "d (rounded to " << digits << " digits) = "<< std::setprecision(digits) << d <<endl;*/

    vector<punto*> vCoord0 = getpoint();

    for(unsigned int i = 0; i<vCoord0.size() - 1; i++){
        for(unsigned int j = i + 1; j<vCoord0.size(); j++){
           if(punto::distanceTwoPoints(*vCoord0[i],*vCoord0[j]) == lato() || vCoord0.size() == 3){
                retta prova = retta::rettaFromTwoPoints(*vCoord0[i],*vCoord0[j]);
                vector<punto> intr = retta::Intersect(prova,*r);

                //intersezione tra due rette è al massimo un punto
                if(intr.size() > 0){

                    //devo verificare che le x della retta coincidono in qualche range con le x del poligono
                    if( (vCoord0[i]->getX() <= intr[0].getX() && vCoord0[j]->getX() >= intr[0].getX() )
                            || (vCoord0[i]->getX() >= intr[0].getX() && vCoord0[j]->getX() <= intr[0].getX() ) || (vCoord0[i]->getX() == vCoord0[j]->getX() ) ) //se ho la stessa x non la verifico
                    {
                        if( (vCoord0[i]->getY() <= intr[0].getY() && vCoord0[j]->getY() >= intr[0].getY() )
                                || (vCoord0[i]->getY() >= intr[0].getY() && vCoord0[j]->getY() <= intr[0].getY() ) || (vCoord0[i]->getY() == vCoord0[j]->getY() ) )
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

    distruggi(vCoord0);

    if( p.size() > 1 ){
        for( unsigned int i = 0 ; i < p.size() - 1 ; ++i ){
            for( unsigned int j = i + 1 ; j < p.size() ; ++j ){
                if( p[i] == p[j] ){
                    p.erase(p.begin()+j);
                    --j;
                }

            }
        }
    }


    return p;
}

vector<punto> poligono::puntint(const poligono & p1,const poligono & p2){
    vector<punto*> punti = p2.getpoint();
    vector<punto> inter;
    for(unsigned int i = 0; i < punti.size(); i++){
        if(p1.polipunto(punti[i])){
            if(p1.polipunto(punti[i])) inter.push_back(*(punti[i]));
        }
    }

    //se il ho n elementi nel vector e il poligono ha n vertici allora è interno e non vado a fare un ulteriore controllo
    if(inter.size() != p2.getlati()){
        vector<punto*> punti2 = p1.getpoint();
        for(unsigned int i = 0; i < punti2.size(); i++){
            if(p2.polipunto(punti2[i])) inter.push_back(*(punti2[i]));
        }
        distruggi(punti2);
    }

    distruggi(punti);


    return inter;
}

vector<punto> poligono::polipoli(poligono * pol) const{
    vector<punto> p,puntinterni;

    puntinterni = poligono::puntint(*this,*pol);

    if( puntinterni.size() > 0 ){
        p.vector::insert(p.end(), puntinterni.begin(), puntinterni.end());
    }

    vector<punto*> vCoord0 = getpoint();

    for(unsigned int i = 0; i<vCoord0.size() - 1; i++){
        for(unsigned int j = i + 1; j<vCoord0.size(); j++){
             if(punto::distanceTwoPoints(*vCoord0[i],*vCoord0[j]) == lato() || vCoord0.size() == 3){
                 retta prova = retta::rettaFromTwoPoints(*vCoord0[i],*vCoord0[j]);
                 vector<punto> single = pol->rettapol(&prova,vCoord0[i],vCoord0[j]);
                 p.vector::insert(p.end(), single.begin(), single.end());
             }
        }
    }

    distruggi(vCoord0); //distruttore dei punti

    //verifico non ci siano doppioni
    if(p.size() > 0){
        for( unsigned int i = 0 ; i < p.size(); ++i ){
            for( unsigned int j = i + 1 ; j < p.size() ; ++j ){
                if( p[i] == p[j] ) {
                    p.erase(p.begin()+j);
                    --j;
                }
            }
        }
    }


    return p;
}

/*metodo verifica :
1) verifico sia un vertice del poligono
2) creo una retta parallela all'asse x passante per p , se la
   retta interseca per due volte il poligono , e i punti di
   intersezione p1 e p2 hanno rispettivamente :
   (x1 <= x <= x2 || x2 <= x <= x1 ) allora è interno .
*/
bool poligono::polipunto( punto * p ) const{
    //prima verifico che sia un vertice del poligono
    vector<punto> punt;

    vector<punto*> lat = getpoint();

    for( unsigned int i = 0 ; i < lat.size() ; ++i ){
       if(*lat[i] == *p){ //punto == vertice poligono
           distruggi(lat);
           return p;
       }
    }

    retta paralx(0,1,-3);
    retta r = retta::RettaParallela(paralx,*p);
    //r è una retta parallela all'asse x passante per p

    vector<punto> inter = rettapol(&r);

    distruggi(lat);

    if( inter.size() >= 2 ) {
        //ok allora verifico che sia uno a dx e uno a sx del punto
       if((inter[0].getX() <= p->getX() && inter[1].getX() >= p->getX())
               ||(inter[0].getX() >= p->getX() && inter[1].getX() <= p->getX() ) )
       {
           return true;
       }
    }
    return false;
}


vector<punto> poligono::intersect(inputitem* i) const {
    if( typeid(punto) == typeid(*i) ){
        punto * p = dynamic_cast<punto*>(i);
        vector<punto> punt ;
        if(polipunto(p)) punt.push_back(*p);
        return punt;
    }
    else{
        if(typeid(retta) == typeid(*i)){
            return rettapol(dynamic_cast<retta*>(i));
        }
        else return polipoli(dynamic_cast<poligono*>(i));
    }
}

//--------distance (0;0)(5;5)(3;0) (7;0)(13;0)(13;6)(7;6)

double poligono::distance(inputitem * i) const {
    if( typeid(retta) == typeid(*i) ){
        return poligono::distrettapol(dynamic_cast<retta*>(i),const_cast<poligono*>(this));
    }
    else if( typeid(punto) == typeid(*i) ){
        return poligono::distpuntopol(dynamic_cast<punto*>(i),const_cast<poligono*>(this));
    }
    else return poligono::distpolipoli(dynamic_cast<poligono*>(i),const_cast<poligono*>(this));
}

//voglio le tre funzioni siano indipendenti (avrei potuto fare il controllo sul vector su distance() )

double poligono::distpuntopol(punto * p , poligono * pol){
    vector<punto*> punti = pol->getpoint();
    vector<double> distanza;

    for(unsigned int i = 0 ; i < punti.size() - 1 ; ++i ){
        for(unsigned int j = i + 1 ; j < punti.size() ; ++j ){
            if(punti.size() == 3 || punto::distanceTwoPoints(*punti[i],*punti[j]) == pol->lato() ){
                retta latopol =  retta::rettaFromTwoPoints(*punti[i],*punti[j]);
                retta perp = retta::RettaPerpendicolare(latopol,*p);
                vector<punto> inter = retta::Intersect(perp,latopol);
                if( (inter[0].getX() <= punti[i]->getX() && inter[0].getX() >= punti[j]->getX() )
                    || (inter[0].getX() >= punti[i]->getX() && inter[0].getX() <= punti[j]->getX()) )
                {
                    distanza.push_back(punto::distanceTwoPoints(*p,inter[0]));
                }
            }
        }
        distanza.push_back(punto::distanceTwoPoints(*punti[i],*p));
    }
    distanza.push_back(punto::distanceTwoPoints(*punti[punti.size()-1],*p));

    if(distanza.size() == 0) throw input_error();
    vector<double>::iterator result = std::min_element(std::begin(distanza), std::end(distanza));
    distruggi(punti);
    return *result;
}

double poligono::distrettapol(retta * r , poligono * pol){

    vector<punto> inter = pol->rettapol(r);
    if( inter.size() == 0 ){

        vector<punto*> punti = pol->getpoint();
        vector<double> distanza;

        for(unsigned int i = 0 ; i < punti.size() ; ++i ){
            distanza.push_back(retta::distancePuntoRetta(*punti[i],*r));
        }

        vector<double>::iterator result = std::min_element(std::begin(distanza), std::end(distanza));
        distruggi(punti);
        return *result;
    }
    else return 0;
}

double poligono::distpolipoli(poligono * pol1, poligono * pol2){
    vector<punto> inter = pol1->polipoli(pol2);
    if( inter.size() > 0 ){
        return 0;
    }
    else{
        vector<punto*> punti1 = pol1->getpoint();
        vector<double> distanza;

        for(unsigned int i = 0 ;  i< punti1.size() ; ++i ){
            distanza.push_back(distpuntopol(punti1[i],pol2));
        }

        vector<punto*> punti2 = pol2->getpoint();
        for(unsigned int i = 0 ;  i< punti2.size() ; ++i ){
            distanza.push_back(distpuntopol(punti2[i],pol1));
        }

        vector<double>::iterator result = std::min_element(std::begin(distanza), std::end(distanza));
        distruggi(punti1);
        distruggi(punti2);
        return *result;
    }
}





// se ritorno un vector di size == 1 è un vertice del poligono









