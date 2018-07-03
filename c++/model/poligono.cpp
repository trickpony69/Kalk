#include "poligono.h"




poligono::poligono(int l , const vector<punto*>& p):lati(l){
    pt = copia(p);
}


unsigned int poligono::getlati() const {
    return lati;
}

vector<punto*> poligono::getpoint() const {
    return copia(pt); //ritorno la copia dei puntatori a punto
}

//massimo tre controlli : visto che utilizziamo poligoni regolari fino a 4 lati
//quindi prendendo tre segmenti posso capire qual'e' il lato del poligono
double poligono::lato() const{

    double lat = pt[0]->distanceTwoPoints(*pt[1]);

    //il lato e' la distanza minima tra i punti inseriti
    for(int i = 2 ; i < 4 ; i ++ ){
       double p = pt[0]->distanceTwoPoints(*pt[i]);
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
                if(pt[i]->distanceTwoPoints(*pt[j]) == conf) {
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

void poligono::distruggi(vector<punto*>& v) {
    vector<punto*>::iterator it = v.begin();
    for( ; it != v.end() ; ++it ){;
        delete *it;
        v.erase(it);
        --it;
    }
}

//---------------COPIA PROFONDA-------------

vector<punto*> poligono::copia(const vector<punto*>& v){
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
        lati = p.lati;
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

        distruggi(p1);
        distruggi(p2);

        if(cont == lati) return true;


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
                throw ;
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

//p1 e p2 sono diversi da nullptr nel momento in cui viene invocata all'interno di polipoli()
//questo perche' bisogna verificare che il punto trovato sia all'interno dei range dei due lati e non solo di uno
vector<punto> poligono::rettapol(retta * r , punto * p1 = nullptr  ,punto * p2 = nullptr) const{
    vector<punto> p;

    vector<punto*> vCoord0 = getpoint();

    for(unsigned int i = 0; i<vCoord0.size() - 1; i++){
        for(unsigned int j = i + 1; j<vCoord0.size(); j++){
           if(vCoord0[i]->distanceTwoPoints(*vCoord0[j]) == lato() || vCoord0.size() == 3){
                retta prova = retta::rettaFromTwoPoints(*vCoord0[i],*vCoord0[j]);
                vector<punto> intr = prova.Intersect_rette(*r);

                //intersezione tra due rette è al massimo un punto
                if(intr.size() > 0){

                    //- devo verificare che il punto trovato sia compreso tra i due vertici presi in considerazione :
                    //- quindi primo controllo verifico che la x dell'intersezione sia compreso tra le x di vCoord0[i] e vCoord0[j]
                    //  poi avviene lo stesso controllo sulle y
                    //- se vCoord0[i] e vCoord0[j] hanno la stessa x (lato parallelo all'asse y) allora vado a verificare direttamente le y
                    //  (vale il contrario con le y)
                    if( (vCoord0[i]->getX() <= intr[0].getX() && vCoord0[j]->getX() >= intr[0].getX() )
                            || (vCoord0[i]->getX() >= intr[0].getX() && vCoord0[j]->getX() <= intr[0].getX() ) || (vCoord0[i]->getX() == vCoord0[j]->getX() ) ) //se ho la stessa x non la verifico
                    {
                        if( (vCoord0[i]->getY() <= intr[0].getY() && vCoord0[j]->getY() >= intr[0].getY() )
                                || (vCoord0[i]->getY() >= intr[0].getY() && vCoord0[j]->getY() <= intr[0].getY() ) || (vCoord0[i]->getY() == vCoord0[j]->getY() ) )
                        {
                            if(p1 && p2){ //invocata in polipoli: p1 e p2 sono i punti che formano la retta r, quindi vado a veridfica che il punto sia tra quelle x e y.x
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

    //verifico non ci siano ridondanze nel vector
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

vector<punto> poligono::puntint(const poligono & p1) const{
    vector<punto*> punti = getpoint();
    vector<punto> inter;
    for(unsigned int i = 0; i < punti.size(); i++){
        if(p1.polipunto(punti[i])){
            if(p1.polipunto(punti[i])) inter.push_back(*(punti[i]));
        }
    }

    //se il ho n elementi nel vector e il poligono ha n vertici allora è interno e non vado a fare un ulteriore controllo
    if(inter.size() != getlati()){
        vector<punto*> punti2 = p1.getpoint();
        for(unsigned int i = 0; i < punti2.size(); i++){
            if(polipunto(punti2[i])) inter.push_back(*(punti2[i]));
        }
        distruggi(punti2);
    }

    distruggi(punti);


    return inter;
}

vector<punto> poligono::polipoli(poligono * pol) const{
    vector<punto> p,puntinterni;

    puntinterni = puntint(*pol);

    if( puntinterni.size() > 0 ){
        p.vector::insert(p.end(), puntinterni.begin(), puntinterni.end());
    }

    vector<punto*> vCoord0 = getpoint();

    for(unsigned int i = 0; i<vCoord0.size() - 1; i++){
        for(unsigned int j = i + 1; j<vCoord0.size(); j++){
             if(vCoord0[i]->distanceTwoPoints(*vCoord0[j]) == lato() || vCoord0.size() == 3){
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
    retta r = paralx.RettaParallela(*p);
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

/*
NB: il controllo delle ridondanze dei punti sul vector avviene all'interno di più funzioni, l'obiettivo è renderle indipendenti
    per un eventuale modifica futura.
*/

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

//--------distance------------------------------------------

double poligono::distance(inputitem * i) const {
    //verifico che i due elementi non si intersecano, cosi eventualmente evitare calcoli inutii
    if( (intersect(i)).size() > 0 ) return 0;

    if( typeid(retta) == typeid(*i) ){
        return distrettapol(dynamic_cast<retta*>(i));
    }
    else if( typeid(punto) == typeid(*i) ){
        return distpuntopol(dynamic_cast<punto*>(i));
    }
    else return distpolipoli(dynamic_cast<poligono*>(i));
}

double poligono::distpuntopol(punto * p ) const{
    vector<punto*> punti = getpoint();
    vector<double> distanza;

    for(unsigned int i = 0 ; i < punti.size() - 1 ; ++i ){
        for(unsigned int j = i + 1 ; j < punti.size() ; ++j ){
            if(punti.size() == 3 || punti[i]->distanceTwoPoints(*punti[j]) == lato() ){
                retta latopol =  retta::rettaFromTwoPoints(*punti[i],*punti[j]);
                retta perp = latopol.RettaPerpendicolare(*p);
                vector<punto> inter = perp.Intersect_rette(latopol);
                if( punti[i]->getX() == punti[j]->getX() ){
                    if( (inter[0].getY() <= punti[i]->getY() && inter[0].getY() >= punti[j]->getY() )
                    || (inter[0].getY() >= punti[i]->getY() && inter[0].getY() <= punti[j]->getY()) )
                        distanza.push_back(inter[0].distanceTwoPoints(*p));
                }
                else{
                    if( (inter[0].getX() <= punti[i]->getX() && inter[0].getX() >= punti[j]->getX() )
                    || (inter[0].getX() >= punti[i]->getX() && inter[0].getX() <= punti[j]->getX()) )
                    {
                        distanza.push_back(inter[0].distanceTwoPoints(*p));
                    }
                }
                
            }
        }
        distanza.push_back(p->distanceTwoPoints(*punti[i]));
    }
    distanza.push_back(p->distanceTwoPoints(*punti[punti.size()-1]));

    if(distanza.size() == 0) throw input_error("Errore.");
    vector<double>::iterator result = std::min_element(std::begin(distanza), std::end(distanza));
    distruggi(punti);
    return *result;
}

double poligono::distrettapol(retta * r ) const{
    vector<punto*> punti = getpoint();
    vector<double> distanza;

    for(unsigned int i = 0 ; i < punti.size() ; ++i ){
        distanza.push_back(r->distancePuntoRetta(*punti[i]));
    }

    vector<double>::iterator result = std::min_element(std::begin(distanza), std::end(distanza));
    distruggi(punti);
    return *result;
}

double poligono::distpolipoli(poligono * pol1) const{
    vector<punto*> punti1 = pol1->getpoint();
    vector<double> distanza;

    for(unsigned int i = 0 ;  i< punti1.size() ; ++i ){
        distanza.push_back(distpuntopol(punti1[i]));
    }

    vector<punto*> punti2 = getpoint();
    for(unsigned int i = 0 ;  i< punti2.size() ; ++i ){
        distanza.push_back(pol1->distpuntopol(punti2[i]));
    }

    vector<double>::iterator result = std::min_element(std::begin(distanza), std::end(distanza));
    distruggi(punti1);
    distruggi(punti2);
    return *result;
}










