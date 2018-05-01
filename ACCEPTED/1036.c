// Lukasavicus 1036

#include <stdio.h>
#include <math.h>

main(){

	double a, b, c, delta;

	scanf("%lf %lf %lf", &a, &b, &c);

	if(a == 0){
		printf("Impossivel calcular\n");
		return;
	}
	
	if((b * b) < (4 * a *c)){
		printf("Impossivel calcular\n");
		return;
	}

	delta = sqrt((b * b) - (4 * a *c));
	
	printf("R1 = %.5lf\n", ((-b + (delta)) / (2*a)) );
	printf("R2 = %.5lf\n", ((-b - (delta)) / (2*a)) );
}