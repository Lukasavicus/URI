// Lukasavicus 1048

#include <stdio.h>

main(){

	double salario;
	int perc;
	
	scanf("%lf", &salario);

	if(salario >= 0 && salario <= 400)
		perc = 15;
	else if(salario > 400 && salario <= 800)
		perc = 12;
	else if(salario > 800 && salario <= 1200)
		perc = 10;
	else if(salario > 1200 && salario <= 2000)
		perc = 7;
	else
		perc = 4;

	printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %%\n", (double)(salario + (double)(salario * perc / 100)), (double)(salario * perc / 100), perc);

}