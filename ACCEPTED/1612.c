// Lukasavicus 1612

#include <stdio.h>

int main(){
	int TC, n;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &n);
		(n % 2) ? printf("%d\n", ((n/2)+1)) : printf("%d\n", (n/2));
	}
	return 0;
}