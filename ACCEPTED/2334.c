//Lukasavicus 2334

#include <stdio.h>

typedef unsigned long long int ulli;

int main(){

	ulli n, result = 0;
	const ulli n_1 = 1;

	while(1){
		scanf("%llu", &n);
		if(n == -1)
			break;
		else if(n == 0)
			result = 0;
		else
			result = (n - n_1);

		printf("%llu\n", result);
	}
    return 0;
}