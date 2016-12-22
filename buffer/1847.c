//Lukasavicus 1847

#include <stdio.h>

int main(){
	
	int a , b, c;
	scanf("%d %d %d", &a, &b, &c);
	//printf("%d %d\n", (b-a), (c-b));
	if ((c-b) >= (b-a))
		if((c-b) == (b-a) && (a < b))
			printf(":)\n");
		else
			printf(":(\n");
	else
		printf(":(\n");
	return 0;
}
