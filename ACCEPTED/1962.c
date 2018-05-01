//Lukasavicus 1962

#include<stdio.h>

main(){
	
	int n, i, a;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &a);
		(a < 2015) ? printf("%d D.C.\n", 2015 - a) : printf("%d A.C.\n", a - 2015 + 1);
	}
	
}
