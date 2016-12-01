// Lukasavicus 1075

#include <stdio.h>

main(){

	int const qnt = 10000;
	int const divisor = 2;

	int num;
	int i;
	
	scanf("%d", &num);

	for(i = 0; i < qnt; i++)
		if(i %  num == divisor)
			printf("%d\n", i);


}