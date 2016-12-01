// Lukasavicus 1074

#include <stdio.h>

main(){

	int qnt, num;
	int i;
	
	scanf("%d", &qnt);


	for(i = 0; i < qnt; i++){
		scanf("%d", &num);
		if(num == 0){
			printf("NULL\n");
			continue;
		}

		if(num % 2 == 0)
			printf("EVEN ");
		else
			printf("ODD ");

		if(num > 0)
			printf("POSITIVE\n");
		else
			printf("NEGATIVE\n");
	}


}