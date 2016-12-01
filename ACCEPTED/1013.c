//Lukasavicus 1013

#include <stdio.h>
#include <stdlib.h>

main(){

	int a, b, c, aux1, aux2, intermed;

	scanf("%d %d %d", &a, &b, &c);

	aux1 = (a + b + (a > b ? a - b : b - a))/2;
	aux2 = (c + aux1 + (c > aux1 ? c - aux1 : aux1 - c))/2;

	printf("%d eh o maior\n", aux2);


}
