// Lukasavicus 2175

#include <stdio.h>
#include <stdlib.h>

int main(){
	double o, b, i;

	scanf("%lf %lf %lf", &o, &b, &i);

	if(o == b || b == i || o == i)
		printf("Empate\n");
	else if(o < b && o < i)
		printf("Otavio\n");
	else if(i < b && i < o)
		printf("Ian\n");
	else if(b < o && b < i)
		printf("Bruno\n");

	return 0;
}