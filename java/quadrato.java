import java.util.Vector;

public class quadrato extends poligono{
	private static double numeroFisso;

	public quadrato(int i , Vector<punto> p){
		super(i,p);
	}

	public quadrato() {
		super(0);		
	}

	public double getfisso(){
		return numeroFisso;
	}

	public double distance(inputitem i){
		return 0;
	}

	public Vector<punto> intersect(inputitem i){
		Vector<punto> temp = new Vector<punto>();
		return temp;
	} 

	/*public area(){
		return lato()*lato();
	}*/

}