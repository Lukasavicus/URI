// Lukasavicus 2663

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	return (*((int *)a)) - (*((int *)b));
}

int main(){
	int v[1123];

	int n, k, i;

	scanf("%d %d", &n, &k);

	for(i = 0; i < n; i++)
		scanf("%d", &v[i]);

	qsort(v,n,sizeof(int),compare);	

	i = k-1;
	while((i < n) && v[i] == v[i+1])
		i++;

	printf("%d\n", i+1);
	return 0;
}