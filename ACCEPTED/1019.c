// Lukasavicus 1019

#include <stdio.h>

main(){

	int tempo, horas, minutos;

	scanf("%d", &tempo);

	horas = tempo / 3600;
	tempo = tempo % 3600;
	minutos = tempo / 60;
	tempo = tempo % 60;

	printf("%d:%d:%d\n", horas, minutos, tempo);

}