//Lukasavicus 1865

#include <stdio.h>
#include <string.h>

main(){

	int n, i, c;
	char name[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s %d", name, &c);	
		if(strcmp(name, "Thor") == 0)
			printf("Y\n");
		else
			printf("N\n");
	}
	
}
