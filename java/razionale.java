import static java.lang.Math.*; //serve per pow() , abs () , ecc
 


public class razionale {
	private double num , den ;

	//--------COSTRUTTORI-------------------------------

	public razionale(double n , double d ) {
		if(d == 0) { den = 1; num = 0; }
		else{
			riduzione();
			num = n;
			den = d;
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

 	public void inverso() {
 		double temp = this.num;
 		this.num = this.den;
 		this.den = temp;
 	}
	
	//operator <<: overriding di tostring() della classe object
	public String toString() {
		return num + " / " + den ; 
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

	public void add_one(razionale r){
		this.num = this.num * r.den + this.den*r.num ;
		this.den = this.den * r.den ;
		riduzione();
	}

	public void multiply(double d) {
		this.num = this.num * d ;
		riduzione();
	}

	public void multiply(razionale r) {
		this.num = this.num * r.num ;
		this.den = this.den * r.den ;
		riduzione();
	}

	public double converti(){
		return num/den;
	}

 	/*public static void main(String[] args) {
		razionale r1 = new razionale(3,4);
		razionale r2 = new razionale(5,10);
		double d1 = 8.9 ;	
		System.out.print(r1.show());
		System.out.print(r2.show());
		r1.multiply(d1);
		System.out.print(r1.show());
		r1.inverso();
		System.out.print(r1.show());
	}*/

}

