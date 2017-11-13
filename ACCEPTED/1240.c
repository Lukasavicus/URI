// Lukasavicus 1240

#include <stdio.h>

#define TC_LOOP int TC; \
				scanf("%d", &TC); \
				while(TC--)

void main(){
	int a, b, flag, digA, digB;

	TC_LOOP{
		scanf("%d %d", &a, &b);
		flag = 1;
		while(a && b){
			if(((a % 10) != (b % 10)) && a != 0 && b != 0){
				flag = 0;
				break;
			}
			a = a / 10;
			b = b / 10;
		}
		if(flag && (a >= b))
			printf("encaixa\n");
		else
			printf("nao encaixa\n");
	}
}