// Lukasavicus 1869

#include <stdio.h>

void n10to32(int n){
	int div;

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
	int n;

	while(1){
		scanf("%d", &n);
		if(n == 0)
			break;
		n10to32(n);
		printf("\n");
	}
}