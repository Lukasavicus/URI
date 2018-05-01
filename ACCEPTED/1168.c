// Lukasavicus 1168

#include <stdio.h>
#include <string.h>

long long int leds[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

long long int ledify(char *n){
	long long int r = 0;
	int i, s = strlen(n);
	for(i = 0, r = 0; i < s; i++){
		r += leds[n[i]-48];
	}
	return r;
}


main(){

	long long int n, i;
	char v[100];

	scanf("%lld", &n);

	for(i = 0; i < n; i++){
		scanf("%s", &v);
		printf("%lld leds\n", ledify(v));
	}
	
}