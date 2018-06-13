import java.util.Vector;

public class triangolo extends poligono{
	private static double numeroFisso;

	public triangolo(int i , Vector<punto> p){
		super(i,p);
	}

	public triangolo() {
		super(0);	
	}

	public double getfisso(){
		return numeroFisso;
	}

	public double perimetro(){
		return (pt.get(0)).distancefromtwopoints(pt.get(1)) + (pt.get(1)).distancefromtwopoints(pt.get(2)) + (pt.get(0)).distancefromtwopoints(pt.get(2));
	}

	public double area(){
		double base = (pt.get(0)).distancefromtwopoints(pt.get(1)) ;
		double h = ((pt.get(0)).rettafromtwopoints(pt.get(1))).distancePuntoRetta(pt.get(2));
		return (base*h)/2;
	}

	public double lato(){
		double a = ((pt.get(1)).distancefromtwopoints(pt.get(2)));
		double b = ((pt.get(0)).distancefromtwopoints(pt.get(2)));
		double c = ((pt.get(0)).distancefromtwopoints(pt.get(1)));

	    if(a == b ){
	    	if(a == c)
	        	return (pt.get(1)).distancefromtwopoints(pt.get(2));
	    }
	    return 0; //non regolare
	}


}