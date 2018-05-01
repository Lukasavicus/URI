// Lukasavicus 2149

#include <stdio.h>

int seq(int n){
	if(n == 1)
		return 0;
	if(n == 2)
		return 1;
	if(n == 3)
		return 1;

	if(n % 2 != 0){
		return seq(n-1)+seq(n-2);
	}
	else{
		return seq(n-2)+seq(n-3);
	}

}

void main(){
	printf("%d %d %d\n", seq(1), seq(4), seq(10));
	//int n;
	//while(scanf("%d", &n) !!= EOF)
	//	printf("%d\n", seq(n));
}

/*
 * 	[0] [1] [2] [3] [4] [5] [6] [7] [8]
 * 	[0] [1] [1] [1] [2] [2] [4] [8] [12]
 * 	[0] [1] [1] [2] [3] [5] [8] [13] [21]
 */