import java.util.Vector;


public class use {
	public static void main(String[] args) {

		inputitem i1 = new punto();
		inputitem i2 = new punto();

		inputitem i3 = new retta();
		inputitem i4 = new retta();
		inputitem i5 = new retta();

		inputitem i6 = new quadrato();
		inputitem i7 = new triangolo();
		inputitem i8 = new triangolo();

		String triangolo = new String("(3;0)(0;1)(5;7)");
		String quadrato1 = new String("(0;2)(2;0)(2;2)(0;0)");
		String quadrato2 = new String("(0;-5)(4;-1)(0;-1)");
		String punto1 = new String("(1;1)");
		String punto2 = new String("(-3;5)");
		String retta1 = new String("3x + 6y - 3 ");
		String retta2 = new String("2x - 6y + 2 ");
		String retta3 = new String("2x - 6y + 4 ");


		boolean insert = true;
		try{
			i1 = i1.iniz_input(punto1);
			i2 = i2.iniz_input(punto2);
			/*i3 = i1.iniz_input(retta1);
			i4 = i2.iniz_input(retta2);
			i5 = i1.iniz_input(retta3);
			i6 = i2.iniz_input(triangolo);
			i7 = i1.iniz_input(quadrato1);
			i8 = i2.iniz_input(quadrato2);*/
		}
		catch(eccezioni i){
			insert = false;
		}

		if(insert == true){
			System.out.println("Inserimento giusto.");
		}
		else System.out.println("Inserimento errato.");

/*	
		try{pol1 = pol1.pars_pol(polprova);}
		catch(eccezioni i){
			reinserisci1 = true;
			System.out.println(i.message);
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
		*/
	}
}