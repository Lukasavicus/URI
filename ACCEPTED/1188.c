//Lukasavicus 1188

#include <stdio.h>

#define MAX 12
#define MAXL 5

main(){

	double m[MAX][MAX];
	int i = 0, j = 0, k;

	double const max = 30;

	double sum = 0.0;

	char c = 'a';

	scanf("%c", &c);

	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			scanf("%lf", &m[i][j]);
		}
	}

	int aux = 0;

	for(i = 11, k = 0, sum = 0; k < MAXL; k++, i--){
		for(j = 1+k; j <= (MAXL*2)-k; j++){
			aux++;
			//printf("[%d][%d] = %.1lf\n", i, j, m[i][j]);
			sum += m[i][j];
		}
	}

	//printf("%d\n", aux);

	if(c == 'S')
		printf("%.1lf\n", sum);
	else
		printf("%.1lf\n", (double)(sum)/(double)max);
}
