// Lukasavicus 1716

 #include <stdio.h>
 #include <math.h>


long long int findFirstPrimeComponent(n){

	long long int l = pow(n, 0.5)+1;
	long long int i;

	for(i = 3; i < l; i+=2){
		if(n % i == 0)
			return i;
	}

	return -1;
}

long long int eea(long long int a, long long int b){

	long long int 	s = 0,
					s_old = 1,
					q = 0, // quocient
				  	r = 1, // Remainder
				  	aux,   // auxiliar
				  	mod = b; // mod

	
	// invert if a greater than b
  	if(a > b){
		aux = a;
		a = b;
		b = aux;	
	}
	

  	do{

  		q = a / b;
  		// ==================
  		r = a % b;
  		a = b;
  		b = r;
  		// ==================

  		aux = s;
  		s = s_old - q * s;
  		s_old = aux;

  	}while(r != 0);

  	//printf("%lld ",a);
  	if(a == 1){
  		if(s_old < 0){
  			s_old += mod;
  		}

  		return s_old;
  	}
  	else{
  		return -1;
  	}
}

int binary[32];

int d2b(long long int n){
	if(n == 0){
		return 0;
	}

	int r;

	r = d2b(n/2);
	binary[r++] = n % 2;
	return r;
}

long long int sm(long long int base, long long int exp,  long long int mod){

	int i, s = d2b(exp);

	long long int x = base;

	int t = 1;

	//printf("%d\n", s);
	for(i = 1; i < s; i++){
		//printf("%d ", binary[i]);
		t *= 2;
		x = ((x * x) % mod);
		if(binary[i]){
			x = ((x * base) % mod);
			t++;
		}
		//printf("t: %d\n", t);
	}	
	//printf("t: %d\n", t);
	return x;
}

int main(){

 	long long int n, e, c;
 	long long int phi = 0;
 	long long int p, q;
 	long long int d;
 	long long int m;

 	scanf("%lld %lld %lld",&n ,&e ,&c );

 	p = findFirstPrimeComponent(n);
 	q = n / p;

 	phi = (p-1)*(q-1);

 	d = eea(e, phi);

 	m = sm(c,d,n);

 	//printf("%lld %lld %lld %lld\n", p, q, phi, d);
 	printf("%lld\n", m);

 	return 0;

 }