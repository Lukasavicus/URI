//Lukasavicus  1957

#include <stdio.h>

void d2h(int n){
	
	int r;
		
	if(n == 0)
		return ;

	r = n % 16;
	n /= 16;
		
	d2h(n);
	
	(r >= 10) ? printf("%c", 65+r-10) : printf("%d", r);

}

main(){
	int n;
	
	scanf("%d", &n);
	
	d2h(n);
	printf("\n");

}
