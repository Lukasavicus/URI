//Lukasavicus 2167

#include <stdio.h>

int main(){

	int TC, a, b, p = 0, i, f = 0;

	scanf("%d", &TC);

	if(TC == 1){
		scanf("%d", &a);
		p = 0;
	}
	else if(TC == 2){
		scanf("%d %d", &a, &b);
		if(b < a)
			p = 2;
		else
			p = 0;
	}
	else{
		i = 2;
		scanf("%d", &a);
		while(--TC){
			scanf("%d", &b);
			if((!f) && (b < a)){
				f = 1;
				p = i;
			}
			else
				i++;
			a = b;
		}
	}

	printf("%d\n", p);

    return 0;
}