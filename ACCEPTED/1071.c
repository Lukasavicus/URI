// Lukasavicus 1071

#include <stdio.h>

main(){

	int n1, n2, aux;
	int i, sum = 0;
	
	scanf("%d %d", &n1, &n2);

	if(n1 > n2){
		aux = n1;
		n1 = n2;
		n2 = aux;
	}

	n1++;

	if(n1 % 2 == 0)
		n1++;

	for(i = n1; i < n2; i+= 2)
		sum += i;

	printf("%d\n", sum);

}