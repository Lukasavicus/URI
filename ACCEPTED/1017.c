// Lukasavicus 1017

#include <stdio.h>

	int const autonomia = 12;

main(){

	int vel, tempo;

	scanf("%d %d", &tempo, &vel);

	printf("%.3lf\n", (double)((double)(vel*tempo) / autonomia));

}