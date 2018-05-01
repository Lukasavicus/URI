// Lukasavicus 1078

#include <stdio.h>

main(){

	int const qnt = 10;

	int num;
	int i;
	
	scanf("%d", &num);

	for(i = 1; i <= qnt; i++)
		printf("%d x %d = %d\n",i, num, i*num);


}