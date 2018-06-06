

public class punto extends inputitem {
	private razionale x , y ;

	public punto( razionale a , razionale b ){
		x = a;
		y = b;
	}

	public punto() { }

	public razionale getx(){
		return x;
	}

	public razionale gety(){
		return y;
	}


}