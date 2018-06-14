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

	public static inputitem iniz_input(String b) throws eccezioni{
		if(pars_start(b) instanceof retta){
			retta r = new retta();
			try{r.pars_rect(b);}
			catch(eccezioni e){
				System.out.println(e.message);
				throw new input_error();
			}

			return r;
		}
		else if(pars_start(b) instanceof punto){
			punto p = new punto();

			try{p.pars_point(b);}
			catch(eccezioni e){
				System.out.println(e.message);
				throw new input_error();
			}

			return p;
		}
		else{
			poligono p = new quadrato();
			try{p.pars_pol(b);}
			catch(eccezioni e){
				System.out.println(e.message);
				throw new input_error();
			}

			return p;
		}
	}

	public abstract double distance(inputitem i) throws eccezioni;

	public abstract Vector<punto> intersect(inputitem i);

	public static void main(String[] args) {
		inputitem i1 = new punto();
		inputitem i2 = new punto();

		/*String s = new String("(12;2)");
		String s1 = new String("(12/4.6;5)");
		punto p = (punto)i1 ;
		punto p1 = (punto)i2 ;
		p.pars_point(s);
		p1.pars_point(s1);

		Vector<punto> v = new Vector<punto>();
		v = p.intersect(p1);
		if(v.size() == 0) System.out.println("non si intersecano \n");
		else System.out.println("si intersecano \n");

		String ret1 = new String("2x+6y+7");
		String ret2 = new String("5x+3y-29");
		retta r1 = new retta();
		r1.pars_rect(ret1);
		retta r2 = new retta();
		r2.pars_rect(ret2);

		System.out.println(r1 +"\n");
		System.out.println(r2 +"\n");

		System.out.println("distanza : " + r1.distance(r2));

		System.out.println("perp : " + r1.rettaperpendicolare(p));
		System.out.println("parall : " + r1.rettaparallela(p));

		Vector<punto> v1 = r1.intersect(r2);

		if(v1.size() == 0) System.out.println("non si intersecano \n");
		else {
			for (Object o : v1) {
			    System.out.print("intersezione: " + o );
			}	
		}*/

		String polprova = new String("(3;0)(0;1)(0;0)");
		String polprova2 = new String("(0;2)(2;0)(1;2)");

		boolean reinserisci1 = false;
		poligono pol1 = new triangolo();
		poligono pol2 = new triangolo();

		try{pol1 = pol1.pars_pol(polprova);}
		catch(eccezioni i){
			reinserisci1 = true;
			System.out.println(i.message);
		}

		if(reinserisci1 == false)
			System.out.println("\npol1 : " + pol1);

		boolean reinserisci2 = false;

		try{pol2 = pol2.pars_pol(polprova2);}
		catch(eccezioni i){
			reinserisci2 = true;
			System.out.println(i.message);
		}

		if(reinserisci2 == false)
			System.out.println("\npol2 : " + pol2);

		if(reinserisci1 == false && reinserisci2 == false){
			Vector<punto> temp = pol1.polipoli(pol2);
			if(temp.size() == 0) System.out.println("non si intersecano \n");
			else {
				System.out.print("\npolipoli: ");
				for (Object o : temp) {
				    System.out.print("\n" + o );
				}	
			}


		}

		String ret1 = new String("2x+6y-6");
		retta r1 = new retta();
		try{r1.pars_rect(ret1);}
		catch(eccezioni i){
			reinserisci1 = true;
			System.out.println(i.message);
		}
		System.out.println("\n\nret:\n" + r1 +"\n");
		Vector<punto> t = new Vector<punto>();
		Vector<punto> intersez = pol2.rettapol(r1,t);
		if(intersez.size() == 0) System.out.println("non si intersecano \n");
		else {
			System.out.print("\nrettapol: ");
			for (Object o : intersez) {
			    System.out.print("\n" + o );
			}	
		}




		String punto1 = new String("(1;1.5)");
		punto p1 = new punto();
		try{p1.pars_point(punto1);}
		catch(eccezioni i){
			reinserisci1 = true;
			System.out.println(i.message);
		}

		try{System.out.print("\ndist"+pol2.distancepuntopol(p1));}
		catch(eccezioni i){
			reinserisci1 = true;
			System.out.println(i.message);
		}
		


		//copia

		/*
		Vector<punto> temp = pol1.getpoint();
		triangolo t = new triangolo(3,temp);
		System.out.println("\npol 1 : " + t);
		*/


	}


}