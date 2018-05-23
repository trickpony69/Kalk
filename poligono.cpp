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

//------------------ OPERATOR INPUT ----------------


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
            /*vector<punto*> p = pent.GetPoint();

            for(unsigned int i=0; i<p.size(); i++) cout<<*p[i]<<" - ";

            if( pent.isRegular() != razionale(0,0) )*/
                return new pentagono(pent);
            /*else
                throw irregular_pol();*/
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

vector<punto> poligono::printPoligon() const{
    vector<punto> temp;
    for(unsigned int i = 0 ; i < pt.size()-1 ; ++i ){
        for( unsigned int j = i + 1  ; j < pt.size() ; ++j ){
            if( punto::distanceTwoPoints(*pt[i],*pt[j]) == lato() ){
                retta r = retta::rettaFromTwoPoints(*pt[i],*pt[j]);
                vector<punto> single = r.print_rect(pt[i]->getX(),pt[j]->getX());
                temp.vector::insert(temp.end(), single.begin(), single.end());
            }
        }
    }
    return temp;
}

//mi dice se le x e le y dei poligoni si intersecano
bool poligono::isintersect( poligono * p1 , poligono * p2 ) {
    vector<punto*> vec1 = p1->GetPoint() ;
    vector<punto*> vec2 = p2->GetPoint() ;

    double minx1 , maxx1 , minx2 , maxx2 , miny1 , maxy1 , miny2 , maxy2 ;

    minx1 = vec1[0]->getX();
    maxx1 = vec1[0]->getX();
    miny1 = vec1[0]->getY();
    maxy1 = vec1[0]->getY();

    for(unsigned int i = 1 ; i < vec1.size() ; ++i ){
        if( minx1 > vec1[i]->getX() )
            minx1 = vec1[i]->getX();

        if( maxx1 < vec1[i]->getX() )
            maxx1 = vec1[i]->getX();

        if( miny1 > vec1[i]->getY() )
            miny1 = vec1[i]->getY();

        if( maxy1 < vec1[i]->getY() )
            maxy1 = vec1[i]->getY();
    }

    minx2 = vec2[0]->getX();
    maxx2 = vec2[0]->getX();
    miny2 = vec2[0]->getY();
    maxy2 = vec2[0]->getY();

    for(unsigned int i = 1 ; i < vec2.size() ; ++i ){
        if( minx2 > vec2[i]->getX() )
            minx2 = vec2[i]->getX();

        if( maxx2 < vec2[i]->getX() )
            maxx2 = vec2[i]->getX();

        if( miny2 > vec2[i]->getY() )
            miny2 = vec2[i]->getY();

        if( maxy2 < vec2[i]->getY() )
            maxy2 = vec2[i]->getY();
    }
    //verifico se gli intervalli x1 e x2 si intersecano
    if((minx1 > minx2 && minx1 < maxx2) || (minx2 >= minx1 && minx2 <= maxx1) || (maxx1 >= minx2 && maxx1 <= maxx2) || (maxx2 >= minx1 && maxx2 <= maxx1))
        if((miny1 > miny2 && miny1 < maxy2) || (miny2 >= miny1 && miny2 <= maxy1) || (maxy1 >= miny2 && maxy1 <= maxy2) || (maxy2 >= miny1 && maxy2 <= maxy1))
            return true;

    return false;
}

vector<punto> poligono::rettapol(retta * r) const{
    vector<punto> p;

    vector<punto*> vCoord0 = GetPoint();

    for(int i = 0; i<vCoord0.size() - 1; i++){
        for(int j = i + 1; j<vCoord0.size(); j++){
           if(punto::distanceTwoPoints(*vCoord0[i],*vCoord0[j]) == lato() || vCoord0.size() == 3){
                retta prova = retta::rettaFromTwoPoints(*vCoord0[i],*vCoord0[j]);
                vector<punto> intr = retta::Intersect(prova,*r);
                if(intr.size() > 0){
                    if( (vCoord0[i]->getX() <= intr[0].getX() && vCoord0[j]->getX() >= intr[0].getX() )
                            || (vCoord0[i]->getX() >= intr[0].getX() && vCoord0[j]->getX() <= intr[0].getX() ) )
                    {
                        if( (vCoord0[i]->getY() <= intr[0].getY() && vCoord0[j]->getY() >= intr[0].getY() )
                                || (vCoord0[i]->getY() >= intr[0].getY() && vCoord0[j]->getY() <= intr[0].getY() ) )
                            p.push_back(punto(intr[0]));//copio il punto dentro
                    }
                }
                intr.erase(intr.begin(),intr.end());
           }
        }
    }
    return p;
}

vector<punto> poligono::polipoli(poligono * pol) const{
    vector<punto> p;

    vector<punto*> vCoord0 = GetPoint();

    for(int i = 0; i<vCoord0.size() - 1; i++){
        for(int j = i + 1; j<vCoord0.size(); j++){
             if(punto::distanceTwoPoints(*vCoord0[i],*vCoord0[j]) == lato() || vCoord0.size() == 3){
                 retta prova = retta::rettaFromTwoPoints(*vCoord0[i],*vCoord0[j]);
                 vector<punto> single = pol->rettapol(&prova);

                 p.vector::insert(p.end(), single.begin(), single.end());

             }
        }
    }
    return p;
}









