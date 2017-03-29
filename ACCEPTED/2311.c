//Lukasavicus 2311

#include <stdio.h>
#include <stdlib.h>

void bsort(double vec[], int n){
	int i, j;
	double aux;
	for(i = 0; i < n; i++)
		for(j = i+1; j < n; j++)
			if(vec[i] > vec[j]){
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
}

int main(){

	int TC, i;
	double n[7], m, s;
	char name[51];

	scanf("%d", &TC);
	while(TC--){
		scanf("%s %lf", name, &m);

		for(i = 0; i < 7; i++)
			scanf("%lf", &n[i]);

		bsort(n, 7);

		for(i = 1, s = 0; i < 6; i++)
			s += n[i];
		
		printf("%s %.2lf\n", name, s*m);
	}
    return 0;
}