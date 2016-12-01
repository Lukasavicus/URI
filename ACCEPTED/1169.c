// Lukasvicus 1169

#include <stdio.h>
#include <math.h>

typedef long long int lli;

void main(){
	
	lli n;
	lli i;
	lli tam;
	lli res;

	scanf("%lld", &n);

	for(i = 0; i < n; i++){
		scanf("%lld", &tam);
		res = (pow(2, tam) / 12)/1000;
		printf("%lld kg\n", res);
	}
}