// Lukasavicus 1893

#include <stdio.h>

main(){
	int a, b;

	scanf("%d %d", &a, &b);

	if(b >= 0 && b <= 2){
		printf("nova\n");
	}
	else if (b >= 97 && b <= 100){
		printf("cheia\n");
	}
	else if (a >= 3 && a <= 96 || b >= 3 && b <= 96){
		if(b > a)
			printf("crescente\n");
		else
			printf("minguante\n");
	}
}