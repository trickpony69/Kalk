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


	/*public area(){
		return lato()*lato();
	}*/

}