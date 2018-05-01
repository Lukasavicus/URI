// Lukasavicus 1743

#include <stdio.h>

#define MAX 5

main(){

	int a[MAX];
	int b[MAX];
	int i;

	for(i = 0; i < MAX; i++)
		scanf("%d", &a[i]);

	for(i = 0; i < MAX; i++)
		scanf("%d", &b[i]);

	for(i = 0; i < MAX; i++)
		if((a[i] + b[i]) != 1)
			break;

	(i == MAX) ? printf("Y\n") : printf("N\n");

}