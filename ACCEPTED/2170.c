/* Lukasavicus 2170*/

#include <stdio.h>

int main(){

	long double n, m;
	int i = 0;

	while(scanf("%Lf %Lf", &n, &m) != EOF)
		printf("Projeto %d:\nPercentual dos juros da aplicacao: %.2Lf %%\n\n", ++i, ((m/n)-1.0)*100);

	return 0;
}