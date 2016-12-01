// Lukasavicus 1240

#include <stdio.h>

int encaixa(int a, int b){
	while(a > b){
		printf("%d\n", a);
		a = a % 10;
	}
	printf("%d\n", a);
	if(a == b)
		return 1;
	else
		return 0;
}

void main(){
	int i, n;
	int a, b;
	int aux;

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		aux = encaixa(a, b);
		if(aux){
			printf("encaixa\n");
		}
		else{
			printf("nao encaixa\n");
		}
	}
}