//Lukasavicus 1009

#include <stdio.h>

main(){

	char nome[100];
	double base, comissao;
	double const taxa = 0.15;

	scanf("%s %lf %lf", nome, &base, &comissao);

	printf("TOTAL = R$ %.2lf\n", base + (comissao * taxa));


}
