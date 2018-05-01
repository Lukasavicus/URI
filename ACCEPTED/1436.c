// Lukasavicus 1436

#include <stdio.h>
#include <stdlib.h>

#define MAX 11

int compare(const void * a, const void * b){
	return *(int *)a - *(int *)b;
}

void main(){
	int i, j, n;

	int v1[MAX], qnt1;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d", &qnt1);
		for(j = 0; j < qnt1; j++){
			scanf("%d", &v1[j]);
		}
		//qsort(v1, qnt1, sizeof(int), compare);
		printf("Case %d: %d\n", i+1, v1[qnt1/2]);
	}

}