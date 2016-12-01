// Lukasavicus 1051

#include <stdio.h>

main(){

	double renda, imposto = 0;
	
	scanf("%lf", &renda);

	if(renda > 4500){
		imposto = (renda - 4500) * 0.28;
		renda = 4500;
	}

	if(renda <= 4500 && renda > 3000){
		imposto += (renda - 3000) * 0.18;
		renda = 3000;
	}

	if(renda <= 3000 && renda > 2000){
		imposto += (renda - 2000) * 0.08;
		renda = 2000;
	}

	if(imposto == 0)
		printf("Isento\n");
	else
		printf("R$ %.2lf\n", imposto);

}