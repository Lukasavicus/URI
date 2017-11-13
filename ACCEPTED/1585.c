// Lukasavicus 1585

#include <stdio.h>

int main(){
	
	int TC, a, b;

	scanf("%d", &TC);

	while(TC--){
		scanf("%d %d", &a, &b);
		printf("%d cm2\n", ((a*b)/2));
	}

	return 0;
}