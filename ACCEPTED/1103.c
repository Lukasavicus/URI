// Lukasavicus 1103

#include <stdio.h>

main(){
	const int t = 24*60;
	int a, b, c, d, r;
	do{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		r = (c*60 + d) - (a*60 + b);
		if((a + b + c + d) != 0)
			r > 0 ? printf("%d\n", r) : printf("%d\n", t+r);
		else
			break;
	}while(1);
}
