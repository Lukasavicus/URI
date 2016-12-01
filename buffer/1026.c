// Lukasavicus 1026

#include <stdio.h>

void main(){
	int a, b, xor;

	while(scanf("%d %d", &a, &b) != EOF){
		xor = a ^ b;
		printf("%d\n", xor);
	}
}