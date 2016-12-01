// Lukasavicus 1070

#include <stdio.h>

main(){

	int const max = 6;
	int start;
	int i;
	
	scanf("%d", &start);

	if(start % 2 == 0)
		start++;

	for(i = 0; i < max; i++, start +=2)
		printf("%d\n", start);

}