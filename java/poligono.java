import java.util.Vector;

import java.util.Iterator;


public abstract class poligono extends inputitem {
	private int lati;

	protected Vector<punto> pt;

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
			ret = ret + o.toString() ;
		}

		return ret;
	}


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

	public boolean isRegular(){
		
		for(int i = 0 ; i < pt.size() - 1 ; i++){
    		for(int j = i + 1 ; i < pt.size() ; i++ ){
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
	    		for(int j = i + 1 ; i < pt.size() ; i++ ){
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
	    
}
		


