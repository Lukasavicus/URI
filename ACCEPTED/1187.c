//Lukasavicus 1187

#include <stdio.h>

#define MAX 12
#define MAXL 5

main(){

	double m[MAX][MAX];
	int i = 0, j = 0;

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

	for(i = 0, sum = 0; i < MAXL; i++){
		for(j = 1+i; j <= (MAXL*2)-i; j++){
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
