// Lukasavicus 1097

#include <stdio.h>

main(){

	int i, j, k;

	for(i = 1, j = 7, k = j; i <= 9 && j >= 5; j--){
		printf("I=%d J=%d\n", i, j);	
		if(j == (k-2)){
			j = k+2+1;
			i+= 2;
			k+= 2;
		}
	}
	

}