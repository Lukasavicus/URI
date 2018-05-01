//Lukasavicus 1198

#include <stdio.h>
#include <stdlib.h>

long long int diffabs(long long int a, long long int b){
	return (a > b ) ? (a - b) : (b - a);
}

int main(){
	long long int a, b, c = 0;
	while(scanf("%lld %lld", &a, &b) != EOF){
			c = diffabs(a, b);
			printf("%lld\n", c);
	}
	return 0;
}