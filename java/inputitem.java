import java.util.Vector;

public abstract class inputitem{
	
	public static inputitem pars_start(String b){
		String input[] = new String[b.length()];
	    input = b.split("");

	    //parsing iniziale per verifica la figura.
	    //- se ci sono n. "(" > 1 è chiaramente un poligono
	    //- se è presente una volta "(" allora è un punto
	    //- altrimenti è una retta

	    int len = input.length;
		if(input[0].equals("(")){
	        int cont = 0;
	        for (int i = 0; i < len; ++i) {
	            if(input[i].equals("(")){
	                cont++;
	            }
	        }
	        if( cont > 1 ) return new quadrato();
	        else return new punto();
	    }
	    else{
	        return new retta();
	    }
	}

	public inputitem iniz_input(String b) throws eccezioni{
		if(pars_start(b) instanceof retta){
			retta r = new retta();
			try{r.pars_rect(b);}
			catch(eccezioni e){
				System.out.println(e.message);
				throw e;
			}

			return r;
		}
		else if(pars_start(b) instanceof punto){
			punto p = new punto();

			try{p.pars_point(b);}
			catch(eccezioni e){
				System.out.println(e.message);
				throw e;
			}

			return p;
		}
		else{
			poligono p = new quadrato();
			try{p = p.pars_pol(b);}
			catch(eccezioni e){
				System.out.println(e.message);
				throw e;
			}
			return p;
		}


	}

	public abstract double distance(inputitem i) throws eccezioni;

	public abstract Vector<punto> intersect(inputitem i);

}