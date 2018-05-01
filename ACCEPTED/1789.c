//Lukasavicus 1789

#include <stdio.h>

main(){
	int times, i, bigger, actual;

	while(scanf("%d", &times) == 1){
		for(i = 0, bigger = -1, actual = -1; i < times; i++){
			scanf("%d", &actual);
			if(actual > bigger)
				bigger = actual;
		}
		//printf("%d\n", bigger);
		if(bigger < 10)
			printf("1\n");
		else if(11 <= bigger && bigger < 20)
			printf("2\n");
		else
			printf("3\n");

	}
}