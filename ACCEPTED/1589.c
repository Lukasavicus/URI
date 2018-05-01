//Lukasavicus 1589

#include <stdio.h>

main(){

	int cont, r1, r2, i;
	
	scanf("%d", &cont);

	for(i = 0; i < cont; i++){
		scanf("%d %d", &r1, &r2);
		printf("%d\n", r1+r2);
	}

}
