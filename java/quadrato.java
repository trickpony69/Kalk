import java.util.Vector;

public class quadrato extends poligono{
	private static double numeroFisso = 0.5;

	public quadrato(int i , Vector<punto> p){
		super(i,p);
	}

	public quadrato() {
		super(0);		
	}

	public double getfisso(){
		return numeroFisso;
	}


	public double area(){
		return lato()*lato();
	}

}