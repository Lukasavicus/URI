//Lukasavicus 1983

#include<stdio.h>

main(){

	long long int n, alMax;
	int q, i;
	double num, max;
	scanf("%d", &q);
	scanf("%llu %lf", &alMax, &max);
	
	for(i = 1; i < q; i++){
		scanf("%llu %lf", &n, &num);
		if(num > max){
			max = num;
			alMax = n;
		}
	}
	//printf("%.2lf\n", max);
	if(max >= 8)
		printf("%llu\n", alMax);
	else
		printf("Minimum note not reached\n");

}
