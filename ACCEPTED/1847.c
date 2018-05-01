//Lukasavicus 1847

#include<stdio.h>

int main(){
	
	int a , b, c;
	scanf("%d %d %d", &a, &b, &c);

	//printf("%d %d\n", (b-a), (c-b));

	//if ((c-b) > (b-a))	printf(":)\n");	//Solução erra em 10%
	//else					printf(":(\n");

	//if((b-a) < (c-b))		printf(":)");	//Solução erra em 10%
	//else					printf(":(");
	
	// Se a temperatura desceu do 1º para o 2º dia, mas subiu ou permaneceu constante do 2º para o 3º, as pessoas ficam felizes (primeira figura).
	if( ( a > b ) && ( b <= c ) ) printf(":)\n");

	//Se a temperatura subiu do 1º para o 2º dia, mas desceu ou permaneceu constante do 2º para o 3º, as pessoas ficam tristes (segunda figura).
	if( ( a < b ) && ( b >= c ) ) printf(":(\n");

	//Se a temperatura subiu do 1º para o 2º dia e do 2º para o 3º, mas subiu do 2º para o 3º menos do que subira do 1º para o 2º, as pessoas ficam tristes (terceira figura).
	if( ( a < b ) && ( b < c ) && ( ( b - a ) > ( c - b ) ) ) printf(":(\n");

	//Se a temperatura subiu do 1º para o 2º dia e do 2º para o 3º, mas subiu do 2º para o 3º no mínimo o tanto que subira do 1º para o 2º, as pessoas ficam felizes (quarta figura).
	if( ( a < b ) && ( b < c )  && ( ( b - a ) <= ( c - b ) ) ) printf(":)\n");

	//Se a temperatura desceu do 1º para o 2º dia e do 2º para o 3º, mas desceu do 2º para o 3º menos do que descera do 1º para o 2º, as pessoas ficam felizes (quinta figura).
	if( ( a > b ) && ( b > c ) && ( ( b - c ) < ( a - b ) ) ) printf(":)\n");

	//Se a temperatura desceu do 1º para o 2º dia e do 2º para o 3º, mas desceu do 2º para o 3º no mínimo o tanto que descera do 1º para o 2º, as pessoas ficam tristes (sexta figura).
	if( ( a > b ) && ( b > c ) && ( ( b - c ) >= ( a - b ) ) ) printf(":(\n");

	//Se a temperatura permaneceu constante do 1º para o 2º dia, as pessoas ficam felizes se subiu do 2º para o 3º dia ou tristes caso contrário (respectivamente, sétima e oitava figuras).
	if( a == b ){
		if ( b < c ) printf(":)\n");
		else  printf(":(\n");
	}
}