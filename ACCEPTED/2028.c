//Lukasavicus 2028

#include <stdio.h>

long long int sum(n){
	if(n == 0)
		return 1;
	else
		return n + sum(n-1);
}

main(){

	int n, i, j = 1, k;
	long long int f;

	while(scanf("%d", &n) != EOF){
		if(n == 0)
			printf("Caso %d: 1 numero\n0\n\n", j);
		else{
			f = sum(n);
			printf("Caso %d: %lld numeros\n0", j, f);
			for(i = 1; i <= n; i++){
				for(k = 0; k < i; k++)
					printf(" %d", i);
			}
			printf("\n\n");
		}
		j++;	
	}
}
