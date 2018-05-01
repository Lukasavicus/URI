//Lukasavicus 2006

#include<stdio.h>

main(){
	
	int t, i, tt, act = 0;
	scanf("%d", &tt);
	for(i = 0; i < 5; i++){
		scanf("%d", &t);
		if(t == tt)
			act++;
	}
		
	printf("%d\n", act);
}
