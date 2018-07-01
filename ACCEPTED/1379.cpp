/* Lukasavicus - 1379 */

#include<stdio.h>

int main(){
	long long int a, b;

	while(1){
		scanf("%lld %lld", &a, &b);
		if(a == 0 && b == 0)
			break;
		printf("%lld\n", ((a*3) - (a+b)));
	}

	return 0;
}