// Lukasavicus 1066

#include <stdio.h>

main(){

	int const max = 5;
	int i, positive = 0, negative = 0, pair = 0, npair = 0;
	int num;
	
	for(i = 0; i < max; i++){
		scanf("%d", &num);

		if(num > 0)
			positive++;

		if(num < 0)
			negative++;

		if(num % 2 == 0)
			pair++;
		else
			npair++;
	}

	printf("%d valor(es) par(es)\n%d valor(es) impar(es)\n%d valor(es) positivo(s)\n%d valor(es) negativo(s)\n", pair, npair, positive, negative);

}