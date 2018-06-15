import static java.lang.Math.*; //serve per pow() , abs () , ecc
 


class razionale {
	private double num , den ;

	//--------COSTRUTTORI-------------------------------

	public razionale(double n , double d ) {
		if(d == 0) { den = 1; num = 0; }
		else{
			num = n;
			den = d;
			riduzione();
		}

		if((den < 0 && num > 0) || (den < 0 && num < 0)){
	        den = den*(-1);
	        num = num*(-1);
    	}
		
	}

	public razionale( ){
		this(0,1); //delegation
	}

	public razionale( double d ) {
		num = d*pow(10,conteggio(d));
		den = pow(10,conteggio(d));

		riduzione();

	    if(num<0 && den <0){
	        num=abs(num);
	        den=abs(den);
	    }
 	}

 	public razionale(razionale r1 , razionale r2){
 		num = r1.num*r2.den ; 
 		den = r2.num*r1.den ;

 		if((den < 0 && num > 0) || (den < 0 && num < 0)){
	        den = den*(-1);
	        num = num*(-1);
    	}
    	
    	riduzione();
 	}

 	public razionale(razionale r1){
 		this(r1.num,r1.den);
 	}


 	//--------------------------------------------------

 	public void riduzione(){
 		if(num==den)
        	num=den=1;
    	else if(num!=0){
	        double aux=abs(num)<abs(den)?abs(num):abs(den);

	        for(int i=2; i<=aux; i++){
	            if((num % i == 0) && (den % i == 0)){
	                num=num/i;
	                den=den/i;
	                aux=abs(num)<abs(den)?abs(num):abs(den);
	                --i;
	            }
        	}
	    }
	    else
	        den=1;
	}

	public int conteggio(double d){
	    int i=0;
	    while( (d*pow(10,i)-floor(d*pow(10,i)) != 0 ) && i<= 10)
	        i++;
	    return i;
	}
 	
 	public double getnum(){
 		return this.num;
 	}

 	public double getden(){
 		return this.den;
 	}

 	public razionale inverso() {
 		razionale tr = new razionale();
 		tr.num = this.den;
 		tr.den = this.num;
 		return tr;
 	}
	
	//tostring()  classe object
	public String toString() {

		String ret = new String() ;

		if((num % 1) == 0){
			int convnum = (int)num;
			ret = ret + convnum ; 
		}
		else{
			ret = ret + num;
		}
		

		if(den != 1){ 
			if((den % 1) == 0){
				int convden = (int)den;
				ret = ret + "/" + convden ;
			}
			else{
				ret = ret + "/" + den ;
			}
		}
		
		return ret ;
	}

	//operator == ----------------------

	public boolean equals(razionale r){
		return num*r.den ==r.num*den;
	}

	public boolean equals(double d) {
		return num/den == d;
	}

	//operator ++  -------------------------
	public void add_one(){
		this.num += this.den;
		riduzione();
	}

	public razionale add(razionale r){
		razionale n = new razionale();
		n.num = this.num * r.den + this.den*r.num ;
		n.den = this.den * r.den ;
		n.riduzione();
		return n;
	}

	public razionale multiply(double d) {
		razionale temp = new razionale();
		temp.num = this.num * d ;
		temp.den = this.den;
		temp.riduzione();
		return temp;
	}

	public razionale multiply(razionale r) {
		razionale temp = new razionale();
		temp.num = this.num * r.num ;
		temp.den = this.den * r.den ;
		temp.riduzione();
		return temp;
	}

	public double converti(){
		return num/den;
	}

	public boolean sign(){
		if( num > 0 ){
			return true;
		}
		else return false;
	}


}

