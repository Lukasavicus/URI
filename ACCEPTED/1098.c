// Lukasavicus 1098

//(Formatar a saída dos números decimais, quando eles são inteiros)
#include <stdio.h>

main(){

	double i, j, k;
	int l;
	double const zero = 0;

	for(i = 0, j = 1,  k = 0, l = 0; i < 2.1 && j < 5.1; j++){
		//printf("\n%.1lf %d %.1lf %.1lf %d %.1lf\n\n", i, (int)(i), i - (int)(i), j, (int)(j), j - (int)(j));
		if(l % 5 == 0)
			printf("I=%.0lf J=%.0lf\n", i, j);	
		else	
			printf("I=%.1lf J=%.1lf\n", i, j);	
		k++;
		if(k == 3){
			i+=0.2;
			j+=0.2;
			j-=3;
			k = 0;
			l++;
		}
	}
	
}