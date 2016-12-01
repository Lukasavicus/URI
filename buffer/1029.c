// Lukasavicus 1029

#include <stdio.h>

int fibb(int n, int * ncalls){
	++(*ncalls);
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	return fibb(n-1, ncalls)+fibb(n-2, ncalls);

}

void main(){
	
	int ncalls = 0;
	int n, value;

	scanf("%d", &n);

	value = fibb(n, &ncalls);

	printf("%d %d\n", value, ncalls);

}