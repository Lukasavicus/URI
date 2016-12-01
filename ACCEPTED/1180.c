//Lukasavicus 1180

#include <stdio.h>

main(){
	int val, times, i, smaller, pos, actual;

	scanf("%d", &times);
	for(i = 0, smaller = 1001, pos = -1; i < times; i++){
		scanf("%d", &actual);
		if(actual < smaller){
			smaller = actual;
			pos = i;
		}
	}
	printf("Menor valor: %d\nPosicao: %d\n", smaller, pos);
}