// Lukasavicus 1050

#include <stdio.h>
#include <string.h>

main(){

	int ddd;
	char resp[40];
	
	scanf("%d", &ddd);

	switch(ddd){
		case 61: strcpy(resp, "Brasilia\n"); break;
		case 71: strcpy(resp, "Salvador\n"); break;
		case 11: strcpy(resp, "Sao Paulo\n"); break;
		case 21: strcpy(resp, "Rio de Janeiro\n"); break;
		case 32: strcpy(resp, "Juiz de Fora\n"); break;
		case 19: strcpy(resp, "Campinas\n"); break;
		case 27: strcpy(resp, "Vitoria\n"); break;
		case 31: strcpy(resp, "Belo Horizonte\n"); break;
		default: strcpy(resp, "DDD nao cadastrado\n"); break;
	}


	printf("%s", resp);

}