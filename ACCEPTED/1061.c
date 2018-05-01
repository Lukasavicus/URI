// Lukasavicus 1061

#include <stdio.h>

main(){

	long int ini_d, fim_d;
	long int ini_h, ini_m, ini_s, fim_h, fim_m, fim_s;
	long int t_ini, t_fim, t;
	char desprezo[40];


	// Para capturar a palavra 'Dia'
	scanf("%s", desprezo);
	scanf("%ld", &ini_d);
	ini_d--;	// O mes nao comeca com o dia '0', e sim com o dia '1'
	scanf("%ld : %ld : %ld", &ini_h, &ini_m, &ini_s);

	// Para capturar a palavra 'Dia'
	scanf("%s", desprezo);
	scanf("%ld", &fim_d);
	fim_d--;
	scanf("%ld : %ld : %ld", &fim_h, &fim_m, &fim_s);

	t_ini = (ini_d * 24 * 3600) + (ini_h * 3600) + (ini_m * 60) + (ini_s);
	t_fim = (fim_d * 24 * 3600) + (fim_h * 3600) + (fim_m * 60) + (fim_s);

	//printf("%ld %ld\n", t_ini, t_fim);

	t = t_fim - t_ini;

	printf("%ld dia(s)\n", t / (24 * 3600));
	t = t % (24 * 3600);
	printf("%ld hora(s)\n", t / (3600));
	t = t % (3600);
	printf("%ld minuto(s)\n", t / (60));
	t = t % (60);
	printf("%ld segundo(s)\n", t);
}