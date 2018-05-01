// Lukasavicus 1786

#include<stdio.h>

int main(){
	
	char cpf[10];
	int b1, b2, i, j, k;

	while(scanf("%s", &cpf) != EOF){
		for(i = 0, j = 1, k = 9, b1 = 0, b2 = 0; i < 9; i++){
			b1 += (cpf[i]-'0') * (j++);
			b2 += (cpf[i]-'0') * (k--);
		}
		b1 = b1 % 11;
		if(b1 == 10)
			b1 = 0;
		b2 = b2 % 11;
		if(b2 == 10)
			b2 = 0;

		for(i = 1, j = 0; i < 12;i++){
			if(i == 4 || i == 8)
				printf(".");
			else{
				printf("%c", cpf[j++]);
			}
		}
		printf("\nb1:%d\tb2%d\n", b1, b2);
		printf("-%d%d\n", b1, b2);

	}

	return 0;
}