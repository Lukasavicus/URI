//Lukasavicus 1182

#include <stdio.h>

#define MAX 12

main(){

	double m[MAX][MAX];
	int i = 0, j = 0;

	double const max = 12.00;

	double sum = 0.0;

	int col = 0;
	char c = 'a';

	scanf("%d", &col);
	scanf("\n%c", &c);

	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			scanf("%lf", &m[i][j]);
		}
	}

	for(i = 0, sum = 0.00; i < MAX; i++){
		sum += m[i][col];
	}

	if(c == 'S')
		printf("%.1lf\n", sum);
	else
		printf("%.1lf\n", (double)(sum)/(double)max);
}