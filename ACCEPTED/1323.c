// Lukasavicus 1323

#include <stdio.h>

int sqr_sum(int n){
	return (n == 1) ? (1) : ((n*n) + sqr_sum(n-1));
}

int main(){
	
	int n;

	while(1){
		scanf("%d", &n);
		if(!n)
			break;
		n = sqr_sum(n);
		printf("%d\n", n);
	}

	return 0;
}