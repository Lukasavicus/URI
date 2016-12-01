//Lukasavicus 1984

#include<stdio.h>

main(){

	long long int n;	
	scanf("%llu", &n);
	
	while(n != 0){
		printf("%d", (n%10));
		n /= 10;
	}
	printf("\n");

}
