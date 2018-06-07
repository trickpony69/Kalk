import java.util.Vector;
import static java.lang.Math.*;
import java.StringUtils;

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
		return "(" + x.toString() + " ; " + y.toString() + ") \n ";
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

	public void pars_point(String p){
	    //rimuove gli spazi
	    p = p.replace(" ","");

	    //verifico se è un double
	    String s = new String();
	    boolean doub = false;
	    double virgola = 1 , n1 , n=0,d=1;
	    
    	int sign=1;
	    //virgola vale : 10 se ho un numero dopo la virgola  ,100 se ho due punti dopo la virgola , 1000 se ho tre punti dopo la virgola

	    for(int cont = 1 ; cont < p.length() - 1 ; ++cont){

	        if(p.substring(cont-1,cont) != "("){
	            if(p.substring(cont-1,cont) == "-"){
	                sign = -1;
	            }
	            else if(p.substring(cont-1,cont) == "/"){
	                if(s.length() == 0) System.out.println("input_error");//throw num_error();

	                if(doub) {
	                    n1 = Integer.parseInt(s);
	                    n = n1 / virgola;
	                }
	                else n = Integer.parseInt(s);

	                doub = false;
	                virgola = 1;


	                if( n == 0 ){
	                    while( p.substring(cont-1,cont) != ";" && p.substring(cont-1,cont) != ")" )
	                        cont++;
	                    if(p.substring(cont-1,cont) == ";")
	                        x = new razionale(0,1);
	                    else
	                        y = new razionale(0,1);
	                }
	                s = "";
	            }
	            else if(p.substring(cont-1,cont) == ";" || p.substring(cont-1,cont) == ")"){
	                if(s.length() == 0){
	                    System.out.println("input_error");
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
	                if(p.substring(cont-1,cont) == ";"){
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
	                if(p.substring(cont-1,cont) == "."){
	                    doub = true;
	                }
	                else if(isNumer(p.substring(cont-1,cont)))
	                {
	                  if(doub) virgola *= 10 ;
	                  s = s+p.substring(cont-1,cont);
	                }
	                else {
	                	System.out.println("input_error");
	                	break;
	                    //throw input_error();
	                }
	            }
	        }
	    }
	    /*if(p.substring(0) == '(' && p.substring(p.length()-1)== ')') {
	        throw 1;
	    }
	    //else throw input_error();*/
	}


	//------------------------- virtuali puri -----------------------
	public double distance(inputitem i){
		return 0;
	}

	public Vector<punto> intersect(inputitem i){
		punto ref = new punto( );
		Vector<punto> v = new Vector<punto>();
		v.add(ref);
		return v;
	}

	public static void main(String[] args) {
		inputitem i1 = new punto();
		inputitem i2 = new punto();
		Vector<punto> v = i1.intersect(i2);
		for (int i = 0 ; i < v.size() ; i++) {
			System.out.println(v.get(i));
		}

		String s = "ci d a o";
		punto p = (punto)i1 ;
		p.pars_point(s);
	}


}