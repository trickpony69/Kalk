import java.util.Vector;
import static java.lang.Math.*;


public class punto extends inputitem {
	private razionale x , y ;

	//---------------------costruttori------------------------------

	public punto( razionale a , razionale b ){
		x = a;
		y = b;
	}

	public punto( razionale a ){
		this(a,new razionale(1,1));
	}

	public punto() { 
		this(new razionale(),new razionale());
	}

	public punto( punto p ){
		this(p.getx(),p.gety());
	}

	//--------------------------------------------------------------

	public String toString(){
		return "(" + x.toString() + ";" + y.toString() + ")";
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
	        razionale b = new razionale(p2.x.converti() - this.x.converti());
	        razionale a = new razionale(p2.y.converti() - this.y.converti());
	        razionale c = new razionale( (a.multiply(this.x.multiply(neg))).converti() + (b.multiply(this.y)).converti());
	        return new retta(a,b.multiply(neg),c);
	    }	
	}

	public void pars_point(String p) throws eccezioni{
	    //rimuove gli spazi
	    p = p.replace(" ","");

	    //verifico se è un double
	    String s = new String();
	    boolean doub = false;
	    double virgola = 1 , n1 , n=0,d=1;
	    	    //virgola vale : 10 se ho un numero dopo la virgola  ,100 se ho due punti dopo la virgola , 1000 se ho tre punti dopo la virgola
	    
    	int sign=1;

    	String point[] = new String[p.length()];
	    point = p.split("");

    	if( !(p.substring(0,1).equals("(") ) && !(p.substring(p.length()-1,p.length()).equals(")") ) ) {
	        throw new input_error();
	    }




	    for(int cont = 0 ; cont < point.length ; cont++){

	        if(!point[cont].equals( "(" ) ){

	            if(point[cont].equals("-") || point[cont].equals("+")){
	                if(point[cont].equals("-") && sign == -1 ) sign = 1;
			else if(point[cont].equals("-") && sign == 1 ) sign = -1;
	            }
	            else if(point[cont].equals( "/" )){
	                if(s.length() == 0) throw new input_error();

                    n1 = Integer.parseInt(s);
                    n = n1 / virgola;

	                doub = false;
	                virgola = 1;


	                if( n == 0 ){
	                    while( !point[cont].equals( ";" ) && !point[cont].equals( ")" ) )
	                    {
	                    	cont++;
	                    }   
	                    if(point[cont].equals(";"))
	                        x = new razionale(0,1);
	                    else
	                        y = new razionale(0,1);
	                }
	                s = "";
	            }
	            else if( point[cont].equals( ";" ) || point[cont].equals( ")" ) ){
	                if(s.length() == 0){
	                    throw new input_error(); 
	                }

	                if(n != 0){

	                    n1 = Integer.parseInt(s);
	                    d = n1 / virgola;


	                    doub = false;
	                    virgola = 1;

	                    if( d == 0 ) throw new input_error();

	                }else{

                        n1 = Integer.parseInt(s);
                        n = n1 / virgola;


	                    virgola = 1 ;
	                    doub = false;

	                    d = 1;
	                }
	                if(point[cont].equals( ";" ) ){
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
	                if(point[cont].equals( "." ) ){
	                    doub = true;
	                }
	                else{
	                	try{

	                		Integer.parseInt(point[cont]);
		                }
		                catch(java.lang.NumberFormatException nfe){
		                	throw new not_numeric();
		                }

		                if(doub) virgola = virgola * 10 ;
		                s = s+point[cont];
	                }
	                
	            }
	        }
	    }
	    
	}

	//------------------------- virtuali puri -----------------------
	public double distance(inputitem i) throws eccezioni{
		if(i instanceof punto){
			punto p = (punto)i;
			return distancefromtwopoints(p);
		}
		else{
			return i.distance(this);
		}

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
		else return i.intersect(this);//i.intersect(this);
	}
}
