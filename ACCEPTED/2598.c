// Lukasavicus 2598

#include <stdio.h>
#include <math.h>

int main(){
	
	int TC;
	int n, c;

	scanf("%d", &TC);

	while(TC--){
		scanf("%d %d", &n, &c);
		if(n % c == 0)
			printf("%d\n", n/c);
		else
			printf("%d\n", (n/c) + 1);
	}

	return 0;
}