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

		String triangolo = new String("(3/4;0)(0;1)(5;7)");
		String quadrato1 = new String("(0;2)(2;0)(2;2)(0;0)");
		String triangolo1 = new String("(0;-5)(4;-1)(0;-1)");
		String punto1 = new String("(1;1)");
		String punto2 = new String("(-3;5)");
		String retta1 = new String("3x + 6y - 3 ");
		String retta2 = new String("2x - 6y + 2 ");
		String retta3 = new String("2x - 6y + 4 ");


		boolean insert = true;
		try{
			i1 = i1.iniz_input(punto1);
			i2 = i2.iniz_input(punto2);
			i3 = i3.iniz_input(retta1);
			i4 = i4.iniz_input(retta2);
			i5 = i5.iniz_input(retta3);
			i6 = i6.iniz_input(triangolo);
			i7 = i7.iniz_input(quadrato1);
			i8 = i8.iniz_input(triangolo1);
		

			System.out.println(i1);
			System.out.println(i2);
			System.out.println(i3);
			System.out.println(i4);
			System.out.println(i5);
			System.out.println(i6);
			System.out.println(i7);
			System.out.println(i8);

			//------ INTERSEZIONE ------ \\
			System.out.println("\nINTERSEZIONI   ------------------------------------------------------");

			System.out.println("\nIntersezione tra " + i1 + " e " + i3 + " : \n");
			Vector<punto> p = i1.intersect(i3);
			if(p.size() == 0) System.out.println("Non si intersecano.");
			else System.out.println("Si intersecano.");

			System.out.println("\nIntersezione tra " + i1 + " e " + i7 + " : \n");
			p = i1.intersect(i7);
			if(p.size() == 0) System.out.println("Non si intersecano.");
			else System.out.println("Si intersecano.");

			System.out.println("\nIntersezione tra " + i1 + " e " + i8 + " : \n");
			p = i1.intersect(i8);
			if(p.size() == 0) System.out.println("Non si intersecano.");
			else System.out.println("Si intersecano.");

			System.out.println("\nIntersezione tra " + i3 + " e " + i8 + " : \n");
			p = i3.intersect(i8);
			if(p.size() == 0) System.out.println("Non si intersecano.");
			else {
				for(Object o : p){
					System.out.println(o);
				}
			}

			System.out.println("\nIntersezione tra " + i4 + " e " + i8 + " : \n");
			p = i4.intersect(i8);
			if(p.size() == 0) System.out.println("Non si intersecano.");
			else {
				for(Object o : p){
					System.out.println(o);
				}
			}

			System.out.println("\nIntersezione tra " + i4 + " e " + i3 + " : \n");
			p = i4.intersect(i3);
			if(p.size() == 0) System.out.println("Non si intersecano.");
			else {
				for(Object o : p){
					System.out.println(o);
				}
			}

			System.out.println("\nIntersezione tra " + i4 + " e " + i5 + " : \n");
			p = i4.intersect(i5);
			if(p.size() == 0) System.out.println("Non si intersecano.");
			else {
				for(Object o : p){
					System.out.println(o);
				}
			}

			System.out.println("\nIntersezione tra " + i6 + " e " + i7 + " : \n");
			p = i6.intersect(i7);
			if(p.size() == 0) System.out.println("Non si intersecano.");
			else {
				for(Object o : p){
					System.out.println(o);
				}
			}

			System.out.println("\nIntersezione tra " + i6 + " e " + i8 + " : \n");
			p = i6.intersect(i8);
			if(p.size() == 0) System.out.println("Non si intersecano.");
			else {
				for(Object o : p){
					System.out.println(o);
				}
			}

			//--------- RETTA FROM TWO POINTS ----------------\\

			System.out.println("\nRETTA PER DUE PUNTI   ----------------------------------------------");

			System.out.println("\nRetta passante per " + i1 + " e " + i2 + " : \n");
			if( (i1 instanceof punto) && (i2 instanceof punto) ){
				punto p1 = (punto)i1;
				punto p2 = (punto)i2;
				retta r = p1.rettafromtwopoints(p2);
				System.out.println("Retta : " + r );
			}
			else System.out.println("Non sono stati inseriti due punti.");
			
			//---------- DISTANZA TRA INPUT -------------\\
			System.out.println("\nDISTANZA   ------------------------------------------------------");

			//distanza punto punto
			System.out.println("\nDistanza tra "+ i1 + " e " + i2 + " = " +i1.distance(i2));

			//distanza punto retta
			System.out.println("\nDistanza tra "+ i2 + " e " + i3 + " = " +i2.distance(i3));

			//distanza punto poligono
			System.out.println("\nDistanza tra "+ i2 + " e " + i6 + " = " +i2.distance(i6));

			//distanza retta poligono
			System.out.println("\nDistanza tra "+ i3 + " e " + i6 + " = " +i3.distance(i6));

			//distanza poligono poligono
			System.out.println("\nDistanza tra "+ i7 + " e " + i8 + " = " +i7.distance(i8));	

			//--------------------AREA PERIMETRO---------------------------\\
			System.out.println("\nAREA  PERIMETRO------------------------------------------------------");
			if(i7 instanceof poligono){
				poligono pol1 = (poligono)i7;
				System.out.println("\nPerimetro"+ i7 + " = " +pol1.perimetro());
				System.out.println("\nArea"+ i7 + " = " +pol1.area());

			}

			if(i8 instanceof poligono){
				poligono pol2 = (poligono)i8;
				System.out.println("\nPerimetro"+ i8 + " = " +pol2.perimetro());	
				System.out.println("\nArea"+ i8 + " = " +pol2.area());
			}

			//---------------------- RETTA PERPENDICOLARE A UN ALTRA E PASSANTE PER UN PUNTO ----------------\\
			System.out.println("\nRETTA PASSANTE PER UN PUNTO E PARALLELA/PERPENDICOLARE  ----------------");

			if((i1 instanceof punto) && (i3 instanceof retta)){
				punto p1 = (punto)i1;
				retta r1 = (retta)i3;
				System.out.println("\nRetta passante per "+ p1 + " e parallela a " + r1 + " = " +r1.rettaparallela(p1));
				System.out.println("\nRetta passante per "+ p1 + " e perpendicolare a " + r1 + " = " +r1.rettaperpendicolare(p1));	
			}

			if((i2 instanceof punto) && (i4 instanceof retta)){
				punto p2 = (punto)i2;
				retta r2 = (retta)i4;
				System.out.println("\nRetta passante per "+ p2 + " e parallela a " + r2 + " = " +r2.rettaparallela(p2));
				System.out.println("\nRetta passante per "+ p2 + " e perpendicolare a " + r2 + " = " +r2.rettaperpendicolare(p2));	
			}

			
		}
		catch(eccezioni i){
			System.out.println("\nErrore. ");

		}
	}
}