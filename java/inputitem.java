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

		String ret = new String("1/5x+3y-2/6");
		retta r = new retta();
		r.pars_rect(ret);

		System.out.println(r +"\n");
	}


}