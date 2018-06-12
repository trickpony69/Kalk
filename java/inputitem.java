import java.util.Vector;

public abstract class inputitem{
	
	public static inputitem pars_start(String a){
		return new punto();
	}

	public static inputitem iniz_input(String a){
		return new punto();
	}

	public abstract double distance(inputitem i);

	public abstract Vector<punto> intersect(inputitem i);

	public static void main(String[] args) {
		inputitem i1 = new punto();
		inputitem i2 = new punto();

		String s = new String("(12;2)");
		String s1 = new String("(12/4.6;5)");
		punto p = (punto)i1 ;
		punto p1 = (punto)i2 ;
		p.pars_point(s);
		p1.pars_point(s1);

		System.out.println(p + " e " + p1 + " dist : " + p.distance(p1) + "\n");

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
		}
	}


}