public class eccezioni extends Exception {
	public String message;
	eccezioni(String mess){
		message = mess;
	}
}

class input_error extends eccezioni{
	input_error() {
		super("\nErrore inserimento.\n");
	}
	input_error(String a){
		super(a);
	}
}

class not_numeric extends input_error{
	not_numeric(){
		super("\nE' stato inserito un valore non numerico.\n");
	}
}

class not_regular extends eccezioni{
	not_regular(){
		super("\nIl poligono inserito non è regolare.\n");
	}
	not_regular(String a){
		super(a);
	}
}

class poligonlinearexception extends not_regular{
	poligonlinearexception(){
		super("\nI punti inseriti sono nella stessa linea\n");
	}
}

class implicit extends eccezioni{
	implicit(){
		super("\nRetta non nella forma aspettata.\n");
	}
}

