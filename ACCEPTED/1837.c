//Lukasavicus 1837

#include<stdio.h>

main(){
	
	int a , b, i = 0, it = 0;
	scanf("%d %d", &a, &b);
	
	
	if(a > 0)
		printf("%d %d\n", (a/b), (a%b));
	else{
		if(b > 0)
			it = -1;
		else
			it = 1;
		while(i*b > a){
			i += it;
		}
		printf("%d %d\n", i, (a - i*b) );
	}
}
