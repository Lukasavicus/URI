// Lukasavicus 1080

#include <stdio.h>

main(){

	int const qnt = 100;
	int i;
	int num;
	int maior = -1, pos = -1;

	for(i = 1; i <= qnt; i++){
		scanf("%d", &num);
		if(num > maior){
			maior = num;
			pos = i;
		}
	}
	printf("%d\n%d\n", maior, pos);

}