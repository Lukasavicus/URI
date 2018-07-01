/* Lukasavicus - 1441 */

#include<stdio.h>

int main(){
	long long int actual, biggest = 0;

	while(1){
		scanf("%lld", &actual);
		if(actual == 0)
			break;
		biggest = actual;
		while(actual != 1){
			if((actual % 2) == 0)
				actual = actual / 2;
			else
				actual = 3 * actual + 1;
			if(actual > biggest)
				biggest = actual;
		}
		printf("%lld\n", biggest);
	}

	return 0;
}