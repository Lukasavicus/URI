//Lukasavicus 1010

#include <stdio.h>

typedef struct _peca{

	int cod, num;
	float valor;
}Peca;


main(){

	Peca p1, p2;

	scanf("%d %d %f", &p1.cod, &p1.num, &p1.valor);
	scanf("%d %d %f", &p2.cod, &p2.num, &p2.valor);

	printf("VALOR A PAGAR: R$ %.2f\n", (p1.num * p1.valor) + (p2.num * p2.valor));


}
