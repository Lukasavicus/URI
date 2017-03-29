//Lukasavicus 2222

#include <stdio.h>

void intersec(int vec_a[], int vec_b[]){
	int r = 0, i, j;

	for(i = 1; i <= vec_a[0]; i++){
		for(j = 1; j <= vec_a[0]; j++){
			if(vec_a[i] == vec_b[j])
				r++;
		}
	}
	printf("%d\n", r);
}

void uniao(int vec_a[], int vec_b[]){

}

int main(){

	int mtx[11234][61], TC, nconj, noper, oper, i, j, a, b, c;

	scanf("%d", &TC);

	while(TC--){
		scanf("%d", &nconj);
		for(i = 0; i < nconj; i++){
			scanf("%d", &mtx[i][0]);
			for(j = 1; j <= n; j++){
				scanf("%d", &mtx[i][j]);
			}
		}
		scanf("%d", &noper);
		for(i = 0; i < noper; i++){
			scanf("%d %d %d", &a, &b, &c);
			if(a == 1){
				intersec(mtx[b], mtx[c]);
			}
			else{
				uniao(mtx[b], mtx[c]);
			}
		}
	}

    return 0;
}