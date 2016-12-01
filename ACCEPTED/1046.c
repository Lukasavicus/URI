// Lukasavicus 1046

#include <stdio.h>

main(){

	int ini, fim, t;

	scanf("%d %d", &ini, &fim);

	t = fim > ini ?  (fim - ini) :  (24 - ini + fim);

	printf("O JOGO DUROU %d HORA(S)\n", t);

}