// Lukasavicus 1026

#include <stdio.h>

void main(){
	unsigned long long int a, b, xor;

	while(scanf("%lld %lld", &a, &b) != EOF){
		xor = a ^ b;
		printf("%lld\n", xor);
	}
}
