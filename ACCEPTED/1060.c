// Lukasavicus 1060

#include <stdio.h>

main(){

	int const max = 6;
	int i, positive = 0;
	double num;
	
	for(i = 0; i < max; i++){
		scanf("%lf", &num);
		if(num > 0)
			positive++;
	}

	printf("%d valores positivos\n", positive);

}