//Lukasavicus 1802

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct _books{

	int v[10];
	int n;
	int top;

}Books;

int compare(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

main(){

	Books b[MAX];
	int i,j, num;

	int sum = 0, partialsum = 0;

	for(i = 0; i < MAX; i++){
		b[i].top = 0;
		scanf("%d", &b[i].n);
		for(j = 0; j < b[i].n; j++){
			scanf("%d", &b[i].v[j]);
		}
		qsort(b[i].v, b[i].n, sizeof(int), compare);
	}

	/*

	for(i = 0; i < MAX; i++){
		b[i].top = 0;
		printf("%d\n", b[i].n);
		for(j = 0; j < b[i].n; j++){
			printf("%d ", b[i].v[j]);
		}
		qsort(b[i].v, b[i].n, sizeof(int), compare);
	}

	*/

	scanf("%d", &num);

	int idx, v;

	for(i = 0; i < num; i++){
		v = 999;
		idx = -1;
		for(j = 0; j < MAX; j++){
			sum += b[j].v[b[j].top];
			//printf("%d %d\n", v, b[j].v[b[j].top]);
			if(b[j].top < b[j].n && b[j].v[b[j].top] < v){
				v = b[j].v[b[j].top];
				idx = j;
			}
			printf(">>%d %d\n", b[j].v[b[j].top], b[j].top);
		}
		printf(">%d\n", idx);
		if(b[j].top < b[j].n-1)
			b[idx].top++;
	}

	printf("%d\n", sum);

}