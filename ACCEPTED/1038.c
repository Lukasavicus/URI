// Lukasavicus 1038

#include <stdio.h>

main(){

	double valor;
	int qnt, opt;

	scanf("%d %d", &opt, &qnt);


	switch(opt){
		case 1: valor = 4; break;
		case 2: valor = 4.5; break;
		case 3: valor = 5; break;
		case 4: valor = 2; break;
		case 5: valor = 1.5; break;
	}


	printf("Total: R$ %.2f\n", valor * qnt);
}