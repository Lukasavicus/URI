//Lukasavicus 1164

#include <stdio.h>

main(){
	int q, n, i, sum = 0, j, TAM;

	scanf("%d", &q);

	for(i = 0; i < q; i++){
		scanf("%d", &n);
		TAM = n/2;

		for(j = 1, sum = 0; j <= TAM; j++){
			if(n % j == 0)
				sum += j;
		}

	if(sum == n)
		printf("%d eh perfeito\n", n);
	else
		printf("%d nao eh perfeito\n", n);
	}
}