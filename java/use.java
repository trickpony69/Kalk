public class use {
	public static void main(String[] args) {
				inputitem i1 = new punto();
		inputitem i2 = new punto();

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
		
	}
}