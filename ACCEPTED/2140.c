/* Lukasavicus - 2140 */

#include <stdio.h>

int maiorNota(int n){
	if(n >= 100)
		return 100;
	else if(n >= 50)
		return 50;
	else if(n >= 20)
		return 20;
	else if(n >= 10)
		return 10;
	else if(n >= 5)
		return 5;
	else if(n >= 2)
		return 2;
	else
		return 0;
}

int main(){

	int n, m, c, r, aux;

	while(1){
		scanf("%d %d", &n, &m);
		if(n == 0 && m ==0)
			break;

		c = m - n;
		r = maiorNota(c);
		if(r == 0)
			printf("impossible\n");
		else{
			c -= r;
			if(c == 0)
				printf("impossible\n");
			else{
				r = maiorNota(c);
				if(r == 0)
					printf("impossible\n");
				else{
					c -= r;
					if(c == 0)
						printf("possible\n");
					else{
						printf("impossible\n");
					}
				}
			}
		}			

	}

	return 0;
}