//Lukasavicus 1847

#include<stdio.h>

main(){
	
	int a , b, c;
	scanf("%d %d %d", &a, &b, &c);
	//printf("%d %d\n", (b-a), (c-b));
	if ((c-b) > (b-a))
		printf(":)\n");
	else
		printf(":(\n");
	
}
