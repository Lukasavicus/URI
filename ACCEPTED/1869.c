// Lukasavicus 1869

#include <stdio.h>

typedef unsigned long long int ulli;

void n10to32(ulli n){
	ulli div;

	div = n / 32;
	if(div != 0){
		n10to32(div);
	}

	int res = n % 32;

	if(res < 10){
		printf("%c", res+'0');
	}
	else{
		printf("%c", res+55);
	}
}

void main(){
	ulli n;

	while(1){
		scanf("%llu", &n);
		n10to32(n);
		printf("\n");
		if(n == 0)
			break;
	}
}