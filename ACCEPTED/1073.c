// Lukasavicus 1073

#include <stdio.h>

main(){

	int i, qnt;
	
	scanf("%d", &qnt);

	for(i = 2; i <= qnt; i+= 2)
		printf("%d^2 = %ld\n",i, (long int)(i * i));

}