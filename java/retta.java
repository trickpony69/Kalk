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

	public razionale getA(){
		return a;
	}

	public razionale getB(){
		return b;
	}

	public razionale getC(){
		return c;
	}

	public String tostring(){
		return a + "x + " + b + "y + " + c ;
	}

	public double distancePuntoRetta(punto p){

		return  ( (abs( (a.multiply(p.getx())).converti() + (b.multiply(p.gety())).converti() + c.converti() ) )  /(sqrt(pow(a.converti(),2) + pow(b.converti(),2))));
	}

	public double distanceRettaRetta(retta r){
		punto x = new punto();
		razionale neg = new razionale(-1,1);
		razionale zero = new razionale();

		if(r.a.equals(0)){
	        x = new punto(zero,neg.multiply(r.c.multiply(r.b.inverso())));
	    }
	    else if(r.b.equals(0) ){
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
	    return coeffA == coeffB;
	}

	public boolean isPerpendicolari( retta r2){
		razionale neg = new razionale(-1,1);
	    if( neg.multiply((this.a.multiply(this.b.inverso()))).equals(neg.multiply(neg.multiply((r2.a.multiply(r2.b.inverso())).inverso()))) )
	        return true;
	    else return false;
	}

	public double distance(inputitem i){
		return 0;
	}

	public Vector<punto> intersect(inputitem i){
		Vector<punto> v = new Vector<punto>();
		
		return v;//i.intersect(this);
	}

}
