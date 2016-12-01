// Lukasavicus 1387

#include <stdio.h>

main(){
	
	int a, b;

	do{
		scanf("%d %d", &a, &b);
		if(a != 0 && b != 0)
			printf("%d\n", a + b);
	}while(a != 0 && b != 0);
}