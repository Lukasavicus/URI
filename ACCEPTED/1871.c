/* Lukasavicus - 1871 */

#include <stdio.h>
#include <string.h>

typedef long long int lli;

int resp[11];
int s;

void tiraZero(lli n){
	int i = 0, aux;
	while(n != 0){
		aux = n % 10;
		//printf("aux: [%d]%d\n", i, aux);
		if(aux != 0){
			//printf("%d\n", aux);
			resp[i++] = aux;
		}
		n /= 10;
	}
	s = i;
}

int main(){
	int i = 0, max;
	lli a, b, c;

	while(1){
		scanf("%lld %lld", &a, &b);
		if(a == 0 && b == 0)
			break;
		c = a + b;
		//printf("%lld\n", c);
		tiraZero(c);
		//printf("%d\n", s);
		for(i = s-1; i >= 0; i--)
			printf("%d", resp[i]);
		printf("\n");
	}

	return 0;
}