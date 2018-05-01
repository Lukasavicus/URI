// Lukasavicus 1065

#include <stdio.h>

main(){

	int const max = 5;
	int i, pair = 0;
	int num;
	
	for(i = 0; i < max; i++){
		scanf("%d", &num);
		if(num % 2 == 0)
			pair++;
	}

	printf("%d valores pares\n", pair);

}