// Lukasavicus 1170

#include <stdio.h>

int log2int(double n){
	int i = 0;
	do{
		i++;
		n /= 2;
	}while(n > 1);
	return i;
}

void main(){
	int n, i;
	double qnt;
	int res;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%lf", &qnt);
		res = log2int(qnt);
		printf("%d dias\n", res);
	}

}