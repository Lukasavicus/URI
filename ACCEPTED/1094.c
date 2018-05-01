// Lukasavicus 1094

#include <stdio.h>

void main(){


	int qnt;
	int i;
	int num;
	char c;

	scanf("%d", &qnt);

	int tCobaias = 0, tCoelhos = 0, tRatos = 0, tSapos = 0;
	double pCoelhos, pRatos, pSapos;

	for(i = 0; i < qnt; i++){
		scanf("%d %c", &num, &c);

		if(c == 'C')
			tCoelhos += num;
		else if(c == 'R')
			tRatos += num;
		else
			tSapos += num;

		tCobaias += num;

	}


	pCoelhos = (double)((double)tCoelhos/(double)(tCobaias*100)) * 10000;
	pRatos = (double)((double)tRatos/(double)(tCobaias*100)) * 10000;
	pSapos = (double)((double)tSapos/(double)(tCobaias*100)) * 10000;

	printf("Total: %d cobaias\nTotal de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\nPercentual de coelhos: %.2lf %%\nPercentual de ratos: %.2lf %%\nPercentual de sapos: %.2lf %%\n", tCobaias, tCoelhos, tRatos, tSapos, pCoelhos, pRatos, pSapos);

}