/* Lukasavicus 2170*/

#include <stdio.h>

int main(){

	long double n, m;
	const long double c = 100;
	int i = 0;

	while(scanf("%Lf %Lf", &n, &m) != EOF)
		printf("Projeto %d:\nPercentual dos juros da aplicacao\n%.2Lf %%\n", ++i, ((m-n)/(n*c)));

	return 0;
}