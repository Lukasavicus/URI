/* Lukasavicus 2679 */

#include <stdio.h>

int main(){
	long long int x;
	scanf("%lld", &x);
	printf("%lld\n", ((x % 2) ? (x+1) : (x+2)));
	return 0;
}