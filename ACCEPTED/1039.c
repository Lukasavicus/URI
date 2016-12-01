//Lukasavicus 1039

#include <stdio.h>
#include <math.h>

main(){
	
	int r1, x1, y1;
	int r2, x2, y2;

	double diff_centre;

	while(scanf("%d", &r1) > 0){

		int n  = scanf(" %d %d %d %d %d", &x1, &y1, &r2, &x2, &y2);
		//printf("%d\n", n);

		diff_centre = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));

		if(diff_centre <= (double)(r1 - r2))
			printf("RICO\n");
		else
			printf("MORTO\n");
	}

}