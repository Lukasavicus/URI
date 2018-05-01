// Lukasavicus 1047

#include <stdio.h>

main(){

	int const minADay = 24 * 60;
	int ini_h, fim_h, ini_m, fim_m, t_ini, t_fim, t;

	scanf("%d %d %d %d", &ini_h, &ini_m, &fim_h, &fim_m);

	t_ini = ini_h * 60 + ini_m;
	t_fim = fim_h * 60 + fim_m;


	//printf("%d %d", t_ini, t_fim);

	t = t_fim > t_ini ?  (t_fim - t_ini) :  (minADay - t_ini + t_fim);

	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", (t / 60), (t % 60));

}