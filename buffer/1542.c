// Lukasavicus 1542

#include <stdio.h>

int mdc(int a, int b){
	if(!b)
		return a;
	return mdc(b, (a % b));
}

int mmc(int a, int b){
	return ((a / mdc(a, b)) * b);
}

int abs_diff_mdc_div(int a, int b){
	int mdc_ab = mdc(a,b);
	int aux_a = a / mdc_ab;
	int aux_b = b / mdc_ab;

	return (aux_a > aux_b) ? (aux_a - aux_b) : (aux_b - aux_a);
}

int main(){
	
	int a, b, c, d, e, aux;

	while(1){
		scanf("%d", &a);
		if(!a)
			return 0;
		scanf("%d %d", &b, &c);

		//ordena
		if(c > a){
			aux = a;
			a = c;
			c = aux;
		}		

		aux = abs_diff_mdc_div(a, c);

		d = b / abs_diff_mdc_div(a, c);
		e = d * mmc(a, c);

		printf("%d paginas\n", e);
	}

	return 0;
}