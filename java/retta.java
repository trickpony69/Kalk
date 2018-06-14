import java.util.Vector;
import static java.lang.Math.*;

class retta extends inputitem {
	private razionale a, b , c ;

	public retta(razionale x,razionale y, razionale l){
		a = x;
		b = y;
		c = l;
	}

	public retta(){
		this(new razionale(),new razionale(),new razionale());	
	}

	public retta(double n, double m,double o){
		this(new razionale(n),new razionale(m),new razionale(o));
	}

	public razionale getA(){
		return a;
	}

	public razionale getB(){
		return b;
	}

	public razionale getC(){
		return c;
	}

	public String toString(){
		String ret = new String();

		ret = ret + "( ";
		
		if( a.getnum() != 0 ) ret = ret + a + " x " ;

		if( b.getnum() != 0 ) {
			if( b.sign() == true ) ret = ret + " + ";

			ret = ret + b  + " y " ;
		}

		if( c.getnum() != 0 ){
			if( c.sign() == true ) ret = ret + " + ";

		    ret = ret + c ;
		}

		ret = ret + " )";


		return ret;
	}

	public double distancePuntoRetta(punto p){

		return  ( (abs( (a.multiply(p.getx())).converti() + (b.multiply(p.gety())).converti() + c.converti() ) )  /(sqrt(pow(a.converti(),2) + pow(b.converti(),2))));
	}

	public double distanceRettaRetta(retta r){
		punto x = new punto();
		razionale neg = new razionale(-1,1);
		razionale zero = new razionale();

		if(r.a.getnum() == 0){
	        x = new punto(zero,neg.multiply(r.c.multiply(r.b.inverso())));
	    }
	    else if(r.b.getnum() == 0 ){
	        x = new punto(((r.c.multiply(r.a.inverso())).multiply(neg)),zero);
	    }
	    else{

	        x = new punto(zero,(neg.multiply(r.c.multiply(r.b.inverso()))));
	    }
	    return distancePuntoRetta(x);
	}


	public boolean isParallels(retta r2 ){
		razionale neg = new razionale(-1,1);
		razionale zero = new razionale();

	    double coeffA = neg.multiply((this.a.multiply(this.b.inverso()))).converti();
	    double coeffB = neg.multiply((r2.a.multiply(r2.b.inverso()))).converti();
	    if(coeffA == coeffB) return true;
	    else return false;
	}

	public boolean isPerpendicolari( retta r2){
		razionale neg = new razionale(-1,1);
	    if( neg.multiply((this.a.multiply(this.b.inverso()))).equals(neg.multiply(neg.multiply((r2.a.multiply(r2.b.inverso())).inverso()))) )
	        return true;
	    else return false;
	}

	//retta perpendicolare a un altra e passante per un punto
	public retta rettaperpendicolare(punto p ){
		razionale neg = new razionale(-1,1);
		razionale zero = new razionale();

	    if( b.getnum() != 0 && a.getnum() != 0 ){
	        //trovo il coefficente angolare
	        razionale m = new razionale(a.multiply(neg),b);
	        //trovo l'antireciproco del coefficente angolare
	        razionale new_m =  (m.inverso()).multiply(neg);
	        //trovo c => y1 + m*x1
	        razionale c = new_m.multiply(p.getx());
	        c = new razionale( (c.multiply(neg)).converti() + (p.gety()).converti());
	        return new retta(new_m,neg,c);
	    }else{
	        if( a.equals(0) ){
	           return new retta( neg,zero,p.getx() );
	        }
	        else return new retta( zero,neg,p.gety() );
	    }
	}

	public retta rettaparallela(punto p){
		razionale neg = new razionale(-1,1);
		razionale zero = new razionale();

		if( b.getnum() != 0 && a.getnum() != 0){ //disuguaglianza double ==> primitivi
	        //trovo il coefficente angolare
	        razionale m = new razionale( a.multiply(neg),b );
	        //trovo c => y1 + m*x1
	        razionale c = m.multiply(p.getx()) ;

	        c = (c.multiply(neg)).add(p.gety());

	        return new retta(m,neg,c);
	    }
	    else{
	        if(getA().getnum() == 0){
	            return new retta(zero,neg,p.gety());
	        }
	        else return new retta(neg,zero,p.getx());
	    }
	}


	//dato una x ritorna il punto rispettivo 
	public punto printCoord_x(razionale x) throws eccezioni{
		razionale neg = new razionale(-1,1);

		razionale y = new razionale(1,1);

		if(getB().getnum() == 0 && getA().getnum() == 0){
	       throw new implicit();
	    }
	    else if(getB().getnum() == 0){
	        x = new razionale ( getC().multiply(neg) , getA() );

	    }
	    else{
	        y = new razionale( (getA().multiply(neg)).multiply(x).add(getC().multiply(neg)) ,getB());
	    }

	    return new punto(x,y);
	}

	//mi serve per disegnare... la facciooo ?
	/*public Vector<punto> print_rect() {

	}*/

	public Vector<punto> intersectretta(retta r1){
		Vector<punto> p = new Vector<punto>();
		razionale neg = new razionale(-1,1);

		if(isParallels(r1) == true) return p;

		razionale det = new razionale ( getA().multiply(r1.getB()).add( neg.multiply(r1.getA().multiply(getB()) ) ));

		if(det.getnum() != 0){

			razionale detx = new razionale(((getC().multiply(neg)).multiply(r1.getB())).add(neg.multiply((r1.getC().multiply(neg)).multiply(getB()))),det) ;

	        razionale dety = new razionale(((getA().multiply(neg)).multiply(r1.getC())).add(neg.multiply((r1.getA().multiply(neg)).multiply(getC()))),det) ;

	        p.add(new punto(detx,dety));	        
		}
		else{
			razionale x = new razionale( ((getC().multiply((r1.getB()).multiply(getB().inverso()))).add(neg.multiply(r1.getC()))),(r1.getA()).add(neg.multiply(getA().multiply((r1.getB()).multiply(getB().inverso())))));
	        razionale y = new razionale((getA().multiply(x)).multiply(neg.multiply(getB())).add(getC().multiply((neg.multiply(getB())).inverso())));
	        p.add(new punto(x,y));
		}
		return p;
	}

	public double distance(inputitem i) throws eccezioni{
		if(i instanceof retta){
			if((this.intersect(i)).size() == 1) return 0;
			retta r = (retta)i;
			return distanceRettaRetta(r);
		}
		else if(i instanceof punto){
			punto p = (punto)i;
			return distancePuntoRetta(p);
		}
		else{
			return i.distance(this);
		}
	}

	public Vector<punto> intersect(inputitem i){
		Vector<punto> v = new Vector<punto>();
		
		if(i instanceof retta){
			retta r = (retta)i;
			return intersectretta(r);
		}
		else if(i instanceof punto){
			punto p = (punto)i ;
			if(distancePuntoRetta(p) == 0) {
				v.add(p);
			}
		}
		else{
			return i.intersect(this);
		}

		return v;//i.intersect(this);
	}

	public void pars_rect(String retta) throws eccezioni
	{
		retta = retta.replace(" ","");

		//inserisco = a prescindere
	    retta = retta + '=';

	    String s = new String();
	    retta r;

	    // raz = verifica se è una frazione .
	    // incx = incy = serve per verificare se trova due volte la
	    // la x o la y .
	    boolean raz = false , incx = false , incy = false , doub = false , segno = false ;

	    //n = num , d = den , x = coeff x , y = coeff y , tn = termine noto
	    double n=0,d=0,x=0,y=0,tn=0;

	    int sign = 1;
	    double virgola = 1 , n1;

	    String rect[] = new String[retta.length()];
	    rect = retta.split("");

	    for(int i = 0 ; i < rect.length; i++){

	        //vado a verificare ci sia solo una x e una y altrimenti non e' nella forma prevista
	        if(rect[i].equals("y") && incy == false) incy = true ;
	        else if(rect[i].equals("y") && incy == true) throw new implicit();

	        if(rect[i].equals("x") && incx == false) incx = true ;
	        else if(rect[i].equals("x") && incx == true) throw new implicit();

	        if( !rect[i].equals("*") && !rect[i].equals("=") )
	        {
	            if( rect[i].equals("-") || rect[i].equals("+") ){
	                //verifico se il termine noto è a primo o secondo membro

	                if(s.length() > 0){
	                    n1 = Integer.parseInt(s);
	                    tn = n1 / virgola;

	                    virgola = 1;
	                    doub = false;

	                    if( ( !(b.getnum() == 0) || (a.getnum() == 0) ) && segno == false )  throw new input_error();

	                    c = new razionale(sign*tn,1);
	                    sign = 1;
	                    segno = false;
	                    s = "";
	                }
	                if( rect[i].equals("-") ) sign = -1;

	                segno = true;

	            }
	            else if( rect[i].equals("/") ){

	                n1 = Integer.parseInt(s);
	                n = n1 / virgola;

	                virgola = 1;
	                doub = false;

	                s = "";
	                raz = true;
	            }
	            else {
	                //caso in cui ci sia un x o y al denominatore
	                if( ( rect[i].equals("x") || rect[i].equals("y") ) && raz == true )
	                     throw new input_error();

	                if( rect[i].equals("x") || rect[i].equals("y") ){
	                    if( s.length() == 0) s="1";

	                    n1 = Integer.parseInt(s);
	                    x = n1 / virgola;

	                    virgola = 1;
	                    doub = false;
	                    if((b.getnum() != 0 || c.getnum() != 0) && segno == false) throw new input_error();

	                    if(rect[i].equals("x"))
	                    	a = new razionale(sign*x,1);
	                    else 
	                    	b = new razionale(sign*x,1);

	                    sign = 1;
	                    segno = false;
	                    s = "";
	                }
	                else{
	                    if(raz == true){
	                        //vuol dire che sono a denominatore
	                        while( !rect[i].equals("x") && !rect[i].equals("y") && !rect[i].equals("=") && !rect[i].equals("+") && !rect[i].equals("-") )
	                        {
	                            if(doub == true) virgola *= 10 ;
	                            if( rect[i].equals(".") ){
	                                doub = true;
	                            }
	                            else s = s + rect[i];
	                            i++;
	                        }

	                        n1 = Integer.parseInt(s);
	                        d = n1 / virgola;

	                        virgola = 1;
	                        doub = false;

	                        if( rect[i].equals("x") ){
	                            if((b.getnum() != 0 || c.getnum() != 0) && segno == false )  throw new input_error();
	                            a = new razionale(sign*n,d);
	                            segno = false;
	                            sign = 1;
	                        }else if( rect[i].equals("y") ){
	                            if((a.getnum() != 0 || c.getnum() != 0) && segno == false ) throw new input_error(); 
	                            b = new razionale(sign*n,d);
	                            sign = 1;
	                            segno = false;
	                        }else {
	                            if( (a.getnum() != 0 || b.getnum() != 0) && segno == false )  throw new input_error();
	                            c = new razionale(sign*n,d);
	                            sign = 1;
	                            segno = false;
	                        }

	                        //decremento cosi posso ripartire il ciclo dal segno
	                        if(rect[i].equals("-") || rect[i].equals("+")) --i;
	                        n=0;d=1;
	                        s = "";
	                        raz = false;
	                    }
	                    else{


	                        //verifico se rect[i] == numero
	                        if( rect[i].equals('.') ){
	                            doub = true;
	                        }
	                        else {
	                        	try{
			                		Integer.parseInt(rect[i]);
				                }
				                catch(java.lang.NumberFormatException nfe){
				                	throw new not_numeric();
				                }
				                if(doub == true) virgola *= 10 ;
                          		s = s + rect[i];
		                    }
	                        //inserito un input errato: carattere non riconosciuto
	                    }
	                }
	            }
	        }
	        else if( rect[i].equals('=') || i == rect.length - 1 ){
	            //termine noto ==> tn
	             if(s.length() > 0){
	                 n1 = Integer.parseInt(s);
	                 tn = n1 / virgola;

	                 virgola = 1;
	                 doub = false;

	                 if(( !(b.getnum() == 0) || !(a.getnum() == 0) ) && segno == false) throw new input_error();

	                 c = new razionale(sign*tn,1);
	                 segno = false;

	                 s = "";
	              }

	              sign = 1;
	              break;

	        }else {
	            s = "";
	            n=0;d=0;
	        }
	    }
	    if( a.getnum() == 0 && b.getnum()== 0) {
	        throw new input_error();
	    }

	}


}

