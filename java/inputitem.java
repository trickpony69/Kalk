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

}