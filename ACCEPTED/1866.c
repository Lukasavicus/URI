//Lukasavicus 1866

#include <stdio.h>

main(){
	int q, n, i;

	scanf("%d", &q);

	for(i = 0; i < q; i++){
		scanf("%d", &n);

	if(n % 2 == 0)
		printf("0\n");
	else
		printf("1\n");
	}
}