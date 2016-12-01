// lukasavicus 1397

#include <stdio.h>

main(){
	int n, a, b, pa, pb, i;
	while(1){
		scanf("%d", &n);
		if(n == 0)
			break;
		for(i = 0, pa = 0, pb = 0; i < n; i++){
			scanf("%d %d", &a, &b);
			if(a > b) 
				pa++;
			else if(b > a)
				pb++;
		}
		printf("%d %d\n", pa, pb);
	}
}
