// Lukasavicus 1536

#include <stdio.h>

int main(){

	int v1, m1, sg1;
	int v2, m2, sg2;
	int TC;

	scanf("%d", &TC);

	while(TC--){
		scanf("%d x %d\n%d x %d\n", &m1, &v2, &m2, &v1);
		sg1 = m1 + v1;
		sg2 = m2 + v2;
		//printf("%d %d\n", sg1, sg2);
		if(sg1 > sg2)		printf("Time 1\n");
		else if(sg1 < sg2)	printf("Time 2\n");
		else{
			if(v1 > v2)			printf("Time 1\n");
			else if(v1 < v2)	printf("Time 2\n");
			else				printf("Penaltis\n");
		}
	}
	return 0;
}