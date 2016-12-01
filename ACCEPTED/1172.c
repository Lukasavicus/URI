//Lukasavicus 1172

#include <stdio.h>

#define MAX 10

main(){
	int v[MAX], i;


	for(i= 0; i < MAX; i++)
		scanf("%d", &v[i]);

	for(i= 0; i < MAX; i++)
		if(v[i] <= 0)
			v[i] = 1;

	for(i= 0; i < MAX; i++)
		printf("X[%d] = %d\n", i, v[i]);
}