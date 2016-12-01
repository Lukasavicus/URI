// Lukasavicus 1901

#include <stdio.h>

#define MAXN 200

int founded[2*MAXN];
int qnt_diff = 0;

int present(int f){
	int i;
	for(i = 0; i < qnt_diff; i++)
		if(founded[i] == f)
			break;

	return (i != qnt_diff);
}


main(){
	int m[MAXN][MAXN];

	int n, qnt_diff = 0, i, j, pi, pj, f;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &m[i][j]);
		}
	}

	n *= 2;

	for(i = 0; i < n; i++){
		scanf("%d %d", &pi, &pj);
		f = m[pi-1][pj-1];
		if(!present(f)){
			founded[qnt_diff++] = f;
		}
	}

	printf("%d\n", qnt_diff-1);
}