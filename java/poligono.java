import java.util.Vector;


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

	public poligono pars_pol(String pol){

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

	            /*try{*/point.pars_point(single_point);/*}

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
	            }*/
	            
	            temp.add(point);
	        }
	        if( parentesi_a == 3 ){
	            return new triangolo(parentesi_a,temp);
	        }
	        else if( parentesi_a == 4 )
	        {

	            //if( qr.isRegular()  )
	            return new quadrato(parentesi_a,temp);
	            /*else
	                System.out.println("not_iregular");//throw irregular_pol();
	        */}

	        

	    }
	    //eccezione not poligono considerato
	    return new quadrato(); 
	}

	public String toString(){
		String ret = new String();

		for(Object o : pt){
			ret = ret + o.toString() ;
		}

		return ret;
	}
		


}