// Lukasavicus 1037

#include <stdio.h>

main(){

	double num;

	scanf("%lf", &num);


	if(25 >= num && 0 <= num)
		printf("Intervalo [0,25]\n");
	else if(50 >= num && 25 < num)
		printf("Intervalo (25,50]\n");
	else if(75 >= num && 50 < num)
		printf("Intervalo (50,75]\n");
	else if(100 >= num && 75 < num)
		printf("Intervalo (75,100]\n");
	else
		printf("Fora de intervalo\n");
}