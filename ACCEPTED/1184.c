//Lukasavicus 1184

#include <stdio.h>

#define MAX 12

main(){

	double m[MAX][MAX];
	int i = 0, j = 0;

	double const max = (((12.00 * 12.00) - 12.00) / 2);

	double sum = 0.0;

	char c = 'a';

	scanf("%c", &c);

	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			scanf("%lf", &m[i][j]);
		}
	}

	for(i = 1, sum = 0.00; i < MAX; i++){
		for(j = 0; j < i; j++){ 
			//printf("%d %d - ", i, j);
			sum += m[i][j];
		}
	}

	if(c == 'S')
		printf("%.1lf\n", sum);
	else
		printf("%.1lf\n", (double)(sum)/(double)max);
}