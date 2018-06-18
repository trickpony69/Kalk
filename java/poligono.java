import java.util.Vector;
import java.util.Collections;



public abstract class poligono extends inputitem {
	//privata--------------------
	private int lati;

	//protected-----------------

	protected boolean isRegular(){

		//verifico non ci siano doppioni
		for(int i = 0 ; i < pt.size() - 1 ; i++){
    		for(int j = i + 1 ; j < pt.size() ; j++ ){
    			if((pt.get(i)).equals(pt.get(j))) return false; 
    		}
    	}

	    if(getlati() == 3){
	    	
	    	retta r = (pt.get(0)).rettafromtwopoints(pt.get(1));

	    	if((r.intersect(pt.get(2))).size() >= 1){
	    		return false;
	    	}
	    	return true;
	    }
	    else{
	    	double conf = lato();
	    	int check = 0;

	    	for(int i = 0 ; i < pt.size() - 1 ; i++){
	    		for(int j = i + 1 ; j < pt.size() ; j++ ){
	    			if((pt.get(i)).distancefromtwopoints(pt.get(j)) == conf )
	    				check++;
	    		}
	    	}

		    if(check == getlati()){
		        return true;
		    }
		    else return false;
	    }
	}

	protected Vector<punto> pt;

	protected double distancepuntopol(punto p ) throws eccezioni{
		Vector<punto> punti = getpoint();
		Vector<Double> distanza = new Vector<Double>();

		//1: creo retta r per ogni coppia di vertice che forma un lato
		//2: creo retta perpendicolare alla retta r passante per il punto p.
		//3: se l'intersezione tra le due rette è compresa tra i due punti che fromano il lato allora salvo 
		//la distanza tra i due punti (p e intersezione).
		//4: salvo la distanza anche tra i vertici del poligono e il punto
		//5: Verifico la distanza minima e la ritorno

		for(int i = 0 ; i < punti.size() - 1 ; ++i ){
            for(int j = i + 1 ; j < punti.size() ; ++j ){

                if( (punti.size() == 3) || ((punti.get(i)).distancefromtwopoints(punti.get(j)) == lato())){

                    retta latopol =  (punti.get(i)).rettafromtwopoints((punti.get(j)));
   	                retta perp = latopol.rettaperpendicolare(p); 
	                Vector<punto> inter = perp.intersectretta(latopol);
	                
	                if(inter.size() > 0){
		                if( (punti.get(i)).getx().converti() == (punti.get(j)).getx().converti() ) {
		                	if( ( (inter.get(0)).gety().converti() <= (punti.get(i)).gety().converti() && (inter.get(0)).gety().converti() >= (punti.get(j)).gety().converti() )
		                    || ((inter.get(0)).gety().converti() >= (punti.get(i)).gety().converti() && (inter.get(0)).gety().converti() <= (punti.get(j)).gety().converti() ) )
		                		distanza.add(p.distancefromtwopoints(inter.get(0)));
		                }
		                else{
			                if( ((inter.get(0)).getx().converti() <= (punti.get(i)).getx().converti() && (inter.get(0)).getx().converti() >= (punti.get(j)).getx().converti() )
			                    || ((inter.get(0)).getx().converti() >= (punti.get(i)).getx().converti() && (inter.get(0)).getx().converti() <= (punti.get(j)).getx().converti()) )
			                {
			                    distanza.add(p.distancefromtwopoints(inter.get(0)));
			                }
			            }
			        }
		            	
                }

            }

            distanza.add(p.distancefromtwopoints(punti.get(i)));

        }
        distanza.add(p.distancefromtwopoints(punti.get(punti.size()-1)));
	
        if(distanza.size() == 0) throw new input_error();
	    Double result = (Double)Collections.min(distanza);
	    return result;
	}

	protected double distrettapol(retta r){
        Vector<punto> punti = getpoint();
        Vector<Double> distanza = new Vector<Double>();

        for(int i = 0 ; i < punti.size() ; ++i ){
            distanza.add(r.distancePuntoRetta(punti.get(i)));
        }

        Double result = (Double)Collections.min(distanza);
	    return result;
	}

	protected double distpolipoli( poligono pol ) throws eccezioni{
        Vector<punto> punti = getpoint();
        Vector<Double> distanza = new Vector<Double>();

        for(int i = 0 ;  i< punti.size() ; ++i ){
            distanza.add(pol.distancepuntopol(punti.get(i)));
        }

        Vector<punto> punti2 = pol.getpoint();
        for(int i = 0 ;  i< punti2.size() ; ++i ){
            distanza.add(this.distancepuntopol(punti2.get(i)));
        }

        return (Double)Collections.min(distanza);

    }

    protected Vector<punto> rettapol(retta r , Vector<punto> range ){ //if(range.size() > 0 ) arrivo da polipoli()
		Vector<punto> rit = new Vector<punto>(); 
		Vector<punto> punti = getpoint();
		
		double lat = 0;
		if(punti.size() > 3){
			lat = lato();
		}


		for( int i = 0 ; i < punti.size() - 1 ; i++ ){
			for( int j = i+1 ; j < punti.size() ; j++ ){
				if( punti.size() == 3 || (punti.get(i)).distancefromtwopoints(punti.get(j)) == lat){
					retta temp = (punti.get(i)).rettafromtwopoints(punti.get(j));
					Vector<punto> inter = temp.intersectretta(r);

					if(inter.size() > 0){
						if( ( ((punti.get(i)).getx()).converti() <= (inter.get(0)).getx().converti()  &&  (punti.get(j)).getx().converti()  >= (inter.get(0)).getx().converti()  )
							|| ( (punti.get(i)).getx().converti()  >= (inter.get(0)).getx().converti()  &&  (punti.get(j)).getx().converti()  <= (inter.get(0)).getx().converti()  ) )
						{
							if( ( (punti.get(i)).gety().converti()  <= (inter.get(0)).gety().converti()  &&  (punti.get(j)).gety().converti()  >= (inter.get(0)).gety().converti()  )
								|| ( (punti.get(i)).gety().converti()  >= (inter.get(0)).gety().converti()  &&  (punti.get(j)).gety().converti()  <= (inter.get(0)).gety().converti()  ) )
						
							{
								if(range.size() > 0 ){
									 if( ( ((range.get(0)).getx().converti()  <= (inter.get(0)).getx().converti()  && (range.get(1)).getx().converti()  >= (inter.get(0)).getx().converti()  )
                                        || ((range.get(0)).getx().converti()  >= (inter.get(0)).getx().converti()  && (range.get(1)).getx().converti()  <= (inter.get(0)).getx().converti()  ) )
                                        && ( ((range.get(0)).gety().converti()  <= (inter.get(0)).gety().converti()  && (range.get(1)).gety().converti()  >= (inter.get(0)).gety().converti()  )
                                        || ((range.get(0)).gety().converti()  >= (inter.get(0)).gety().converti()  && (range.get(1)).gety().converti()  <= (inter.get(0)).gety().converti()  ) ) )
										{
											rit.add(inter.get(0));
										}
										
								}
								else rit.add(inter.get(0));
							}
						}
					}
				}
			}
		}

		//verifico i doppioni
		if( rit.size() > 1 ){
	        for(int i = 0 ; i < rit.size() - 1 ; ++i ){
	            for(int j = i + 1 ; j < rit.size() ; ++j ){
	                if( rit.get(i).equals(rit.get(j)) ){
	                    rit.remove(j);
	                    --j;
	                }

	            }
	        }
    	}

    	return rit;

	}

	//poligono-punto
	protected boolean polipunto(punto p){

		Vector<punto> pnt = getpoint();

		for(int i= 0 ; i < pnt.size() ; i++){
			if(pnt.get(i).equals(p)){
				return true; //il punto è uno dei vertici
			}
		}

		//creo retta parallela all'asse x e passante per p (rperp)
		retta paralx = new retta(0.0,1.0,-3.0);
		retta rperp = paralx.rettaparallela(p);

		Vector<punto> inter = new Vector<punto>();
		inter = rettapol(rperp,inter);

		//>= 2 perchè se fosse uno sarebbe un vertice o esterno
		if(inter.size() >= 2){

			//verifico sia uno a destra e uno a sinistra
			if((inter.get(0).getx().converti() <= p.getx().converti() && inter.get(1).getx().converti() >= p.getx().converti())
               || (inter.get(0).getx().converti() >= p.getx().converti() && inter.get(1).getx().converti() <= p.getx().converti() ) )
		       {
		           return true;
		       }
		}
		return false;

	}

	//punti interni tra poligoni
	protected Vector<punto> puntint(poligono p){
		Vector<punto> punti1 = p.getpoint();
		Vector<punto> inter = new Vector<punto>();

		for(int i = 0 ;  i < punti1.size() ; i++){
			if(this.polipunto(punti1.get(i))){
	            inter.add(punti1.get(i));
	        }
		}
		//se ho n elementi nel vector e il poligono ha n vertici allora è interno e non vado a fare un ulteriore controllo

		if(inter.size() != p.getlati()){
			Vector<punto> punti2 = this.getpoint();
			for(int i = 0 ;  i < punti2.size() ; i++){
				if(p.polipunto(punti2.get(i))){
		            inter.add(punti2.get(i));
		        }
			}
		}

		return inter;
	}

	protected Vector<punto> polipoli(poligono p) {
		Vector<punto> puntinterni = puntint(p);
		Vector<punto> inter = new Vector<punto>();

		if( puntinterni.size() > 0 ){
			inter = (Vector<punto>)puntinterni.clone();
		}

		Vector<punto> punti = getpoint();

		for(int i = 0; i < punti.size() - 1; i++){
	        for(int j = i + 1; j<punti.size(); j++){
	             if(punti.get(i).distancefromtwopoints(punti.get(j)) == lato() || punti.size() == 3){
                 	retta prova = punti.get(i).rettafromtwopoints(punti.get(j));
                 
	                //contiene i due punti per il range da rispettare (vedi rettapol)
	                Vector<punto> temp = new Vector<punto>();
	                temp.add(punti.get(i));
	                temp.add(punti.get(j));

	                Vector<punto> single = p.rettapol(prova,temp);

                 	int cont=0;
           
                 	while(cont<single.size()){
                 		
                 		inter.add(single.get(cont));
                 		++cont;
                 	}
	            }
	        }
	    }
	    if( inter.size() > 1 ){
	        for(int i = 0 ; i < inter.size() - 1 ; ++i ){
	            for(int j = i + 1 ; j < inter.size() ; ++j ){
	                if( inter.get(i).equals(inter.get(j)) ){
	                    inter.remove(j);
	                    --j;
	                }

	            }
	        }
    	}


    	return inter;
	}

	//public-----------------------------

	public poligono(int i , Vector<punto> p){
		lati = i;
		pt = p;	
	}

	public poligono(int i){
		lati = i;
		pt = new Vector<punto>();	
	}

	public int getlati(){
		return lati;
	}

	public Vector<punto> getpoint(){
		Vector<punto> p = (Vector<punto>)pt.clone();
		return p;
	}

	public poligono pars_pol(String pol) throws eccezioni{

		pol = pol.replace(" ","");

		int parentesi_c = 0 , parentesi_a = 0, puntvirg = 0;

		String polig[] = new String[pol.length()];
	    polig = pol.split("");

		for (int punt = 0; punt < polig.length ; punt++) {
			if(polig[punt].equals("(")) parentesi_a++;

            if(polig[punt].equals(";")) puntvirg++;

            if(polig[punt].equals(")")) parentesi_c++;
		}


	    Vector<punto> temp = new Vector<punto>();

	    if(parentesi_c == parentesi_a && parentesi_c == puntvirg && puntvirg >= 3 && puntvirg <= 4){

	        for (int punt = 0; punt < polig.length ; punt++) {
	            
	            String single_point = new String();

	            for (int i = punt; !polig[i].equals(")") && i < polig.length -1 ; i++) {
	                single_point = single_point + polig[i] ;
	            }

	            punt = punt + single_point.length();
	            single_point = single_point + polig[punt] ; //aggiungo la parentesi chiusa ")"

	            punto point = new punto();

	            try{point.pars_point(single_point);}
	            catch(eccezioni e){
	            	throw new input_error();
	            }

	            
	            temp.add(point);
	        }
	        if( parentesi_a == 3 ){
	            triangolo tr = new triangolo(parentesi_a,temp);
	            if(tr.isRegular())
	            	return tr;
	            else
	                throw new poligonlinearexception();

	        }
	        else if( parentesi_a == 4 )
	        {
	        	quadrato qr = new quadrato(parentesi_a,temp);
	            if( qr.isRegular()  )
	            	return qr;
	            else
	                throw new not_regular();
	        }

	        

	    }
	    //eccezione not poligono considerato
	    throw new input_error();
	}

	public String toString(){
		String ret = new String();

		for(Object o : pt){
			ret = ret + o.toString() + " " ;
		}

		return ret;
	}

	//funziona dai quadrati in su , su triangolo è overloadato
	public double lato() {
		double lat = (pt.get(0)).distancefromtwopoints(pt.get(1));

	    //il lato e' la distanza minima tra i punti inseriti
	    //posso verificarlo in soli tre controlli
	    for(int i = 2 ; i < 4 ; i ++ ){
	       double p = (pt.get(i)).distancefromtwopoints(pt.get(0));
	       if(p < lat) lat = p ;
	    }
	    return lat;
	}



	//su triangolo è overloadato
	public double perimetro(){
		return getlati()*lato();
	}

	public abstract double getfisso();

	//su triangolo è overloadato
	public double area() {
	    double apotema = getlati() * getfisso();
	    return (perimetro()*apotema)/2;
	}

	//---------------INTERSEZIONI------------------------

	//retta - poligono




	public final double distance(inputitem i) throws eccezioni{
		if(i instanceof retta){
			return distrettapol((retta)i);
		}
		else if(i instanceof punto){
			return distancepuntopol((punto)i);
		}
		else{
			return distpolipoli((poligono)i);
		}
	}

	public final Vector<punto> intersect(inputitem i){
		
		Vector<punto> temp = new Vector<punto>();
		if(i instanceof retta){
			return rettapol((retta)i,temp);
		}
		else if(i instanceof punto){
			
			if(polipunto((punto)i) == true){
				temp.add((punto)i);
			}
			return temp;
		}
		else{
			return polipoli((poligono)i);
		}

		
	} 




	    
}
		


