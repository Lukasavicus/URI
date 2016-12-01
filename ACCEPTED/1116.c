//Lukasavicus 1116

#include <stdio.h>

main(){

	int cont, i;
	double  n1, n2;
	
	scanf("%d", &cont);

	for(i = 0; i < cont; i++){
		scanf("%lf %lf", &n1, &n2);
		if(n2 == 0)
			printf("divisao impossivel\n");
		else
			printf("%.1lf\n", n1/n2);
	}

}
