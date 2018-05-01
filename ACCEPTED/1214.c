// Lukasavicus 1214

#include <stdio.h>

int main(){
	
	int TC, n, i;
	int v[1000];
	double sum, up_mean;

	scanf("%d", &TC);

	while(TC--){
		scanf("%d", &n);
		for(i = 0, sum = 0; i < n; i++){
			scanf("%d", &v[i]);
			sum += v[i];
		}
		for (i = 0, up_mean = 0; i < n; ++i){
			if(v[i] > (sum/n))
				up_mean++;
		}
		printf("%.3f%%\n", ((up_mean/n)*100));
	}

	return 0;
}