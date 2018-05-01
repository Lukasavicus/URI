// Lukasavicus 1096

#include <stdio.h>

main(){

	int i, j;

	for(i = 1, j = 7; i <= 9 && j >= 5; j--){
		printf("I=%d J=%d\n", i, j);	
		if(j == 5){
			j = 8;
			i+= 2;
		}
	}
	

}