// Lukasavicus 1769

#include<stdio.h>

int main(){
	
	char cpf[15];
	int b1, b2, i, j, k;

	while(scanf("%s", &cpf) != EOF){
		for(i = 0, j = 1, k = 9, b1 = 0, b2 = 0; i < 11; i++){
			if((i != 3) && (i != 7)){
				b1 += (cpf[i]-'0') * (j++);
				b2 += (cpf[i]-'0') * (k--);
			}
		}
		b1 = b1 % 11;
		if(b1 == 10)
			b1 = 0;
		b2 = b2 % 11;
		if(b2 == 10)
			b2 = 0;
		if( ((cpf[12]-'0') == b1) && ((cpf[13]-'0') == b2))
			printf("CPF valido\n");
		else
			printf("CPF invalido\n");
	}

	return 0;
}