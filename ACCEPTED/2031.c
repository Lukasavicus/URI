//Lukasavicus 2031

#include<stdio.h>
#include<string.h>

#define J1 "Jogador 1 venceu\n"
#define J2 "Jogador 2 venceu\n"
#define AV "Ambos venceram\n"
#define SG "Sem ganhador\n"
#define AM "Aniquilacao mutua\n"

int eval(char *str){
	if(strcmp(str, "ataque") == 0)	return 3;
	else if(strcmp(str, "pedra") == 0) return 2;
	else return 1;
}

main(){
	
	int n, i, a, b;
	char choice1[11], choice2[11];
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%s %s", choice1, choice2);
		a = eval(choice1);
		b = eval(choice2);
		if(a > b)		printf(J1);
		else if(a < b)	printf(J2);
		else if(a == 1)	printf(AV);
		else if(a == 2) printf(SG);
		else			printf(AM);
	}
	
}
