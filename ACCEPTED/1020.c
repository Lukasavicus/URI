// Lukasavicus 1020

#include <stdio.h>

main(){

	int tempo, anos, meses;

	scanf("%d", &tempo);

	anos = tempo / 365;
	tempo = tempo % 365;
	meses = tempo / 30;
	tempo = tempo % 30;

	printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, tempo);

}