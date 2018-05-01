//Lukasavicus 1858

#include<stdio.h>

main(){
	
	int n ,i, min, act, idx = 1;
	scanf("%d", &n);
	
	scanf("%d", &act);
	
	for(i = 2; i <= n; i++){
		scanf("%d", &min);
		if(min < act){
			act = min;
			idx = i;
		}
	}
	//printf("%d\n", act);
	printf("%d\n", idx);
	
}
