/* Lukasavicus - 2166 */

#include <stdio.h>
#include <string.h>

double fracao_periodica_aproximada(int base, int denominador, int precisao){
	if(precisao == 0){
		return 0;
	}
	else if(precisao == 1){
		return 1 / (double)(denominador);
	}
	else{
		return 1 / (double)((double)(denominador) + fracao_periodica_aproximada(base, denominador, precisao-1));
	}
}

int main(){

	int t;
	double r;

	scanf("%d", &t);

	r = fracao_periodica_aproximada(1, 2, t);

	printf("%.10lf\n", 1+r);

	return 0;
}