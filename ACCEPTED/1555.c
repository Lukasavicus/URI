// Lukasavicus 1555

#include <stdio.h>

typedef long long int lli;

lli r(int x, int y){
	return ((3*x)*(3*x))+(y*y);
}

lli b(int x, int y){
	return 2*(x*x)+((5*y)*(5*y));
}

lli c(int x, int y){
	return -100*x+(y*y*y);
}

void main(){
	
	int n, i;

	int x, y;
	lli rafael, beto, carlos;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		rafael 	= r(x, y);
		beto 	= b(x, y);
		carlos 	= c(x, y);

		if(rafael > beto && rafael > carlos)	printf("Rafael ganhou\n");
		if(beto > rafael && beto > carlos)		printf("Beto ganhou\n");
		if(carlos > beto && carlos > rafael)	printf("Carlos ganhou\n");
	}
}