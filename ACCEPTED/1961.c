//Lukasavicus 1961

#include <stdio.h>

int mod(int a, int b){
	return a > b ? a - b : b - a;
}

main(){

	int n, i, p, pi, pi_1, flag = 0;

	scanf("%d %d %d", &p, &n, &pi_1);
	for(i = 1; i < n; i++){
		scanf("%d", &pi);
		if(mod(pi, pi_1)> p)
			flag = 1;
		pi_1 = pi;
	}
	
	return flag ? printf("GAME OVER\n") : printf("YOU WIN\n");
	
}
