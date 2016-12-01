//Lukasavicus 1176

#include <stdio.h>

main(){
	
	long long int fib1 = 0, fib2 = 1, aux;

	int val = 0;
	int times = 0;
	int i, j;

	scanf("%d", &times);

	for(j = 0; j < times; j++){

		scanf("%d", &val);
		if(val == 0)
			printf("Fib(0) = 0\n");
		else{
			for(i = 0, fib1 = 0, fib2 = 1, aux = 0; i < val; i++){
				aux = fib1;
				fib1 += fib2;
				fib2 = aux;
			}
			printf("Fib(%d) = %lld\n", val, fib1);
		}
	}

}