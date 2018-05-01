// Lukasavicus 2003

#include <stdio.h>

int main(){
	int h, m, t;

	while(scanf("%d:%d", &h, &m) != EOF){

		t = h*60+m;

		if(t < 420)
			t = 0;
		else
			t -= 420;

		printf("Atraso maximo: %d\n", t);
	}

	return 0;
}