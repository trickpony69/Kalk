import java.util.Vector;
import static java.lang.Math.*;


public class punto extends inputitem {
	private razionale x , y ;

	//---------------------costruttori------------------------------

	public punto( razionale a , razionale b ){
		x = a;
		y = b;
	}

	public punto() { 
		this(new razionale(),new razionale());
	}

	//--------------------------------------------------------------

	public String toString(){
		return "(" + x.toString() + " ; " + y.toString() + ") ";
	}

	public razionale getx(){
		return x;
	}

	public razionale gety(){
		return y;
	}


	//per evitare implementazioni future
	public final boolean equals(punto p) {
		if( (p.x.converti() == this.x.converti() ) && (p.y.converti() == this.y.converti() ))
			return true;
		else 
			return false;
	}

	public double distancefromtwopoints(punto p){
		return sqrt(pow((p.x.converti()-x.converti()),2)+pow((p.y.converti()-y.converti()),2));
	}

	public retta rettafromtwopoints(punto p2){

		razionale neg = new razionale(-1,1);
		razionale zero = new razionale();

	    if(this.x.equals(p2.x) && !(this.y.equals(p2.y))){
	        return new retta(neg,zero,this.x);
	    }
	    else if(!(this.x.equals(p2.x)) && this.y.equals(p2.y)){
	        return new retta(zero,neg,this.y);
	    }
	    else{
	        razionale a = new razionale(p2.x.converti() - this.x.converti());
	        razionale b = new razionale(p2.y.converti() - this.y.converti());
	        razionale c = new razionale( (a.multiply(this.x.multiply(neg))).converti() + (b.multiply(this.y)).converti());
	        return new retta(a,b.multiply(neg),c);
	    }	
	}

	public void pars_point(String p){
	    //rimuove gli spazi
	    p = p.replace(" ","");

	    //verifico se è un double
	    String s = new String();
	    boolean doub = false;
	    double virgola = 1 , n1 , n=0,d=1;
	    	    //virgola vale : 10 se ho un numero dopo la virgola  ,100 se ho due punti dopo la virgola , 1000 se ho tre punti dopo la virgola
	    
    	int sign=1;

    	if( !(p.substring(0,1).equals("(") ) && !(p.substring(p.length()-1,p.length()).equals(")") ) ) {
	        System.out.println("input_error_manca_)(");
	    }



	    for(int cont = 1 ; cont < p.length() +1 ; ++cont){

	    	String c = p.substring(cont-1,cont);

	        if(!c.equals( "(" ) ){

	            if(c == "-"){
	                sign = -1;
	            }
	            else if(c.equals( "/" )){
	                if(s.length() == 0) System.out.println("input_error_numeratore");//throw num_error();

	                if(doub) {
	                    n1 = Integer.parseInt(s);
	                    n = n1 / virgola;
	                }
	                else n = Integer.parseInt(s);

	                doub = false;
	                virgola = 1;


	                if( n == 0 ){
	                    while( !c.equals( ";" ) && !c.equals( ")" ) )
	                    {
	                    	cont++;
	                    	c = p.substring(cont-1,cont) ;
	                    }   
	                    if(c == ";")
	                        x = new razionale(0,1);
	                    else
	                        y = new razionale(0,1);
	                }
	                s = "";
	            }
	            else if( c.equals( ";" ) || c.equals( ")" ) ){
	                if(s.length() == 0){
	                    System.out.println("input_error_not_numero");
	                    break;
	                    //throw input_error();
	                }

	                if(n != 0){


	                    if(doub){
	                        n1 = Integer.parseInt(s);
	                        d = n1 / virgola;
	                    }
	                    else d = Integer.parseInt(s);


	                    doub = false;
	                    virgola = 1;

	                    //if( d == 0 ) throw den_error();

	                }else{

	                    if(doub) {
	                        n1 = Integer.parseInt(s);
	                        n = n1 / virgola;
	                    }
	                    else n = Integer.parseInt(s);


	                    virgola = 1 ;
	                    doub = false;

	                    d = 1;
	                }
	                if(c.equals( ";" ) ){
	                    x = new razionale(n*sign,d);
	                }
	                else{
	                    y = new razionale(n*sign,d);
	                    //è finito il punto perchè sono ')'
	                    break;
	                }

	                d=1;n=0;
	                s = "";
	                sign = 1;
	            }
	            else{
	                if(c.equals( "." ) ){
	                    doub = true;
	                }
	                else{
	                	try{
	                		Integer.parseInt(p.substring(cont-1,cont));
		                }
		                catch(java.lang.NumberFormatException nfe){
		                	System.out.println("not numeric" + p.substring(cont-1,cont) );
		                	break;
		                }

		                if(doub) virgola = virgola * 10 ;
		                s = s+p.substring(cont-1,cont);
	                }
	                
	            }
	        }
	    }
	    
	}

	//------------------------- virtuali puri -----------------------
	public double distance(inputitem i){
		if(i instanceof punto){
			punto p = (punto)i;
			return distancefromtwopoints(p);
		}
		/*else{
			return i.distance(this);
		}*/
		else return 0;
	}

	public Vector<punto> intersect(inputitem i){
		Vector<punto> v = new Vector<punto>();
		if(i instanceof punto){
			punto p = (punto)i;
			if( distancefromtwopoints(p) == 0 ){
				v.add(p);
			}
			return v;
		}
		return v;//i.intersect(this);
	}



}