/* Lukasavicus - 1512 */

#include <stdio.h>

int mdc(int a, int b){
	int r;

	r = a % b;

	if(r == 0)
		return b;
	else
		return mdc(b, r);
}

int mmc(int a, int b){
	int m = mdc(a,b);
	return ((b / m) * a);
}

int mmc_slow(int a, int b){
	int i;
	int limit = a * b;
	for(i = 2; i <= limit ; i++)
		if((i % a == 0) && (i % b == 0))
			return i;
		
}

int main(){

	int n, a, b, i, result = 0, min, max, m;

	while(1){
		scanf("%d %d %d", &n, &a, &b);
		if(n == 0 && a == b && n == a)
			break;

		if(a > b){
			max = a;
			min = b;
		}
		else{
			max = b;
			min = a;
		}

		m = mmc(max, min);

		//printf("mmc: %d\n", m);

		result = (n / a) + (n / b) - (n / m);
		printf("%d\n", result);

	}

	return 0;
}