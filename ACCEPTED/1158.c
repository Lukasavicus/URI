//Lukasavicus 1158

#include <stdio.h>

main(){
	
	int n, base, qnt, i, sum = 0, j;

	scanf("%d", &n);

	for(i = 0; i < n; i++, sum = 0){

		scanf("%d %d", &base, &qnt);

		if(base % 2 == 0)
			base++;

		for(j = 0; j < qnt; j++, base+= 2)
			sum += base;

		printf("%d\n", sum);
	}

}