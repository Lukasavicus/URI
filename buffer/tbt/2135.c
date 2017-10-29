/* Lukasavicus 2135 */

#include <stdio.h>

int main(){
	int n, sum, f, aux, i = 0;
	while(scanf("%d", &n) != EOF){
		sum = 0;
		f = 1;
		while(n--){
			scanf("%d", &aux);
			if(f && sum == aux)
				f = 0;
			else if(f)
				sum += aux;
		}
		printf("Instancia %d\n", ++i);
		if (f)
			printf ("nao achei!\n");
		else
			printf ("%d\n", sum);
	}

	return 0;
}