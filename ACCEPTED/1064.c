// Lukasavicus 1064

#include <stdio.h>

main(){

	int const max = 6;
	int i, positive = 0;
	double num;
	double sum = 0;
	
	for(i = 0; i < max; i++){
		scanf("%lf", &num);
		if(num > 0){
			positive++;
			sum += num;
		}
	}

	printf("%d valores positivos\n%.1lf\n", positive, (double)(sum/positive));

}