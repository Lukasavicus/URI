//Lukasavicus 1310

#include <stdio.h>

main(){

	int tam, custo, l, i = 0;
	int max = 0, atual = 0;

	while(scanf("%d", &tam) == 1){
		scanf("%d", &custo);

		atual = 0;
		max = 0;

		for(i = 0; i < tam; i++){
			scanf("%d", &l);
			atual += l - custo;

			if(atual > max)
				max = atual;

			if(atual < 0)
				atual = 0;
		}
		printf("%d\n", max);
	}
}