// Lukasavicus 1079

#include <stdio.h>

main(){

	int qnt;
	int i;
	double n1, n2, n3;
	
	scanf("%d", &qnt);

	for(i = 0; i < qnt; i++){
		scanf("%lf %lf %lf", &n1, &n2, &n3);
		printf("%.1lf\n", (double)((double)((double)(n1*2)+(double)(n2*3)+(double)(n3*5))/10) );
	}

}