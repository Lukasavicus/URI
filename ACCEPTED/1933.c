//Lukasavicus 1933

#include<stdio.h>

main(){
	
	int a, b;
	scanf("%d %d", &a, &b);
	return (a == b || a > b) ? printf("%d\n", a) : printf("%d\n", b);
}
