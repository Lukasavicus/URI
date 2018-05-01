//Lukasavicus 1828

#include <stdio.h>
#include <string.h>

#define BAZ "Bazinga!\n"
#define RAJ "Raj trapaceou!\n"
#define DNV "De novo!\n"

int solve(int a, int b){
	
	int r = a - b;
	int modr = r < 0 ? -r : r;
	
	if(modr > 2)
		return -r;
	else
		return r;
	
}

int enumeration(char *str){
	if(strcmp("pedra", str) == 0){
		return 1;
	}
	else if(strcmp("Spock", str) == 0){
		return 2;
	}
	else if(strcmp("papel", str) == 0){
		return 3;
	}
	else if(strcmp("lagarto", str) == 0){
		return 4;
	}
	else
		return 5;
	
}

main(){
	
	int n, i;
	char resp1[12];
	char resp2[12];
	int a, b;
	int vet[101];
	
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s %s", resp1, resp2);
		a = enumeration(resp1);
		b = enumeration(resp2);
		vet[i] = solve(a, b);
		//printf("%s %s %d %d %d\n", resp1, resp2, a, b, vet[i]);
	}
	
	
	
	for(i = 0; i < n; i++){
		printf("Caso #%d: ", i+1);
		if(vet[i] > 0)
			printf(BAZ);
		else if(vet[i] < 0)
			printf(RAJ);
		else
		printf(DNV);
	}
		
	
}
