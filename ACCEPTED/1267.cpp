/* Lukasavicus - 1267 */

#include<stdio.h>

int main(){
	int flag, aux, n, d, sum, i, j;
	int mtx[500][500];

	while(1){
		scanf("%d %d", &n, &d);
		if(!n && !d)
			return 0;
		for(i = 0; i < d; i++){
			for(j = 0; j < n; j++){
				scanf("%d", &mtx[i][j]);
			}
		}
		for(i = 0, flag = 0; i < n; i++){
			for(j = 0, sum = 0; j < d; j++){
				sum += mtx[j][i];
			}
			if(sum == d)
				flag = 1;
		}
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}