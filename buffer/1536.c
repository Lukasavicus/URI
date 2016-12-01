// lukasavicus 1536

#include <stdio.h>

main(){
	int n, pm = 0, pv = 0, gm, gv, gfm gfv, i;
	int a, b, c, d;
	
	scanf("%d", &n);
	for(i = 0, pa = 0, pb = 0; i < n; i++){
		scanf("%d x %d", &a, &b);
		scanf("%d x %d", &c, &d);
		if(a > b){
			pm += 3;
		}
		else if(b > a)
			pv += 3;
		else{
			pm++;
			pv++;
		}
		gm += a + c;
		gv += b + d;
		gfm = c;
		gfv = b;
	}
	printf("%d %d\n", pa, pb);
}
