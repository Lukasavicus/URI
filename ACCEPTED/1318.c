// Lukasavicus 1318

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n, m, aux, i, cloned;
	int *v;

	while(1){
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0)
			return 0;
		v = (int *) malloc (n * sizeof(int));
		for(i = 0; i < n; i++)
			v[i] = 0;
		for(i = 0, cloned = 0; i < m; i++){
			scanf("%d", &aux);
			aux--;
			if(v[aux] == 1)
				cloned++;
			v[aux]++;
		}
		printf("%d\n", cloned);
	}

	return 0;
}